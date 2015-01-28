#include "graphicmlpelement.h"

GraphicMLPElement::GraphicMLPElement(MultilayerPerceptron *mlp)
{
	init(mlp, new TrainingSet(mlp->getInputSize(), mlp->getOutputSize()));
}

GraphicMLPElement::GraphicMLPElement(MultilayerPerceptron *mlp, TrainingSet *ts)
{
	init(mlp, ts);
}

GraphicMLPElement::~GraphicMLPElement()
{

}

QMenu *GraphicMLPElement::getContextMenu(QMenu *cntxMenu)
{
	cntxMenu->addAction("Analizar", this, SLOT(onAnalizeClick()));
	cntxMenu->addAction("Agregar al conjunto de entrenamiento", this, SLOT(onAddToTrainingSet()));
	cntxMenu->addAction("Entrenar", this, SLOT(onTrainClick()));
	cntxMenu->addAction("Borrar", this, SLOT(onDeleteClick()));
	cntxMenu->addAction("Propiedades", this, SLOT(onPropertyClick()));

	return cntxMenu;
}

int GraphicMLPElement::type() const
{
	return GraphicMLPElementType;
}

void GraphicMLPElement::setTrainingSet(TrainingSet *ts)
{
	this->trainingSet = ts;
}

TrainingSet* GraphicMLPElement::getTrainingSet() const
{
	return trainingSet;
}

void GraphicMLPElement::setValidationSet(TrainingSet *valSet)
{
	validationSet = valSet;
}

TrainingSet *GraphicMLPElement::getValidationSet() const
{
	return validationSet;
}

void GraphicMLPElement::setTestSet(TrainingSet *testSet)
{
	this->testSet = testSet;
}

TrainingSet *GraphicMLPElement::getTestSet() const
{
	return testSet;
}

void GraphicMLPElement::setMultilayerPerceptron(MultilayerPerceptron *mlp)
{
	this->mlp = mlp;
}

MultilayerPerceptron *GraphicMLPElement::getMultilayerPerceptron() const
{
	return mlp;
}


void GraphicMLPElement::setInputElement(GraphicElement *ge)
{
	//Determina cual es el tipo de elemento de entrada y lo conecta con los eventos correspondientes
	switch(ge->type()){
		case DotMatrix::DotMatrixType:
			DotMatrix *dm = dynamic_cast<DotMatrix*>(ge);
			dm->setOutputElement(this);
			connect(dm, SIGNAL(statusChanged(QVector<int>)), SLOT(onDotMatrixStatusChanged(QVector<int>)));
			break;
	}
	inputElement = ge;
}

void GraphicMLPElement::onTrainClick()
{
	MLPTrainingDialog *mlptd = new MLPTrainingDialog(this);
	mlptd->show();
	//	mlptd->deleteLater();
}

