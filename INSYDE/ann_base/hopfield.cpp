#include "hopfield.h"

using namespace ann_base;

void Hopfield::init(unsigned int neuronCount, OutputType tf)
{
	setNumberNeurons(neuronCount);
	setOutputFunction(tf);
}

bool Hopfield::propagateUnit(int i)
{
	int  Out;
	bool Changed;
	size_t sInputs = miu.size();
	Changed = false;
	int Sum = 0;
	for (size_t j = 0; j < sInputs; j++) {
		Sum += weights[i][j] * miu[j];
	}
	if (Sum != 0) {
		if (Sum < 0) Out = -1;
		if (Sum > 0) Out = 1;

		if (Out != miu[i]) {
			Changed = true;
			miu[i] = Out;
		}
	}
	return Changed;
}

Hopfield::Hopfield(unsigned int neuronNumber, OutputType tf)
//	:
//	ArtificialNeuralNetwork(neuronNumber, neuronNumber)
{
	init(neuronNumber, tf);
}

Hopfield::~Hopfield()
{

}

void Hopfield::setNumberNeurons(unsigned int nc)
{
	weights.resize(nc);
	size_t sw = weights.size();
	for(size_t i = 0; i < sw; i++){
		weights[i].resize(nc);
	}
	neuronNumber = nc;
}

unsigned int Hopfield::getNumberNeurons() const
{
	return neuronNumber;
}

void Hopfield::setOutputFunction(OutputType tf)
{
	this->tf = tf;
}

Hopfield::OutputType Hopfield::getOutputFunction()
{
	return tf;
}

vector<vector<int> > Hopfield::calculateWeights(const vector<vector<double> > &patterns)
{
//    QFile f("HOPFIELD.txt");
//    f.open(QFile::ReadWrite); // file opened successfully
////    f->write("", qstrlen(""));
//    QTextStream t(&f); // use a text stream

	size_t sPatterns = patterns.size();
//    QString str = "";
	for(int i = 0; i < neuronNumber; i++){
//        str = "\n\r";
		for(int j = 0; j < neuronNumber; j++){
			weights[i][j] = 0;
			if(i != j){
				for(size_t s = 0; s < sPatterns; s++){
					weights[i][j] += patterns[s][i] * patterns[s][j];
				}
			}
//            str += QString::number(weights[i][j]) + ("\t");
		}
//        str+= ("\r\n");
//        qDebug() << str;
	}
//    t<<str;
//    vector<double> rnds = getRandomValues(neuronNumber);
//    miu = rnds;
//    getOutput(rnds);
//    qDebug() << str;
	return weights;
}

int Hopfield::getOutputSize() const
{
	return getNumberNeurons();
}

int Hopfield::getInputSize() const
{
	return getNumberNeurons();
}

void Hopfield::setInputSize(int i)
{
	setNumberNeurons(i);
}

void Hopfield::setOutputSize(int)
{

}

Hopfield::OutputResult Hopfield::getOutput(const vector<double> &inputs, const PropagationType &pt)
{
	Hopfield::OutputResult output;
	int counter = 0;
	int lastChangeIteration = 0;
	int unit = 0;
	bool breakCond;

	//Ultima salida que tuvo la red
	miu = inputs;
//    vector<double> newMiu(miu.size(), 0);

//    output.outputHistory.push_back(miu);
//    int prevOut;
//    int sum;
//    bool change = false;
	do{
//        change = false;
		counter++;
		switch(pt){
			case Random:
                if (propagateUnit(core::math::randomNumber(0, neuronNumber-1))){
					lastChangeIteration = counter;
				}
				breakCond = (counter - lastChangeIteration) < (10*neuronNumber);
				break;
			case Sequential:
				if (propagateUnit(unit++)){
					lastChangeIteration = counter;
				}
				breakCond = counter - lastChangeIteration < neuronNumber;
				break;
		}





//        int i = randomNumber(0, neuronNumber-1);
//        sum = 0;
//        for(int j = 0; j < neuronNumber; j++){
//            sum += weights[i][j]*miu[j];
//        }

//        prevOut = miu[i];
//        if(sum != 0)
//            miu[i] = sum > 0 ? 1: -1;

//        if(miu[i] != prevOut){
////            change = true;
//            lastChangeIteration = counter;
//        }

//        output.outputHistory.push_back(miu);
	}while(breakCond);

	output.output = miu;
	output.iterations = counter;
	return output;
}

ArtificialNeuralNetwork::Type Hopfield::getType() const
{
	return ArtificialNeuralNetwork::Hopfiel;
}

QString Hopfield::getName() const
{
	return "Hopfield";
}

void Hopfield::randomizeWeights(double min, double max)
{
	(void)min;
	(void)max;
	//TODO: 25/4/16 randomizeWeights implement
}

//void PropagateNet(NET* Net)
//{
//    int Iteration, IterationOfLastChange;

//    Iteration = 0;
//    IterationOfLastChange = 0;
//    do {
//        Iteration++;
//        if (PropagateUnit(Net, RandomEqualINT(0, Net->Units-1)))
//            IterationOfLastChange = Iteration;
//    }while(Iteration-IterationOfLastChange < 10*Net->Units);
//}
