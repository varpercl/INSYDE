#include "mlpobject.h"

ann_gui::MLPObject::MLPObject(MultilayerPerceptron *mlp)
{
	init(mlp, new TrainingSet(mlp->getInputsSize(), mlp->getOutputsSize()));
}

ann_gui::MLPObject::MLPObject(MultilayerPerceptron *mlp, TrainingSet *ts)
{
	init(mlp, ts);
}

ann_gui::MLPObject::~MLPObject()
{

}

QMenu *ann_gui::MLPObject::getContextMenu(QMenu *cntxMenu)
{
	cntxMenu->addAction("Analizar", this, SLOT(onAnalizeClick()));
	cntxMenu->addAction("Agregar al conjunto de entrenamiento", this, SLOT(onAddToTrainingSet()));
	cntxMenu->addAction("Entrenar", this, SLOT(onTrainClick()));
	cntxMenu->addAction("Borrar", this, SLOT(removeClick()));
	cntxMenu->addAction("Propiedades", this, SLOT(propertyClick()));

	return cntxMenu;
}

int ann_gui::MLPObject::type() const
{
	return gotMLP;
}

void ann_gui::MLPObject::setTrainingSet(TrainingSet *ts)
{
	this->trainingSet = ts;
}

TrainingSet* ann_gui::MLPObject::getTrainingSet() const
{
	return trainingSet;
}

void ann_gui::MLPObject::setValidationSet(TrainingSet *valSet)
{
	validationSet = valSet;
}

TrainingSet *ann_gui::MLPObject::getValidationSet() const
{
	return validationSet;
}

void ann_gui::MLPObject::setTestSet(TrainingSet *testSet)
{
	this->testSet = testSet;
}

TrainingSet *ann_gui::MLPObject::getTestSet() const
{
	return testSet;
}

void ann_gui::MLPObject::setMultilayerPerceptron(MultilayerPerceptron *mlp)
{
	this->mlp = mlp;
}

MultilayerPerceptron *ann_gui::MLPObject::getMultilayerPerceptron() const
{
	return mlp;
}

QString ann_gui::MLPObject::getXML() const
{
	//TODO:
	return "";
}


void ann_gui::MLPObject::setInputElement(GraphicObject *ge)
{
	//Determina cual es el tipo de elemento de entrada y lo conecta con los eventos correspondientes
	switch(ge->type()){
		case GraphicObject::gotDotMatrix:
			DotMatrix *dm = dynamic_cast<DotMatrix*>(ge);
			dm->setOutputElement(this);
			connect(dm, SIGNAL(statusChanged(QVector<int>)), SLOT(onDotMatrixStatusChanged(QVector<int>)));
			break;
	}
	inputElement = ge;
}

void ann_gui::MLPObject::onTrainClick()
{
	ANNTrainingDialog *mlptd = new ANNTrainingDialog(this);
	mlptd->show();
	//	mlptd->deleteLater();
}

