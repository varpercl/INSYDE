#include "dotmatrix.h"

core::DotMatrix::DotMatrix() :
	GraphicObject()
{
	//QVector
	ptsList = new QVector<Dot>();
	init(5, 10, 10, DotMatrix::Unipolar);
}

core::DotMatrix::DotMatrix(int rows, int cols, const DotMatrix::DataFormat &dt) :
	GraphicObject()
{
	//QVector
	ptsList = new QVector<Dot>();

	init(5, rows, cols, dt);
}

core::DotMatrix::DotMatrix(int dotsize, int rows, int cols, const DotMatrix::DataFormat &dt) :
	GraphicObject()
{
	//QVector
	ptsList = new QVector<Dot>();
	init(dotsize, rows, cols, dt);
}

core::DotMatrix::DotMatrix(QVector<Dot> *dotList, int dotsize, int rows, int cols, const DotMatrix::DataFormat &dt)
{
	//QVector
	ptsList = dotList;
	init(dotsize, rows, cols, dt);
}

void core::DotMatrix::setRows(int value)
{
	if(rows != value){
		rows = value;

		updateDotList();
		setContainerRect(getContainer());
		update();

		emit rowCountChanged(value);
	}
}

int core::DotMatrix::getRows() const
{
	return rows;
}

void core::DotMatrix::setCols(int value)
{
	if(cols != value){
		cols = value;

		updateDotList();
		setContainerRect(getContainer());
		update();

		emit colCountChanged(value);
	}
}

int core::DotMatrix::getCols() const
{
	return cols;
}

void core::DotMatrix::setMatrixSize(const QSize &size)
{
	if(rows != size.height() || cols != size.width()){
		rows = size.height();
		cols = size.width();

		setContainerRect(getContainer());
		updateDotList();

		update(getContainerRect());

		emit matrixSizeChanged(size);
	}
}

QSizeF core::DotMatrix::getSize() const
{
	return getContainerRect().size();
}

void core::DotMatrix::setInputs(const vector<vector<int> > &matrix)
{
	setInputs(common::toQVector(matrix));
}

void core::DotMatrix::setInputs(const QVector<QVector<int> > &matrix)
{
	rows = matrix.size();
	cols = matrix[0].size();

	ptsList->clear();
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(matrix[i][j] > 0){
				ptsList->push_back({i, j});
			}
		}
	}
	update();

	emit statusChanged(matrix);
}

QVector<QVector<int> > core::DotMatrix::getInputs() const
{
	QVector<QVector<int> > matrix(QVector<QVector<int> >(rows, QVector<int>(cols, dataType == Unipolar? 0 : -1)));

//	int sPts = ptsList.size();
//	for(int k = 0; k < sPts; k++){
//		matrix[ptsList[k].x()][ptsList[k].y()] = 1;
//	}
	return matrix;
}

void core::DotMatrix::setInputs(const vector<double> &inputs)
{
	GraphicObject::setInputs(inputs);
	setInputsSize((int)inputs.size());

	updateDotList();

	setContainerRect(getContainer());

	vector<int> intInputs(inputs.begin(), inputs.end());

	update();

	emit statusChanged(QVector<int>::fromStdVector(intInputs));
}

void core::DotMatrix::setInputs(const vector<double> &inputs, int rows, int cols)
{
	setRows(rows);
	setCols(cols);
	setInputs(inputs);
}

void core::DotMatrix::setInputs(const vector<int> &inputs)
{
	setInputs(vector<double>(inputs.begin(), inputs.end()));
}

void core::DotMatrix::setInputs(const vector<int> &inputs, int rows, int cols)
{
	setInputs(vector<double>(inputs.begin(), inputs.end()), rows, cols);
}

void core::DotMatrix::setInputs(const QVector<double> &inputs)
{
	setInputs(inputs.toStdVector());
}

void core::DotMatrix::setInputs(const QVector<double> &inputs, int rows, int cols)
{
	setInputs(inputs.toStdVector(), rows, cols);
}

void core::DotMatrix::setInputs(const QVector<int> &inputs)
{
	vector<int> intInputs = inputs.toStdVector();
	setInputs(vector<double>(intInputs.begin(), intInputs.end()));
}

void core::DotMatrix::setInputs(const QVector<int> &inputs, int rows, int cols)
{
	vector<int> intInputs = inputs.toStdVector();
	setInputs(vector<double>(intInputs.begin(), intInputs.end()), rows, cols);
}

void core::DotMatrix::setDataType(const DotMatrix::DataFormat &dt)
{
	dataType = dt;
}

core::DotMatrix::DataFormat core::DotMatrix::getDataType() const
{
	return dataType;
}

int core::DotMatrix::type() const
{
	return gotDotMatrix;
}

