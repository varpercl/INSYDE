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

			setupTree(mlp->getWeights());

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

	switch(ann->getType()){

		case ann_base::ArtificialNeuralNetwork::MultilayerPerceptron:
		{
			TreeItem *item = getItem(index);

			switch(role){
				case Qt::DisplayRole:
				case Qt::EditRole:
					return item->getData(index.column());

				case Qt::DecorationRole:
					switch(item->getType()){
						case TreeItem::Weight:
							if(index.column() == 0){
								return getWeightColor(item->getData(1).toDouble(), item->parent()->getChildren());
							}else{
								return QVariant();
							}

						case TreeItem::Root:
						case TreeItem::Layer:
						case TreeItem::Neuron:
						default:
							return QVariant();
					}
				default:
					return QVariant();

			}
		}
		case ann_base::ArtificialNeuralNetwork::NoType:
		case ann_base::ArtificialNeuralNetwork::Adaline:
		case ann_base::ArtificialNeuralNetwork::SimplePerceptron:
		case ann_base::ArtificialNeuralNetwork::Hopfiel:
		case ann_base::ArtificialNeuralNetwork::Kohonen:
		default:
			return QVariant();
	}
}

bool ANNModelWrapper::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if(role != Qt::EditRole){
		return false;
	}

	if(index.column() == 1){
		TreeItem *item = getItem(index);

		switch(item->getType()){
			case TreeItem::Root:
			case TreeItem::Neuron:
				return false;

			case TreeItem::Layer:
				mlp->setLayerSize(index.row(), value.toInt());
				emit dataChanged(index, index);

				return true;
			case TreeItem::Weight:
				mlp->setWeight(index.parent().parent().row(), index.parent().row(), index.row(), value.toDouble());
				emit dataChanged(index, index);

				return true;
		}

	}

	return false;
}

QVariant ANNModelWrapper::headerData(int section, Qt::Orientation orientation, int role) const
{
	if(role != Qt::DisplayRole){
		return QVariant();
	}

	switch(orientation){
		case Qt::Horizontal:
			switch(section){
				case 0:
					return "Item";
				case 1:
					return "Valor";
				default:
					return QVariant();
			}
		case Qt::Vertical:
			return QVariant();

		default:
			return QVariant();

	}
}

Qt::ItemFlags ANNModelWrapper::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return 0;

	TreeItem *item = getItem(index);

	return item->getFlags(index.column());
}

QModelIndex ANNModelWrapper::index(int row, int column, const QModelIndex &parent) const
{
	if (parent.isValid() && parent.column() != 0)
		return QModelIndex();

	TreeItem *parentItem = getItem(parent);

	TreeItem *childItem = parentItem->child(row);
	if (childItem)
		return createIndex(row, column, childItem);
	else
		return QModelIndex();
}

