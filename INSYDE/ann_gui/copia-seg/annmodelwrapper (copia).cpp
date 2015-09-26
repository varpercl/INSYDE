#include "annmodelwrapper.h"


ANNModelWrapper::ANNModelWrapper() :
	QAbstractItemModel()
{
	init(0);
}

ANNModelWrapper::ANNModelWrapper(ArtificialNeuralNetwork *ann, QObject *parent) :
	QAbstractItemModel(parent)
{
	init(ann);
}

ANNModelWrapper::~ANNModelWrapper()
{

}

void ANNModelWrapper::setArtificialNeuralNetwork(ArtificialNeuralNetwork *ann)
{
	this->ann = ann;

	switch(ann->getType()){
		case ann_base::ArtificialNeuralNetwork::NoType:
			break;
		case ann_base::ArtificialNeuralNetwork::Adaline:
			break;
		case ann_base::ArtificialNeuralNetwork::SimplePerceptron:
			break;
		case ann_base::ArtificialNeuralNetwork::MultilayerPerceptron:
			mlp = (MultilayerPerceptron*)ann;

			connect(mlp, SIGNAL(weightsChanged()), SLOT(onWeightsChanged()));
			connect(mlp, SIGNAL(trainingAboutStart()), SLOT(onTrainingAboutStart()));
			connect(mlp, SIGNAL(trainingFinished()), SLOT(onTrainingFinished()));
			break;
		case ann_base::ArtificialNeuralNetwork::Hopfiel:
			break;
		case ann_base::ArtificialNeuralNetwork::Kohonen:
			break;

	}
}

QVariant ANNModelWrapper::data(const QModelIndex &index, int role) const
{

	//Rechaza en caso de que el indice no sea valido o el rol no sea para mostrar o editar
	if(!index.isValid()){
		return QVariant();
	}

	int
			row = index.row(),
			col = index.column(),
			rc = rowCount();

	switch(ann->getType()){
		case ann_base::ArtificialNeuralNetwork::NoType:
			break;
		case ann_base::ArtificialNeuralNetwork::Adaline:
			break;
		case ann_base::ArtificialNeuralNetwork::SimplePerceptron:
			break;
		case ann_base::ArtificialNeuralNetwork::MultilayerPerceptron:
		{

			QString *data = static_cast<QString*> (index.internalPointer());
			int
					//root row
					rrow,
					//parent row
					prow;
			vector<vector<vector<double> > > weights = mlp->getWeights();

			switch(getDeepLevel(index)){
				case 1:
					rrow = data->split(":")[0].toInt();

					switch(role){
						case Qt::EditRole:
							switch(col){
								case 1:
									return (int) weights[rrow].size();

								case 0:
								default:
									return QVariant();
							}

						case Qt::DisplayRole:
							switch(col){
								case 0:
									if(row == rc - 1){
										return "Output layer";
									}else{
										return "Layer: " + QString::number(row + 1);
									}
								case 1:
									return QString::number(weights[row].size()) + " neurons";
								default:
									return QVariant();
							}

						case Qt::DecorationRole:
						default:
							return QVariant();
					}


				case 2:
					rrow = data->split(":")[0].toInt();
					prow = data->split(":")[1].toInt();
					switch(role){
						case Qt::DisplayRole:
							switch(col){
								case 0:
									return "Neuron: " + QString::number(row);
								case 1:
									return QString::number(weights[rrow][prow].size()) + " weights";
								default:
									return QVariant();
							}

						case Qt::DecorationRole:
						case Qt::EditRole:
						default:
							return QVariant();
					}
				case 3:
					rrow = data->split(":")[0].toInt();
					prow = data->split(":")[1].toInt();
					switch(role){
						case Qt::DecorationRole:
							switch(col){
								case 0:
									return getWeightColor(weights[rrow][prow][row], weights[rrow][prow]);
								case 1:
								default:
									return QVariant();
							}

						case Qt::EditRole:
							switch(col){
								case 1:
									return weights[rrow][prow][row];

								case 0:
								default:
									return QVariant();
							}

						case Qt::DisplayRole:
							switch(col){
								case 0:
									return "w" + QString::number(row);
								case 1:
									return weights[rrow][prow][row];
								default:
									return QVariant();
							}
						default:
							return QVariant();
					}
			}
		}
		case ann_base::ArtificialNeuralNetwork::Hopfiel:
			break;
		case ann_base::ArtificialNeuralNetwork::Kohonen:
			break;

	}
	return QVariant();
}

