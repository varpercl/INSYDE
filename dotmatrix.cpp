#include "dotmatrix.h"

DotMatrix::DotMatrix(int dotSize, int rows, int cols)
{
    initDM(dotSize, rows, cols);

    GraphicElement::setRectangle(container.adjusted(-space, -space, space, space));
}

void DotMatrix::setDotMatrix(const QVector<QVector<int> > &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    this->rows = rows;
    this->cols = cols;

    ptsList.clear();
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matrix[i][j] > 0){
                ptsList.push_back(QPoint(i, j));
            }
        }
    }
}

QVector<QVector<int> > DotMatrix::getDotMatrix() const
{
    QVector<QVector<int> > matrix;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(dataType == Unipolar){
                matrix[i][j] = 0;
            }else if(dataType == Bipolar){
                matrix[i][j] = -1;
            }
        }
    }

    int sPts = ptsList.size();
    for(int k = 0; k < sPts; k++){
        matrix[ptsList[k].x()][ptsList[k].y()] = 1;
    }
    return matrix;
}

void DotMatrix::setDotList(const QVector<int> &list)
{
    int c = 0;
    ptsList.clear();
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(list[c++] > 0){
                ptsList.push_back(QPoint(i, j));
            }
        }
    }
}

void DotMatrix::setDotList(const QVector<int> &list, int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    int c = 0;
    ptsList.clear();
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(list[c++] > 0){
                ptsList.push_back(QPoint(i, j));
            }
        }
    }
}

QVector<int> DotMatrix::getDotList() const
{
    QVector<int> list(rows*cols);
    int c = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(ptsList.contains(QPoint(i, j))){
                list[c] = 1;
            }else{
                list[c] = (dataType == Unipolar? 0 : -1);
            }
            c++;
        }
    }
    return list;
}

void DotMatrix::setDataType(const DotMatrix::DataType &dt)
{
    dataType = dt;
}

DotMatrix::DataType DotMatrix::getDataType()
{
    return dataType;
}

void DotMatrix::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QPoint toPush = QPoint(curXIndex, curYIndex);
    if(curXIndex >= 0 && curYIndex >= 0 &&
            mouseRect.x() != -1 &&
            mouseRect.y() != -1){
        if(ptsList.contains(toPush)){
            ptsList.remove(ptsList.indexOf(QPoint(curXIndex, curYIndex)));
        }else{
            ptsList.push_back(QPoint(curXIndex, curYIndex));
        }
        update();
    }
}

void DotMatrix::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    GraphicElement::hoverMoveEvent(event);
    curYIndex = event->pos().x() / size;
    curXIndex = event->pos().y() / size;

    if(event->pos().x() >= container.x() &&
       event->pos().x() < container.x() + container.width() &&
       event->pos().y() >= container.y() &&
       event->pos().y() < container.y() + container.height()){
        mouseRect = QRectF(container.x() + curYIndex * size, container.y() + curXIndex * size, size, size);
    }else{
        mouseRect = QRectF(-1, -1, 0, 0);
    }
    update();
}

//void DotMatrix::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//{
//}

void DotMatrix::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    GraphicElement::paint(painter, option, widget);

    painter->save();

    QPen pen;
    pen.setWidth(1);
    pen.setBrush(Qt::black);
    painter->setPen(pen);
    painter->setBrush(Qt::white);
    painter->drawRect(container);

    if((option->state & (QStyle::State_MouseOver)) &&
       mouseRect.x() >= 0 && mouseRect.y() >= 0){

        painter->save();
        painter->setBrush(Qt::gray);
        painter->drawRect(mouseRect);
        painter->restore();
    }
    for(int i = 0; i < rows - 1; i++){
        painter->drawLine(QPointF(container.x(), size * (i+1)), QPointF(container.x() + container.width(), size * (i+1)));
    }
    for(int j = 0; j < cols - 1; j++){
        painter->drawLine(QPointF(size * (j+1), container.y()), QPointF(size * (j+1), container.y() + container.height()));
    }
    int sPts = ptsList.size();
    painter->save();
    for(int k = 0; k < sPts; k++){
        painter->setBrush(Qt::black);
        painter->drawRect(ptsList[k].y() * size, ptsList[k].x() * size, size, size);
    }
    painter->restore();

    painter->restore();
}

void DotMatrix::initDM(int dotSize, int rows, int cols)
{

//    setAcceptsHoverEvents(true);
//    setFlag(GraphicsItemFlag::);

    size = dotSize;
    space = 5;
    this->cols = cols;
    this->rows = rows;
    container = QRectF(0, 0, cols * dotSize, rows * dotSize);
}