QModelIndex ANNModelWrapper::parent(const QModelIndex &child) const
{
	if (!child.isValid())
		return QModelIndex();

	TreeItem *childItem = getItem(child);
	TreeItem *parentItem = childItem->parent();

	if (parentItem == rootItem)
		return QModelIndex();

	return createIndex(parentItem->childNumber(), 0, parentItem);
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
			TreeItem *item = getItem(parent);

			return item->childCount() > 0;
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

	switch(ann->getType()){
		case ann_base::ArtificialNeuralNetwork::NoType:
			break;
		case ann_base::ArtificialNeuralNetwork::Adaline:
			break;
		case ann_base::ArtificialNeuralNetwork::SimplePerceptron:
			break;
		case ann_base::ArtificialNeuralNetwork::MultilayerPerceptron:
		{
			TreeItem *item = getItem(parent);

			return item->childCount();
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
	visibleWeightValues = b;
}

bool ANNModelWrapper::getVisibleWeightValues() const
{
	return visibleWeightValues;
}

void ANNModelWrapper::setVisibleNeurons(bool b)
{
	visibleNeurons = b;
}

bool ANNModelWrapper::getVisibleNeurons() const
{
	return visibleNeurons;
}

void ANNModelWrapper::setCanEditLayerSize(bool b)
{
	canEditLayerSize = b;
}

bool ANNModelWrapper::getCanEditLayerSize() const
{
	return canEditLayerSize;
}

void ANNModelWrapper::setCanEditWeights(bool b)
{
	canEditWeights = b;
}

bool ANNModelWrapper::getCanEditWeights() const
{
	return canEditWeights;
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

	rootItem = 0;

	canEditLayerSize = true;
	canEditWeights = true;
	visibleNeurons = true;
	visibleWeightValues = true;

	setArtificialNeuralNetwork(ann);
	setViewType(Tree);
}

void ANNModelWrapper::setupTree(const vector<vector<vector<double> > > &weights)
{
	if(!rootItem){
		switch(ann->getType()){
			case ann_base::ArtificialNeuralNetwork::NoType:
				break;
			case ann_base::ArtificialNeuralNetwork::Adaline:
				break;
			case ann_base::ArtificialNeuralNetwork::SimplePerceptron:
				break;
			case ann_base::ArtificialNeuralNetwork::MultilayerPerceptron:
			{
				int
						lCount = weights.size(),
						nCount = 0,
						wCount = 0;
				QVector<QVariant> data(2);
				QVector<Qt::ItemFlags> flags(2);
				TreeItem
						*layerItem,
						*neuronItem,
						*weightItem;

				rootItem = new TreeItem(QVector<QVariant>(), QVector<Qt::ItemFlags>(), TreeItem::Root, 0);

				for(int l = 0; l < lCount; l++){
					nCount = weights[l].size();
					data[0] = l == lCount - 1 ?  "Output layer" : "Layer: " + QString::number(l);
					data[1] = nCount;
					flags[0] = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
					flags[1] = getCanEditLayerSize() ? Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable : Qt::ItemIsEnabled | Qt::ItemIsSelectable;

					layerItem = new TreeItem(data, flags, TreeItem::Layer, rootItem);
					rootItem->addChildItem(layerItem);

					if(getVisibleNeurons()){
						for(int n = 0; n < nCount; n++){
							wCount = weights[l][n].size();
							data[0] = "Neuron: " + QString::number(n);
							data[1] = wCount;
							flags[0] = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
							flags[1] = flags[0];

							neuronItem = new TreeItem(data, flags, TreeItem::Neuron, layerItem);
							layerItem->addChildItem(neuronItem);

							if(getVisibleWeightValues()){
								for(int w = 0; w < wCount; w++){
									data[0] = "w: " + QString::number(w);
									data[1] = weights[l][n][w];
									flags[0] = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
									flags[1] = getCanEditWeights() ? Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable | Qt::ItemNeverHasChildren : Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemNeverHasChildren;

									weightItem = new TreeItem(data, flags, TreeItem::Weight, neuronItem);
									neuronItem->addChildItem(weightItem);
								}
							}
						}
					}
				}
				break;
			}
			case ann_base::ArtificialNeuralNetwork::Hopfiel:
				break;
			case ann_base::ArtificialNeuralNetwork::Kohonen:
				break;

		}
	}
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
QColor ANNModelWrapper::getWeightColor(double value, const QList<TreeItem *> &child) const
{
	vector<double> vec(child.size());

	for(int i = 0; i < child.size(); i++){
		vec[i] = child[i]->getData(1).toDouble();
	}

	double
			maxW = *max_element(vec.begin(), vec.end()),
			minW = *min_element(vec.begin(), vec.end()),
			nValue = fabs((value - minW)/(maxW - minW));

	int
			rComponent = nValue <= 0.5 ? 255 : 512 * (1 - nValue),
			gComponent = nValue <= 0.5 ? 512 * nValue : 255;

	return QColor(rComponent, gComponent, 0);
}

TreeItem *ANNModelWrapper::getItem(const QModelIndex &index) const
{
	if (index.isValid()) {
		TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
		if (item)
			return item;
	}
	return rootItem;
}