bool ANNModelWrapper::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if(role != Qt::EditRole){
		return false;
	}

	if(index.column() == 1){
		mlp->setWeight(index.parent().parent().row(), index.parent().row(), index.row(), value.toDouble());

		emit dataChanged(index, index);

		return true;
	}

	return false;
}

QVariant ANNModelWrapper::headerData(int section, Qt::Orientation orientation, int role) const
{
	if(role != Qt::DisplayRole){
		return QVariant();
	}

	if(orientation == Qt::Horizontal){
		switch(section){
			case 0:
				return "Item";
			case 1:
				return "Valor";
			default:
				return QVariant();
		}
	}

	return QVariant();
}

Qt::ItemFlags ANNModelWrapper::flags(const QModelIndex &index) const
{
	if(!index.isValid())
		return Qt::NoItemFlags;

	int
			row = index.row(),
			col = index.column();
	return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;

	QString *data = static_cast<QString*>(index.internalPointer());
	QStringList indexes = data->split(":");

	switch(getDeepLevel(index)){
		case 1:
			switch(indexes[0].split(",")[1].toInt()){
				case 0:
					return QAbstractItemModel::flags(index);
				case 1:
					return QAbstractItemModel::flags(index) | Qt::ItemIsSelectable | Qt::ItemIsEditable;
				default:
					return QAbstractItemModel::flags(index);
			}
		case 2:
			switch(indexes[1].split(",")[1].toInt()){
				case 0:
				case 1:
				default:
					return QAbstractItemModel::flags(index);
			}
		case 3:
			switch(indexes[2].split(",")[1].toInt()){
				case 0:
					return QAbstractItemModel::flags(index) | Qt::ItemNeverHasChildren;
				case 1:
					return QAbstractItemModel::flags(index) | Qt::ItemIsEditable | Qt::ItemNeverHasChildren;
				default:
					return QAbstractItemModel::flags(index);
			}
		default:
			return QAbstractItemModel::flags(index) | Qt::ItemIsSelectable | Qt::ItemIsEditable;
	}
}

QModelIndex ANNModelWrapper::index(int row, int column, const QModelIndex &parent) const
{

	if (parent.isValid() && parent.column() != 0)
		return QModelIndex();

	switch(ann->getType()){
		case ann_base::ArtificialNeuralNetwork::NoType:
			break;
		case ann_base::ArtificialNeuralNetwork::Adaline:
			break;
		case ann_base::ArtificialNeuralNetwork::SimplePerceptron:
			break;
		case ann_base::ArtificialNeuralNetwork::MultilayerPerceptron:
		{
			QString *data = new QString();
			switch(getDeepLevel(parent)){
				case 0:
					*data = QString::number(row) + "," + QString::number(column);
					break;
				case 1:
					*data = QString::number(parent.row()) + ":" + QString::number(row) + "," + QString::number(column);
					break;
				case 2:
					*data = QString::number(parent.parent().row()) + ":" + QString::number(parent.row()) + ":" + QString::number(row) + "," + QString::number(column);
					break;
				default:
					return QModelIndex();
			}
			return createIndex(row, column, data);
		}
		case ann_base::ArtificialNeuralNetwork::Hopfiel:
			break;
		case ann_base::ArtificialNeuralNetwork::Kohonen:
			break;

	}

	return QModelIndex();
}