void ann_gui::MLPObject::onAnalizeClick()
{
//	MultilayerPerceptron *mlp = getMultilayerPerceptron();
//	ImageEffect* giee = (ImageEffect*)getInputElement();

//	QImage window;

//	vector<long> wdwVector;
//	vector<vector<double> > outputs;

//	int steps = (giee->getImageWidth() / WINDOW_STEP) - WINDOW_WIDTH;
//	for(int x = 0; x < steps; x += WINDOW_STEP){
//		if(x <= giee->getImageWidth() - WINDOW_WIDTH){
//			window = giee->getImage().copy(x, 0, WINDOW_WIDTH, WINDOW_HEIGH);
//			wdwVector = common::imageToIntVector(window, common::Bipolar);
//			//		finalVector = vector<int>(wdwVector.begin(), wdwVector.end());
//			outputs.push_back(mlp->getOutput(wdwVector));
//		}else{
//			break;
//		}
//	}

//	//	for(int x = 0; x < steps; x++){
//	//		window = tmpImage.copy(x*WINDOW_STEP, 0, WINDOW_WIDTH, WINDOW_HEIGH);
//	//		wdwVector = imageToVector(window);
//	//		finalVector = vector<int>(wdwVector.begin(), wdwVector.end());
//	//		outputs.push_back(mlp->getOutput(finalVector));
//	//	}

//	int sLet = mlp->getOutputsSize();
//	//	vector<int> indexes(sLet);
//	//	double ref = -9999999;
//	double threshold = 0;

//	input->setInputMode(QInputDialog::DoubleInput);
//	input->setDoubleValue(0.65);
//	input->setIntMaximum(1);

//	if(input->exec() != QInputDialog::Accepted){
//		return;
//	}else{
//		threshold = input->doubleValue();
//	}


//	for(int x = 0; x < steps; x++){
//		for(int let = 0; let < sLet; let++){
//			if(outputs[x][let] <= threshold){
//				outputs[x][let] = 0;
//			}

//			//			if(outputs[x][let] > ref){
//			//				ref = outputs[x][let];
//			//				indexes[let] = x;
//			//			}
//		}
//	}

//	//	int sLet = mlp->getOutputSize();
//	//	vector<int> indexes(sLet);
//	double deltaRef = 9999999;
//	double delta = 0;
//	vector<int> indexes;
//	for(int let = 0; let < sLet; let++){
//		for(int x = 0; x < steps; x++){
//			if(x == 0) continue;

//			if(outputs[x][let] != 0 && outputs[x-1][let] != 0){
////				int index;
//				deltaRef = 9999999;
//				for(int i = x; i < steps; i++){
//					if(outputs[i][let] == 0 || i == steps-1){
//						x = i;
//						break;
//					}

//					delta = outputs[i][let] - outputs[i-1][let];
//					if(fabs(delta) < deltaRef){
//						deltaRef = fabs(delta);
////						index = i;
//					}
//				}
//				if(outputs[x][let] >= outputs[x-1][let]){
//					indexes.push_back(x);
//				}else{
//					indexes.push_back(x-1);
//				}
//			}else if(x == 1) {
//				if(outputs[x-1][let] != 0 && outputs[x][let] == 0){
//					indexes.push_back(x-1);
//				}
//			}else if(x >= 2 && x <= steps-1){
//				if(outputs[x-2][let] == 0 && outputs[x-1][let] != 0 && outputs[x][let] == 0){
//					indexes.push_back(x-1);
//				}
//			}else if(x == steps-1 && outputs[x-1][let] == 0 && outputs[x][let] != 0){
//				indexes.push_back(x);
//			}
//			//			if(outputs[x][let] <= 0.7){
//			//				outputs[x][let] = 0;
//			//			}

//			//			if(outputs[x][let] > ref){
//			//				ref = outputs[x][let];
//			//				indexes[let] = x;
//			//			}
//		}
//	}
//	sort(indexes.begin(), indexes.end());
//	result = "";
//	for(size_t i = 0; i < indexes.size(); i++){
//		for(size_t j = 0; j < outputs[indexes[i]].size(); j++){
//			if(outputs[indexes[i]][j] == 0) continue;

//			if(j > 25){
//				result += QChar((int)j+22);
//			}else{
//				result += QChar((int)j+65);
//			}
//		}
//	}

//	update();
}

vector<double> ann_gui::MLPObject::filterMayorThan(vector<double> vec, double value)
{
	vector<double> indexes(vec.size(), 0);
	size_t sVector = vec.size();
	for(size_t i = 0; i < sVector; i++){
		if(vec[i] >= value){
			indexes[i] = vec[i];
		}
	}
	return indexes;
}

void ann_gui::MLPObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	GraphicObject::paint(painter, option, widget);

	QRectF rect = getContainerRect();
	QPixmap pm = ICON_MLP.pixmap(rect.size().toSize());

	painter->save();

	painter->fillRect(rect, Qt::white);
	painter->drawPixmap(rect.toRect().adjusted(3, 3, -3, -3), pm);

	painter->restore();
}

void ann_gui::MLPObject::copyClick()
{

}

void ann_gui::MLPObject::cutClick()
{

}

void ann_gui::MLPObject::pasteClick()
{

}

void ann_gui::MLPObject::saveClick()
{

}

void ann_gui::MLPObject::propertyClick()
{
	ANNTrainingDialog *anntd = new ANNTrainingDialog(mlp, this->getTrainingSet());

	anntd->show();
//	MLPObjectPropertyDialog *gmlpepd = new MLPObjectPropertyDialog();

//	gmlpepd->show();
}

void ann_gui::MLPObject::openOnWindowClick()
{
}

void ann_gui::MLPObject::updateInputCursor(int pos)
{
	(void) pos;
	//TODO: 5/14/16 updateInputCursor check this
//	ImageEffect *giee = (ImageEffect*)inputElement;

//	int ih = giee->getImageHeight();
//	if(pos <= giee->getImageWidth() - WINDOW_WIDTH){
//		giee->setCursorRect(pos, 0, WINDOW_WIDTH, ih);
//	}else{
//		giee->setCursorRect(giee->getImageWidth() - WINDOW_WIDTH, 0, WINDOW_WIDTH, ih);
//	}
}

void ann_gui::MLPObject::init(MultilayerPerceptron *mlp, TrainingSet *ts)
{
    Q_INIT_RESOURCE(ann_gui_media);

	input = new QInputDialog();
	//	input->setIntMaximum(9999999);
	connect(input, SIGNAL(intValueChanged(int)), this, SLOT(updateInputCursor(int)));

	//TODO: 10/05/16 Develop detailed view to enable this option
	getOpenAction()->setEnabled(false);

	setMultilayerPerceptron(mlp);
	setTrainingSet(ts);
	setContainerRect(QRectF(0,0,80,80));
}