void core::DotMatrix::setInputElement(GraphicObject *ge)
{
	(void)ge;
//	switch(ge->type()){
//		case GraphicMLPElement::GraphicMLPElementType:{
//			GraphicMLPElement *dm = dynamic_cast<GraphicMLPElement*>(ge);
//			dm->setOutputElement(this);
//			connect(dm, SIGNAL(outputChanged(QVector<double>)), SLOT(onMLPOutputChanged(QVector<double>)));
//			break;
//		}
//		default:
//			break;
//	}
//	inputElement = ge;
}

void core::DotMatrix::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	GraphicObject::mousePressEvent(event);

	objectPosAtPress = pos();
}

void core::DotMatrix::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	GraphicObject::mouseReleaseEvent(event);

//	if(continuousDotWritting) return;
	//Check if object hasn't moved
	if(objectPosAtPress == pos()){
		setDot(curRowIndex, curColIndex, !enableEraser);

		update();
	}

}

void core::DotMatrix::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	GraphicObject::mouseMoveEvent(event);

	if(flags() & GraphicObject::ItemIsMovable) return;

	if(event->buttons() & Qt::LeftButton && enableContinuousDrawing){

		QPointF pointerPos = event->pos();

		updateCurRowAndColIndexes(pointerPos);

		updateMouseRectangle(pointerPos);

		setDot(curRowIndex, curColIndex, !enableEraser);

		update();
	}
}

void core::DotMatrix::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
	GraphicObject::hoverMoveEvent(event);

	QPointF pointerPos = event->pos();

	updateCurRowAndColIndexes(pointerPos);

	updateMouseRectangle(pointerPos);

	update();

}

void core::DotMatrix::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	GraphicObject::paint(painter, option, widget);

	QRectF container = getContainerRect();

	painter->save();

	QPen pen;
	pen.setWidth(1);
	pen.setBrush(Qt::black);
	painter->setPen(pen);
    painter->setBrush(Qt::white);

	for(int i = 0; i < rows; i++){
		painter->drawLine(QPointF(container.x(), size * (i+1)), QPointF(container.x() + container.width(), size * (i+1)));
	}
	for(int j = 0; j < cols; j++){
		painter->drawLine(QPointF(size * (j+1), container.y()), QPointF(size * (j+1), container.y() + container.height()));
	}

	int
			sInputs = getInputsSize(),
			nDotList = (int) ptsList->size(),
			nDots = rows * cols;

	double row = 0;

	painter->save();
	for(int k = 0; k < nDots; k++){
		if(k < sInputs){
			if(k < nDotList){
				painter->setBrush(Qt::black);
				painter->drawRect(ptsList->operator [](k).row * size, ptsList->operator [](k).col * size, size, size);
			}
		}else{
			painter->setBrush(Qt::red);
			modf(k / cols, &row);
			painter->drawRect((k - (cols * row)) * size, row * size, size, size);
		}
	}

	if(enableEdit &&
	   (option->state & QStyle::State_MouseOver) &&
	   isValidDot(mouseRect))
	{
		painter->save();
		painter->setBrush(Qt::green);
		painter->drawRect(mouseRect);
		painter->restore();
	}
	painter->restore();
	painter->restore();

}

void core::DotMatrix::copyClick()
{

}

void core::DotMatrix::cutClick()
{

}

void core::DotMatrix::pasteClick()
{

}

void core::DotMatrix::saveClick()
{

}

void core::DotMatrix::propertyClick()
{
    DotMatrixPropertyDialog *dmepd = new DotMatrixPropertyDialog(this);

	dmepd->show();
}

void core::DotMatrix::clear()
{
	ptsList->clear();
	update();
}

void core::DotMatrix::fill()
{
	ptsList->clear();
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			ptsList->push_back({j, i});
		}
	}
	ptsList->resize(getInputsSize());

	update();
}

bool core::DotMatrix::getEnableEdit() const
{
	return enableEdit;
}

void core::DotMatrix::setEnableEdit(bool value)
{
	enableEdit = value;
}

QString core::DotMatrix::getXML() const
{
	//TODO:
	return "";
}

void core::DotMatrix::setDotSize(int size)
{
	if(this->size != size){
		this->size = size;

		setContainerRect(getContainer());

		update();

		emit dotSizeChanged(size);
	}
}

int core::DotMatrix::getDotSize() const
{
	return size;
}

void core::DotMatrix::setEnableContinuousDrawing(bool b)
{
	continuousDrawingAction->blockSignals(true);
	continuousDrawingAction->setChecked(b);
	continuousDrawingAction->blockSignals(false);
	enableContinuousDrawing = b;
}

bool core::DotMatrix::getEnableContinuousDrawing() const
{
	return enableContinuousDrawing;
}