QModelIndex ANNModelWrapper::parent(const QModelIndex &child) const
{
	if(!child.isValid()){
		return QModelIndex();
	}

	QString
			*indexData,
			*data;

	QStringList indexes;
	int
			//parent row
			prow = 0;

	data = new QString();
	switch(getDeepLevel(child)){
		case 2:

			indexData = static_cast<QString*>(child.internalPointer());
			indexes = indexData->split(":");
			prow = indexes[0].toInt();
			*data = indexes[0] + "," + QString::number(child.column());

			return createIndex(prow, 0, data);
		case 3:

			indexData = static_cast<QString*>(child.internalPointer());
			indexes = indexData->split(":");
			prow = indexes[1].toInt();
			*data = indexes[0] + ":" + indexes[1] + "," + QString::number(child.column());

			return createIndex(prow, 0, data);
		case 1:
		default:
			return QModelIndex();
	}
}

bool ANNModelWrapper::hasChildren(const QModelIndex &parent) const
{
	switch(ann->getType()){
		case ann_base::ArtificialNeuralNetwork::NoType:
			break;
		case ann_base::ArtificialNeuralNetwork::Adaline:
			break;
		case ann_base::ArtificialNeuralNetwork::SimplePerceptron:
			break;
		case ann_base::ArtificialNeuralNetwork::MultilayerPerceptron:
		{
			if(getDeepLevel(parent) <= 2){
				return true;
			}
		}
		case ann_base::ArtificialNeuralNetwork::Hopfiel:
			break;
		case ann_base::ArtificialNeuralNetwork::Kohonen:
			break;

	}

	return false;
}

int ANNModelWrapper::rowCount(const QModelIndex &parent) const
{
	(void) parent;

	switch(ann->getType()){
		case ann_base::ArtificialNeuralNetwork::NoType:
			break;
		case ann_base::ArtificialNeuralNetwork::Adaline:
			break;
		case ann_base::ArtificialNeuralNetwork::SimplePerceptron:
			break;
		case ann_base::ArtificialNeuralNetwork::MultilayerPerceptron:
		{
			vector<vector<vector<double> > > weights = mlp->getWeights();

			switch(getDeepLevel(parent)){
				case 0:
					return weights.size();
				case 1:
					return weights[parent.row()].size();
				case 2:
					return weights[parent.parent().row()][parent.row()].size();
				default:
					return 0;
			}
		}
		case ann_base::ArtificialNeuralNetwork::Hopfiel:
			break;
		case ann_base::ArtificialNeuralNetwork::Kohonen:
			break;

	}
	return 0;
}

int ANNModelWrapper::columnCount(const QModelIndex &) const
{
	return 2;
}

void ANNModelWrapper::setVisibleWeightValues(bool b)
{
	(void)b;
	//TODO: 5/9/15 setVisibleWeightValues must be implemented
}

void ANNModelWrapper::setVisibleNeurons(bool b)
{
	(void)b;
	//TODO: 5/9/15 setVisibleNeurons must be implemented
}

void ANNModelWrapper::canEditLayerSize(bool b)
{

}

void ANNModelWrapper::randomizeWeights(double min, double max)
{
	ann->randomizeWeights(min, max);
}

void ANNModelWrapper::setViewType(ANNModelWrapper::ViewType type)
{
	vType = type;
}

void ANNModelWrapper::onWeightsChanged()
{
	emit dataChanged(QModelIndex(), QModelIndex());
}

void ANNModelWrapper::onTrainingFinished()
{
	emit trainingFinished();
}

void ANNModelWrapper::onTrainingAboutStart()
{
	emit trainingAboutStart();
}

void ANNModelWrapper::init(ArtificialNeuralNetwork *ann)
{
	if(ann == 0) return;

	setArtificialNeuralNetwork(ann);
	setViewType(Tree);
}

int ANNModelWrapper::getDeepLevel(const QModelIndex &index) const
{
	if(!index.isValid()) return 0;
	QStringList data = static_cast<QString*>(index.internalPointer())->split(":");
	return data.size();
}

QColor ANNModelWrapper::getWeightColor(double value, const vector<double> &vec) const
{
	double
			maxW = *max_element(vec.begin(), vec.end()),
			minW = *min_element(vec.begin(), vec.end()),
			nValue = fabs((value - minW)/(maxW - minW));

	int
			rComponent = nValue <= 0.5 ? 255 : 512 * (1 - nValue),
			gComponent = nValue <= 0.5 ? 512 * nValue : 255;

	return QColor(rComponent, gComponent, 0);
}

