#include "dotmatrix.h"

DotMatrix::DotMatrix(int rows, int cols, const DotMatrix::DataType &dt) :
	GraphicObject()
{
	init(5, rows, cols, dt);
}

DotMatrix::DotMatrix(int dotSize, int rows, int cols, const DotMatrix::DataType &dt) :
	GraphicObject()
{
	init(dotSize, rows, cols, dt);
}

void DotMatrix::setRows(int value)
{
	if(rows != value){
		rows = value;

		updateDotList();
		setContainerRect(getContainer());
//		update();
		if(scene()){
			scene()->update();
		}
	}
}

int DotMatrix::getRows() const
{
	return rows;
}

void DotMatrix::setCols(int value)
{
	if(cols != value){
		cols = value;

		updateDotList();
		setContainerRect(getContainer());
//		update();
		if(scene()){
			scene()->update();
		}
	}
}

int DotMatrix::getCols() const
{
	return cols;
}

void DotMatrix::setSize(const QSize &size)
{
	if(rows != size.height() || cols != size.width()){
		rows = size.height();
		cols = size.width();

		setContainerRect(getContainer());
		updateDotList();
//		update();
		if(scene()){
			scene()->update();
		}
	}
}

QSize DotMatrix::getSize() const
{
	return QSize(cols, rows);
}

void DotMatrix::setInputs(const vector<vector<int> > &matrix)
{
	setInputs(common::toQVector(matrix));
}

void DotMatrix::setInputs(const QVector<QVector<int> > &matrix)
{
	rows = matrix.size();
	cols = matrix[0].size();

	ptsList.clear();
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(matrix[i][j] > 0){
				ptsList.push_back(QPoint(i, j));
			}
		}
	}
//	update();
	if(scene()){
		scene()->update();
	}
	emit statusChanged(matrix);
}

QVector<QVector<int> > DotMatrix::getInputs() const
{
	QVector<QVector<int> > matrix(QVector<QVector<int> >(rows, QVector<int>(cols, dataType == Unipolar? 0 : -1)));

	int sPts = ptsList.size();
	for(int k = 0; k < sPts; k++){
		matrix[ptsList[k].x()][ptsList[k].y()] = 1;
	}
	return matrix;
}

void DotMatrix::setInputs(const vector<double> &inputs)
{
	GraphicObject::setInputs(inputs);
	setInputsSize(inputs.size());

	updateDotList();

	setContainerRect(getContainer());

	vector<int> intInputs(inputs.begin(), inputs.end());

//	update();
	if(scene()){
		scene()->update();
	}

	emit statusChanged(QVector<int>::fromStdVector(intInputs));
}

void DotMatrix::setInputs(const vector<double> &inputs, int rows, int cols)
{
	setRows(rows);
	setCols(cols);
	setInputs(inputs);
}

void DotMatrix::setInputs(const vector<int> &inputs)
{
	setInputs(vector<double>(inputs.begin(), inputs.end()));
}

void DotMatrix::setInputs(const vector<int> &inputs, int rows, int cols)
{
	setInputs(vector<double>(inputs.begin(), inputs.end()), rows, cols);
}

void DotMatrix::setInputs(const QVector<double> &inputs)
{
	setInputs(inputs.toStdVector());
}

void DotMatrix::setInputs(const QVector<double> &inputs, int rows, int cols)
{
	setInputs(inputs.toStdVector(), rows, cols);
}

void DotMatrix::setInputs(const QVector<int> &inputs)
{
	vector<int> intInputs = inputs.toStdVector();
	setInputs(vector<double>(intInputs.begin(), intInputs.end()));
}

void DotMatrix::setInputs(const QVector<int> &inputs, int rows, int cols)
{
	vector<int> intInputs = inputs.toStdVector();
	setInputs(vector<double>(intInputs.begin(), intInputs.end()), rows, cols);
}

void DotMatrix::setDataType(const DotMatrix::DataType &dt)
{
	dataType = dt;
}

DotMatrix::DataType DotMatrix::getDataType() const
{
	return dataType;
}

int DotMatrix::type() const
{
	return DotMatrixObject;
}

void DotMatrix::setInputElement(GraphicObject *ge)
{
	switch(ge->type()){
		case GraphicMLPElement::GraphicMLPElementType:{
			GraphicMLPElement *dm = dynamic_cast<GraphicMLPElement*>(ge);
			dm->setOutputElement(this);
			connect(dm, SIGNAL(outputChanged(QVector<double>)), SLOT(onMLPOutputChanged(QVector<double>)));
			break;
		}
		default:
			break;
	}
	inputElement = ge;
}

void DotMatrix::setWidth(int w)
{
	setCols(w);
}

int DotMatrix::getWidth() const
{
	return getCols();
}

void DotMatrix::setHeight(int h)
{
	setRows(h);
}

int DotMatrix::getHeight() const
{
	return getRows();
}