void core::DotMatrix::setEnableEraserPen(bool b)
{
	eraserAction->blockSignals(true);
	eraserAction->setChecked(b);
	eraserAction->blockSignals(false);
	enableEraser = b;
}

bool core::DotMatrix::getEnableEraserPen() const
{
	return enableEraser;
}

void core::DotMatrix::setDotList(QVector<Dot> *dots)
{
	ptsList = dots;
	update(getContainerRect());
}

QVector<core::DotMatrix::Dot> *core::DotMatrix::getDotList() const
{
	return ptsList;
}

QSize core::DotMatrix::getMatrixSize() const
{
	return QSize(rows, cols);
}

void core::DotMatrix::init(int dotSize, int rows, int cols, DataFormat dt)
{
	this->size = dotSize;

	//QActions
	continuousDrawingAction = new QAction(ICON_FREEHAND, "Dibujo continuo", this);
	clearAction = new QAction(ICON_CLEAR, "Limpiar", this);
	fillAction = new QAction(ICON_FILL, "Llenar", this);
	eraserAction = new QAction(ICON_ERASER, "Borrador", this);

	continuousDrawingAction->setCheckable(true);
	eraserAction->setCheckable(true);

	contextMenu.insertAction(getLockAction(), continuousDrawingAction);
	contextMenu.insertAction(continuousDrawingAction, fillAction);
	contextMenu.insertAction(fillAction, clearAction);
	contextMenu.insertAction(clearAction, eraserAction);

	setEnableContinuousDrawing(true);
	setEnableEraserPen(false);

	setRows(rows);
	setCols(cols);

	setEnableEdit(true);
	setBorder(QPen(Qt::black, 1));
	setContainerRect(getContainer());
	setDataType(dt);

	connect(continuousDrawingAction, SIGNAL(triggered(bool)), SLOT(setEnableContinuousDrawing(bool)));
	connect(clearAction, SIGNAL(triggered()), SLOT(clear()));
	connect(fillAction, SIGNAL(triggered()), SLOT(fill()));
	connect(eraserAction, SIGNAL(triggered(bool)), SLOT(setEnableEraserPen(bool)));
}

QRectF core::DotMatrix::getContainer() const
{
	return QRectF(0, 0, cols * size, rows * size);
}

void core::DotMatrix::updateDotList()
{

	if(inputs.empty()) return;

	int
			sInputs = getInputsSize(),
			nDots = rows * cols;

	int row;

	ptsList->clear();
	for(int i = 0; i < nDots; i++){
		if(i >= sInputs)
			return;

		if(inputs[i] > 0){
			row = i / cols;
			ptsList->append({row, i - (cols * row)});
		}
	}
}

bool core::DotMatrix::isValidDot(const QRectF &rect)
{
	if(rect.x() != -1 && rect.y() != -1){
		int
				row = 0,
				col = 0;
		row = rect.y() / size;
		col = rect.x() / size;

		return /*ptsList.indexOf(QPoint(row, col)) >= 0 ||*/ ((row * cols) + col) < getInputsSize();
	}else{
		return false;
	}
}

void core::DotMatrix::setDot(int row, int col, bool b)
{
	Dot toPush = {row, col};
	if(col >= 0 &&
	   row >= 0 &&
	   mouseRect.isValid())
	{
		if(enableEdit){
			if(b){
				if(!ptsList->contains(toPush)){
					ptsList->push_back(toPush);
				}
			}else{
				if(ptsList->contains(toPush)){
					ptsList->removeAt(ptsList->indexOf(toPush));
				}
			}

			vector<double> intInputs = GraphicObject::getInputs();
			emit statusChanged(QVector<int>::fromStdVector(vector<int>(intInputs.begin(), intInputs.end())));

			QVector<QVector<int> > matrix = getInputs();
			emit statusChanged(matrix);
		}
	}
}

void core::DotMatrix::updateMouseRectangle(const QPointF &pos)
{
	QRectF container = getContainerRect();
	if(container.contains(pos)){
		mouseRect = QRectF(container.x() + curRowIndex * size, container.y() + curColIndex * size, size, size);
	}else{
		mouseRect = QRectF(-1, -1, -1, -1);
	}
}

void core::DotMatrix::updateCurRowAndColIndexes(const QPointF &pos)
{
	int
            row = pos.x() / size,
            col = pos.y() / size;

	curRowIndex = row < rows ? row : rows - 1;
	curColIndex = col < cols ? col : cols - 1;
}

bool core::operator ==(const core::DotMatrix::Dot &dotleft, const core::DotMatrix::Dot &dotright)
{
    return dotleft.row == dotright.row && dotright.col == dotleft.col;
}
