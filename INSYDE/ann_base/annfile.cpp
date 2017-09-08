#include "annfile.h"

const QString ann_base::ANNFile::STR_ANN_DEFINITION = "ann";
const QString ann_base::ANNFile::STR_VERSION = "version";
const QString ann_base::ANNFile::STR_ANN_TYPE = "type";

using namespace ann_base;

ANNFile::ANNFile() :
	QFile()
{

}

ANNFile::ANNFile(QString path, ann_base::ArtificialNeuralNetwork *ann, Version version) :
	QFile(path)
{
	init(ann, version);
}

ANNFile::~ANNFile()
{

}

bool ann_base::ANNFile::flush()
{
	QXmlStreamWriter tsWriteXML;

	tsWriteXML.setDevice(this);
	tsWriteXML.setAutoFormatting(true);
	tsWriteXML.setAutoFormattingIndent(3);

	tsWriteXML.writeStartDocument();

	tsWriteXML.writeStartElement(STR_ANN_DEFINITION);

	//Write the version of this file
	switch (version)
	{
		case ann_base::ANNFile::v1_0:
			tsWriteXML.writeAttribute(STR_VERSION, "1.0");
			break;

	}

	//The type of ANN
	tsWriteXML.writeAttribute("type", ann->getName());

	//Input size
	tsWriteXML.writeAttribute("inputs", QString::number(ann->getInputSize()));

	//Output size
	tsWriteXML.writeAttribute("outputs", QString::number(ann->getOutputSize()));

	switch (ann->getType()) {
		case ann_base::ArtificialNeuralNetwork::Adaline:
			break;
		case ann_base::ArtificialNeuralNetwork::SimplePerceptron:
			break;
		case ann_base::ArtificialNeuralNetwork::MultilayerPerceptron:
		{
			MultilayerPerceptron *mlp = (MultilayerPerceptron*) ann;

			//The alfa value
			tsWriteXML.writeAttribute("alfa", QString::number(mlp->getAlfa()));

			switch (mlp->getTransferFunctionType()) {
				case ann_base::MultilayerPerceptron::Sigmoid:
					tsWriteXML.writeAttribute("trasferfunction", "sigmoid");
					break;
				case ann_base::MultilayerPerceptron::Tanh:
					tsWriteXML.writeAttribute("trasferfunction", "tanh");
					break;
				default:
					break;
			}

			vector<vector<vector<double> > > weightsArray = mlp->getWeights();

			QString strWeightsContent;

			size_t
					layers = weightsArray.size(),
					neurons = 0,
					weights = 0;

			tsWriteXML.writeStartElement("weights");
			for(size_t l = 0; l < layers; l++)
			{
				tsWriteXML.writeStartElement("layer");
				neurons = weightsArray[l].size();
				for(size_t n = 0; n < neurons; n++)
				{
					tsWriteXML.writeStartElement("neuron");

					//TODO: implement other formats like json
					tsWriteXML.writeAttribute("format", "csv");
					weights = weightsArray[l][n].size();
					for(size_t w = 0; w < weights; w++)
					{
						strWeightsContent += QString::number(weightsArray[l][n][w]);
						if(w < weights - 1)
						{
							strWeightsContent += ",";
						}
					}
					tsWriteXML.writeCharacters(strWeightsContent);
					tsWriteXML.writeEndElement();
				}
				tsWriteXML.writeEndElement();
			}
			tsWriteXML.writeEndElement();

			break;
		}
		case ann_base::ArtificialNeuralNetwork::Hopfiel:
			break;
		case ann_base::ArtificialNeuralNetwork::Kohonen:
			break;

		default:
			break;
	}

	tsWriteXML.writeEndElement();

	tsWriteXML.writeEndDocument();



	return true;
}

void ann_base::ANNFile::setANN(ann_base::ArtificialNeuralNetwork *ann)
{
	//TODO: missing throw signals. Temporarily left as this
	this->ann = ann;

}

ANNFile::Version ANNFile::getVersion() const
{
	return version;
}

void ANNFile::setVersion(const Version &value)
{
	version = value;
}

void ann_base::ANNFile::init(ann_base::ArtificialNeuralNetwork *ann, Version version)
{
	setANN(ann);
	setVersion(version);
}
