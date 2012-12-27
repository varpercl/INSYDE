#ifndef DOTMATRIX_H
#define DOTMATRIX_H

#include <graphicelement.h>

class DotMatrix : public GraphicElement
{
    public:
        enum DataType{
            Unipolar,
            Bipolar
        };

        explicit DotMatrix(int dotSize, int rows, int cols);

        void setDotMatrix(const QVector<QVector<int> > &matrix);
        QVector<QVector<int> > getDotMatrix() const;

        void setDotList(const QVector<int> &list);
        void setDotList(const QVector<int> &list, int rows, int cols);
        QVector<int> getDotList() const;

        void setDataType(const DataType &dt);
        DataType getDataType();

    protected:

        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
//        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    private:
        Q_OBJECT

        DataType dataType;
        int curYIndex, curXIndex;
        QVector<QPoint> ptsList;
        int cols, rows;
        int space;
        int size;
        QRectF container, mouseRect;

        void initDM(int dotSize, int rows, int cols);
};

#endif // DOTMATRIX_H