void ann_gui::MLPObject::onDotMatrixStatusChanged(QVector<int> outputs)
{
	(void) outputs;
	//NOTE: 17/12/14: redefine to handle concurrent_vector
//	vector<double> out = mlp->getOutput(outputs.toStdVector());

//	emit outputChanged(QVector<double>(out.begin(), out.end()));
}

void ann_gui::MLPObject::onDotMatrixStatusChanged(vector<int> outputs)
{
	//NOTE: 7/4/15 aparently there is no reason to to this code, it could be replaced by code below this commented fragment
//	vector<double> out = mlp->getOutput(outputs);
//	QVector<double> sig_out((int)out.size());
//	for(size_t i = 0; i < out.size(); i++){
//		sig_out[i] = out[i];
//	}

	QVector<double> sig_out = QVector<double>::fromStdVector(mlp->getOutput(outputs));
	emit outputChanged(sig_out);
}

void ann_gui::MLPObject::onAddToTrainingSet()
{
//	TrainingSetDialog *tsMLP = new TrainingSetDialog(trainingSet);
//	TrainingSetTable *tempTST = tsMLP->getTrainingSetTable();
//	TrainingSet *tempTS = tempTST->getTrainingSet();

//	switch(inputElement->type()){
//		case DotMatrix::DotMatrixType:
//		{
//			DotMatrix *dm = dynamic_cast<DotMatrix*>(inputElement);
//			QVector<int> intDotList = dm->getDotList();
//			concurrent_vector<double> dotList(intDotList.begin(), intDotList.end());
//			tempTS->appendPattern(dotList/*.toStdVector()*/, concurrent_vector<double>(mlp->getOutputSize(), 0));

//			if(tsMLP->exec() == QDialog::Accepted){
//				//		int sPatterns = tsMLP->getPatternCount();
//				//		vector<MultilayerPerceptronPattern*> ts(sPatterns);
//				//		for(int i = 0; i < sPatterns; i++){
//				//			vector<vector<double> > in = tsMLP->getInputs();
//				//			vector<vector<double> > out = tsMLP->getTargets();
//				//			ts[i] = new MultilayerPerceptronPattern(in[i], out[i]);
//				//		}
//				setTrainingSet(tempTS);
//				//		targets = tsMLP->getTargets();
//				//		inputs = tsMLP->getInputs();
//			}
//		}
//		case GraphicImageEffectElement::GraphicImageEffectType:
//		{
//			//			GraphicImageEffectElement *giee = dynamic_cast<GraphicImageEffectElement*>(inputElement);
//			//			bool ok;

//			//			input->exec();
//			//			int cursor = input->getInteger(NULL, "Cursor", QString::fromUtf8("Posición del cursor"), 0, 0, giee->getImageWidth(), 1, &ok);

//			GraphicImageEffectElement *giee = (GraphicImageEffectElement*)inputElement;

//			giee->setSampledImage(giee->getOutput());
//			giee->setRectangle(giee->getSampledImage().rect());
//			giee->setCursorVisible(true);

//			input->setInputMode(QInputDialog::IntInput);
//			input->setIntMaximum(giee->getImageWidth()-WINDOW_WIDTH);
//			input->setIntValue(0);

//			updateInputCursor(0);
//			if(input->exec() == QInputDialog::Accepted){
//				int cursor = input->intValue();
//				giee->setWindowWidth(WINDOW_WIDTH);
//				//				vector<int> pixels = CommonFunctions::imageToIntVector(giee->getWindow(0, cursor, giee->getWindowWidth(), giee->getImageHeight()));
//				int ww = giee->getWindowWidth();
//				QImage img = giee->getWindow(cursor, 0, ww, giee->getImageHeight());

//				concurrent_vector<long> intImg = CommonFunctions::imageToIntVector(img, CommonFunctions::Bipolar);
//				concurrent_vector<double> dblImg(intImg.begin(), intImg.end());

//				tempTS->appendPattern(dblImg, concurrent_vector<double>(mlp->getOutputSize(), 0));
//				//				appendPattern(CommonFunctions::imageToIntVector(QImage(file), CommonFunctions::Bipolar), vector<int>(targetSize, 0));

//				if(tsMLP->exec() == QDialog::Accepted){
//					//		int sPatterns = tsMLP->getPatternCount();
//					//		vector<MultilayerPerceptronPattern*> ts(sPatterns);
//					//		for(int i = 0; i < sPatterns; i++){
//					//			vector<vector<double> > in = tsMLP->getInputs();
//					//			vector<vector<double> > out = tsMLP->getTargets();
//					//			ts[i] = new MultilayerPerceptronPattern(in[i], out[i]);
//					//		}
//					setTrainingSet(tempTS);
//					//		targets = tsMLP->getTargets();
//					//		inputs = tsMLP->getInputs();
//				}
//			}
//			giee->setCursorVisible(false);
//			giee->setSampledImage(giee->getImage().scaled(50, 50, Qt::KeepAspectRatio));
//			giee->setRectangle(giee->getSampledImage().rect());
//		}
//	}
}