void DotMatrix::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	GraphicObject::mouseReleaseEvent(event);
	QPoint toPush = QPoint(curXIndex, curYIndex);
	if(curXIndex >= 0 &&
	   curYIndex >= 0 &&
	   mouseRect.x() != -1 &&
	   mouseRect.y() != -1)
	{
		if(enableEdit){
			if(ptsList.contains(toPush)){
				ptsList.removeAt(ptsList.indexOf(QPoint(curXIndex, curYIndex)));
			}else{
				ptsList.push_back(QPoint(curXIndex, curYIndex));
			}

			vector<double> intInputs = GraphicObject::getInputs();
			emit statusChanged(QVector<int>::fromStdVector(vector<int>(intInputs.begin(), intInputs.end())));
			QVector<QVector<int> > matrix = getInputs();
			emit statusChanged(matrix);
//			update();
			if(scene()){
				scene()->update();
			}
		}
	}
}

void DotMatrix::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
	GraphicObject::hoverMoveEvent(event);

	QRectF container = getContainer();

	curYIndex = event->pos().x() / dotSize;
	curXIndex = event->pos().y() / dotSize;

	if(event->pos().x() >= container.x() &&
	   event->pos().x() < container.x() + container.width() &&
	   event->pos().y() >= container.y() &&
	   event->pos().y() < container.y() + container.height())
	{
		mouseRect = QRectF(container.x() + curYIndex * dotSize, container.y() + curXIndex * dotSize, dotSize, dotSize);

//		update();
		if(scene()){
			scene()->update();
		}
	}else{
		mouseRect = QRectF(-1, -1, 0, 0);
	}
}

void DotMatrix::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	GraphicObject::paint(painter, option, widget);

	QRectF container = getContainer();

	painter->save();

	QPen pen;
	pen.setWidth(1);
	pen.setBrush(Qt::black);
	painter->setPen(pen);
	painter->setBrush(Qt::white);
	painter->drawRect(container);

	for(int i = 0; i < rows; i++){
		painter->drawLine(QPointF(container.x(), dotSize * (i+1)), QPointF(container.x() + container.width(), dotSize * (i+1)));
	}
	for(int j = 0; j < cols; j++){
		painter->drawLine(QPointF(dotSize * (j+1), container.y()), QPointF(dotSize * (j+1), container.y() + container.height()));
	}

	int
			sInputs = getInputsSize(),
			nDotList = (int) ptsList.size(),
			nDots = rows * cols;
	double row = 0;

	painter->save();
	for(int k = 0; k < nDots; k++){
		if(k < sInputs){
			if(k < nDotList){
				painter->setBrush(Qt::black);
				painter->drawRect(ptsList[k].y() * dotSize, ptsList[k].x() * dotSize, dotSize, dotSize);
			}
		}else{
			painter->setBrush(Qt::red);
			modf(k / cols, &row);
			painter->drawRect((k - (cols * row)) * dotSize, row * dotSize, dotSize, dotSize);
		}
	}

	if(enableEdit &&
	   (option->state & (QStyle::State_MouseOver)) &&
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

void DotMatrix::copyClick()
{

}

void DotMatrix::cutClick()
{

}

void DotMatrix::pasteClick()
{

}

void DotMatrix::saveClick()
{

}

void DotMatrix::propertyClick()
{
	DotMatrixPropertyDialog *dmepd = new DotMatrixPropertyDialog();

	dmepd->show();
}

void DotMatrix::onMLPOutputChanged(QVector<double> inputs)
{
	MultilayerPerceptron *mlp = dynamic_cast<MultilayerPerceptron*>(inputElement);
	setInputs(mlp->getOutput(vector<double>(inputs.begin(), inputs.end())));
}
bool DotMatrix::getEnableEdit() const
{
	return enableEdit;
}

void DotMatrix::setEnableEdit(bool value)
{
	enableEdit = value;
}

QString DotMatrix::getXML() const
{
	//TODO:
	return "";
}

void DotMatrix::init(int dotSize, int rows, int cols, DataType dt)
{
	this->dotSize = dotSize;
//	this->cols = cols;
//	this->rows = rows;

	saveAction->setText("Guardar como imagen...");

	setRows(rows);
	setCols(cols);

	setEnableEdit(true);
	setBorder(QPen(Qt::black, 1));
	setContainerRect(getContainer());
	setDataType(dt);
}

QRectF DotMatrix::getContainer() const
{
	return QRectF(0, 0, cols * dotSize, rows * dotSize);
}

void DotMatrix::updateDotList()
{

	if(inputs.empty()) return;

	int
			sInputs = getInputsSize(),
			nDots = rows * cols;

	double row = 0;

	ptsList.clear();
	for(int i = 0; i < nDots; i++){
		if(i >= sInputs)
			return;

		if(inputs[i] > 0){
			modf(i / cols, &row);
			ptsList.append(QPoint(row, i - (cols * row)));
		}
	}
}

bool DotMatrix::isValidDot(const QRectF &rect)
{
	double
			row = 0,
			col = 0;

	modf(rect.y() / dotSize, &row);
	modf(rect.x() / dotSize, &col);

	return ptsList.indexOf(QPoint(row, col)) >= 0 || ((row * cols) + col < (int)inputs.size());
}