void GraphicMLPElement::onAnalizeClick()
{
	MultilayerPerceptron *mlp = getMultilayerPerceptron();
	GraphicImageEffectElement* giee = (GraphicImageEffectElement*)getInputElement();

	QImage window;

	vector<long> wdwVector;
	vector<vector<double> > outputs;

	int steps = (giee->getImageWidth() / WINDOW_STEP) - WINDOW_WIDTH;
	for(int x = 0; x < steps; x += WINDOW_STEP){
		if(x <= giee->getImageWidth() - WINDOW_WIDTH){
			window = giee->getImage().copy(x, 0, WINDOW_WIDTH, WINDOW_HEIGH);
			wdwVector = CommonFunctions::imageToIntVector(window, CommonFunctions::Bipolar);
			//		finalVector = vector<int>(wdwVector.begin(), wdwVector.end());
			outputs.push_back(mlp->getOutput(wdwVector));
		}else{
			break;
		}
	}

	//	for(int x = 0; x < steps; x++){
	//		window = tmpImage.copy(x*WINDOW_STEP, 0, WINDOW_WIDTH, WINDOW_HEIGH);
	//		wdwVector = imageToVector(window);
	//		finalVector = vector<int>(wdwVector.begin(), wdwVector.end());
	//		outputs.push_back(mlp->getOutput(finalVector));
	//	}

	int sLet = mlp->getOutputSize();
	//	vector<int> indexes(sLet);
	//	double ref = -9999999;
	double threshold = 0;

	input->setInputMode(QInputDialog::DoubleInput);
	input->setDoubleValue(0.65);
	input->setIntMaximum(1);

	if(input->exec() != QInputDialog::Accepted){
		return;
	}else{
		threshold = input->doubleValue();
	}


	for(int x = 0; x < steps; x++){
		for(int let = 0; let < sLet; let++){
			if(outputs[x][let] <= threshold){
				outputs[x][let] = 0;
			}

			//			if(outputs[x][let] > ref){
			//				ref = outputs[x][let];
			//				indexes[let] = x;
			//			}
		}
	}

	//	int sLet = mlp->getOutputSize();
	//	vector<int> indexes(sLet);
	double deltaRef = 9999999;
	double delta = 0;
	vector<int> indexes;
	for(int let = 0; let < sLet; let++){
		for(int x = 0; x < steps; x++){
			if(x == 0) continue;

			if(outputs[x][let] != 0 && outputs[x-1][let] != 0){
//				int index;
				deltaRef = 9999999;
				for(int i = x; i < steps; i++){
					if(outputs[i][let] == 0 || i == steps-1){
						x = i;
						break;
					}

					delta = outputs[i][let] - outputs[i-1][let];
					if(fabs(delta) < deltaRef){
						deltaRef = fabs(delta);
//						index = i;
					}
				}
				if(outputs[x][let] >= outputs[x-1][let]){
					indexes.push_back(x);
				}else{
					indexes.push_back(x-1);
				}
			}else if(x == 1) {
				if(outputs[x-1][let] != 0 && outputs[x][let] == 0){
					indexes.push_back(x-1);
				}
			}else if(x >= 2 && x <= steps-1){
				if(outputs[x-2][let] == 0 && outputs[x-1][let] != 0 && outputs[x][let] == 0){
					indexes.push_back(x-1);
				}
			}else if(x == steps-1 && outputs[x-1][let] == 0 && outputs[x][let] != 0){
				indexes.push_back(x);
			}
			//			if(outputs[x][let] <= 0.7){
			//				outputs[x][let] = 0;
			//			}

			//			if(outputs[x][let] > ref){
			//				ref = outputs[x][let];
			//				indexes[let] = x;
			//			}
		}
	}
	sort(indexes.begin(), indexes.end());
	result = "";
    for(size_t i = 0; i < indexes.size(); i++){
        for(size_t j = 0; j < outputs[indexes[i]].size(); j++){
			if(outputs[indexes[i]][j] == 0) continue;

			if(j > 25){
                result += QChar((int)j+22);
			}else{
                result += QChar((int)j+65);
			}
		}
	}

	update();
}

vector<double> GraphicMLPElement::filterMayorThan(vector<double> vec, double value)
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

void GraphicMLPElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	GraphicElement::paint(painter, option, widget);

	painter->drawImage(getRectangle(), QImage(":imagenes/perceptron multicapa.png"));
	painter->drawText(getRectangle(), result);
}

void GraphicMLPElement::onPropertyClick()
{
	GraphicMLPElementPropertyDialog *gmlpepd = new GraphicMLPElementPropertyDialog();

	gmlpepd->show();
}

void GraphicMLPElement::onOpenClick()
{
}

void GraphicMLPElement::updateInputCursor(int pos)
{
	GraphicImageEffectElement *giee = (GraphicImageEffectElement*)inputElement;

	int ih = giee->getImageHeight();
	if(pos <= giee->getImageWidth() - WINDOW_WIDTH){
		giee->setCursorRect(pos, 0, WINDOW_WIDTH, ih);
	}else{
		giee->setCursorRect(giee->getImageWidth() - WINDOW_WIDTH, 0, WINDOW_WIDTH, ih);
	}
}

void GraphicMLPElement::init(MultilayerPerceptron *mlp, TrainingSet *ts)
{
	input = new QInputDialog();
	//	input->setIntMaximum(9999999);
	connect(input, SIGNAL(intValueChanged(int)), this, SLOT(updateInputCursor(int)));

	setMultilayerPerceptron(mlp);
	setTrainingSet(ts);
	setRectangle(QRectF(0,0,50,50));
}

void GraphicMLPElement::onDotMatrixStatusChanged(QVector<int> outputs)
{
	(void) outputs;
	//NOTE: 17/12/14: redefine to handle concurrent_vector
//	vector<double> out = mlp->getOutput(outputs.toStdVector());

//	emit outputChanged(QVector<double>(out.begin(), out.end()));
}

void GraphicMLPElement::onDotMatrixStatusChanged(vector<int> outputs)
{
	//	inputs = outputs;
	vector<double> out = mlp->getOutput(outputs);
	QVector<double> sig_out(out.size());
	for(size_t i = 0; i < out.size(); i++){
		sig_out[i] = out[i];
	}

	emit outputChanged(sig_out);
}

void GraphicMLPElement::onAddToTrainingSet()
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
