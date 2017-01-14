#include "annmodelwrapper.h"


ann_gui::ANNModelWrapper::ANNModelWrapper() :
	QAbstractItemModel()
{
	init(0);
}

ann_gui::ANNModelWrapper::ANNModelWrapper(ArtificialNeuralNetwork *ann, QObject *parent) :
	QAbstractItemModel(parent)
{
	init(ann);
}

ann_gui::ANNModelWrapper::~ANNModelWrapper()
{

}

void ann_gui::ANNModelWrapper::setArtificialNeuralNetwork(ArtificialNeuralNetwork *ann)
{
	this->ann = ann;

	switch(ann->getType()){
		case ann_base::ArtificialNeuralNetwork::NoType:

			break;
		case ann_base::ArtificialNeuralNetwork::Adaline:
			adaline = (Adaline*)ann;

			//TODO: 27/4/16 put connections here
			break;
		case ann_base::ArtificialNeuralNetwork::SimplePerceptron:
			sp = (SimplePerceptron*)ann;

			//TODO: 27/4/16 put connections here
			break;
		case ann_base::ArtificialNeuralNetwork::MultilayerPerceptron:
			mlp = (MultilayerPerceptron*)ann;

			connect(mlp, SIGNAL(weightsChanged()), SLOT(onWeightsChanged()));
//			connect(mlp, SIGNAL(trainingAboutStart()), SLOT(onTrainingAboutStart()));
//			connect(mlp, SIGNAL(trainingFinished()), SLOT(onTrainingFinished()));
			connect(mlp, SIGNAL(layerCountChanged(int, int)), SLOT(onLayerCountChanged(int, int)));
			connect(mlp, SIGNAL(layerRemoved(int)), SLOT(onLayerRemoved(int)));
			connect(mlp, SIGNAL(layerSizeChanged(int, int, int)), SLOT(onLayerSizeChanged(int, int, int)));
			break;
		case ann_base::ArtificialNeuralNetwork::Hopfiel:
			hopfield = (Hopfield*)ann;

			//TODO: 27/4/16 put connections here
			break;
		case ann_base::ArtificialNeuralNetwork::Kohonen:
			kohonen = (Kohonen*)ann;

			//TODO: 27/4/16 put connections here
			break;

	}

	setupTree();
}

QVariant ann_gui::ANNModelWrapper::data(const QModelIndex &index, int role) const
{
	//Rechaza en caso de que el indice no sea valido o el rol no sea para mostrar o editar
	if(!index.isValid() || !(role == Qt::DisplayRole || role == Qt::EditRole || Qt::DecorationRole)){
		return QVariant();
	}

	switch(ann->getType()){

		case ann_base::ArtificialNeuralNetwork::MultilayerPerceptron:
		{
			ANNModelTree *item = getItem(index);

			switch(role){
				case Qt::DisplayRole:
					switch(item->getType()){
						case ANNModelTree::Layer:
							if(index.column() == 0){
								return item->getData(index.column());
							}else{
								if(item->getLayer() == mlp->getHiddenLayerCount()){
									return QString::number(item->getData(index.column()).toInt()) + " outputs";
								}else{
									return QString::number(item->getData(index.column()).toInt()) + " neurons";
								}
							}
						case ANNModelTree::Neuron:
							if(index.column() == 0){
								return item->getData(index.column());
							}else{
								return QString::number(item->getData(index.column()).toInt()) + " weights";
							}
						case ANNModelTree::Weight:
							return item->getData(index.column());

						case ANNModelTree::Root:
							return QVariant();
					}

				case Qt::EditRole:
					switch(item->getType()){
						case ANNModelTree::Root:
						case ANNModelTree::Neuron:
							return QVariant();

						case ANNModelTree::Layer:
						case ANNModelTree::Weight:
							return item->getData(index.column());

					}
				case Qt::DecorationRole:
					switch(item->getType()){
						case ANNModelTree::Weight:
							if(index.column() == 0){
								return getWeightColor(item->getData(1).toDouble(), *item->getParent()->getChildren());
							}else{
								return QVariant();
							}

						case ANNModelTree::Root:
						case ANNModelTree::Layer:
						case ANNModelTree::Neuron:
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

bool ann_gui::ANNModelWrapper::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if(role != Qt::EditRole){
		return false;
	}

	if(index.column() == 1){
		ANNModelTree *item = getItem(index);

		switch(item->getType()){
			case ANNModelTree::Root:
			case ANNModelTree::Neuron:
				return false;

			case ANNModelTree::Layer:
				if(item->getData(1) != value){
					if(index.row() < mlp->getHiddenLayerCount()){
						mlp->setLayerSize(index.row(), value.toInt());
					}else{
						mlp->setOutputSize(value.toInt());
					}
					emit dataChanged(index, index);
					return true;
				}else{
					return false;
				}

			case ANNModelTree::Weight:
				mlp->setWeight(index.parent().parent().row(), index.parent().row(), index.row(), value.toDouble());
				emit dataChanged(index, index);

				return true;
		}

	}

	return false;
}

QVariant ann_gui::ANNModelWrapper::headerData(int section, Qt::Orientation orientation, int role) const
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

Qt::ItemFlags ann_gui::ANNModelWrapper::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return 0;

	ANNModelTree *item = getItem(index);

	return item->getFlags(index.column());
}

QModelIndex ann_gui::ANNModelWrapper::index(int row, int column, const QModelIndex &parent) const
{
	ANNModelTree *parentItem = getItem(parent);

	ANNModelTree *childItem = parentItem->getChild(row);
	if (childItem){
		return createIndex(row, column, childItem);
	}else{
		return QModelIndex();
	}
}

QModelIndex ann_gui::ANNModelWrapper::parent(const QModelIndex &child) const
{
	if (!child.isValid())
		return QModelIndex();

	ANNModelTree *childItem = getItem(child);
	ANNModelTree *parentItem = childItem->getParent();

//	if (parentItem == 0)
//		return QModelIndex();
	if (parentItem == rootItem || parentItem == 0)
		return QModelIndex();


	return createIndex(parentItem->childIndex(), child.column(), parentItem);
}

bool ann_gui::ANNModelWrapper::hasChildren(const QModelIndex &parent) const
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
			ANNModelTree *item = getItem(parent);

			switch(item->getType()){
				case ANNModelTree::Root:
					return item->getChildrenCount() > 0;
				case ANNModelTree::Layer:
					if(visibleNeurons){
						return item->getChildrenCount() > 0;
					}else{
						return false;
					}
				case ANNModelTree::Neuron:
					if(visibleWeightValues){
						return item->getChildrenCount() > 0;
					}else{
						return false;
					}
				case ANNModelTree::Weight:
					return false;
			}

		}
		case ann_base::ArtificialNeuralNetwork::Hopfiel:
			break;
		case ann_base::ArtificialNeuralNetwork::Kohonen:
			break;

	}

	return false;
}

int ann_gui::ANNModelWrapper::rowCount(const QModelIndex &parent) const
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
			ANNModelTree *item = getItem(parent);

			switch(item->getType()){
				case ANNModelTree::Root:
					if(visibleOutputLayer){
						return item->getChildrenCount();
					}else{
						return item->getChildrenCount() - 1;
					}
				case ANNModelTree::Layer:
				case ANNModelTree::Neuron:
				case ANNModelTree::Weight:
					return item->getChildrenCount();

			}

		}
		case ann_base::ArtificialNeuralNetwork::Hopfiel:
			break;
		case ann_base::ArtificialNeuralNetwork::Kohonen:
			break;

	}
	return 0;
}

int ann_gui::ANNModelWrapper::columnCount(const QModelIndex &) const
{
	return 2;
}

void ann_gui::ANNModelWrapper::setVisibleOutputLayer(bool b)
{
	visibleOutputLayer = b;
}

bool ann_gui::ANNModelWrapper::getVisibleOutputLayer() const
{
	return visibleOutputLayer;
}

void ann_gui::ANNModelWrapper::setVisibleWeightValues(bool b)
{
	visibleWeightValues = b;
}

bool ann_gui::ANNModelWrapper::getVisibleWeightValues() const
{
	return visibleWeightValues;
}

void ann_gui::ANNModelWrapper::setVisibleNeurons(bool b)
{
	visibleNeurons = b;
}

bool ann_gui::ANNModelWrapper::getVisibleNeurons() const
{
	return visibleNeurons;
}

void ann_gui::ANNModelWrapper::setCanEditLayerSize(bool b)
{
	canEditLayerSize = b;
}

bool ann_gui::ANNModelWrapper::getCanEditLayerSize() const
{
	return canEditLayerSize;
}

void ann_gui::ANNModelWrapper::setCanEditWeights(bool b)
{
	canEditWeights = b;
}

bool ann_gui::ANNModelWrapper::getCanEditWeights() const
{
	return canEditWeights;
}

void ann_gui::ANNModelWrapper::randomizeWeights(double min, double max)
{
	ann->randomizeWeights(min, max);
}

void ann_gui::ANNModelWrapper::setViewType(ANNModelWrapper::ViewType type)
{
	vType = type;
}

void ann_gui::ANNModelWrapper::onWeightsChanged()
{
	updateTree();
	emit dataChanged(QModelIndex(), QModelIndex());
}

void ann_gui::ANNModelWrapper::onLayerCountChanged(int lastCount, int newCount)
{
	//TODO: 29/4/16 onLayerCountChanged check if can improve this. Try to implement "begin" and "end" methods
	//inside updateTree. I think it could be better, it could update row insertion and removing depending on layer count
	//neuron count, weights, etc.

	updateTree();

	if(lastCount <= newCount){
		beginInsertRows(QModelIndex(), lastCount + 1, newCount);
		endInsertRows();
	}else{
		beginRemoveRows(QModelIndex(), newCount + 1, lastCount);
		endRemoveRows();
	}
}

void ann_gui::ANNModelWrapper::onLayerRemoved(int index)
{
	updateTree();

	beginRemoveRows(createIndex(-1, -1), index, index);
	endRemoveRows();
}

void ann_gui::ANNModelWrapper::onLayerSizeChanged(int layer, int lastSize, int newSize)
{
	(void)layer;

	updateTree();

	if(lastSize <= newSize){
		beginInsertRows(createIndex(layer, 0, rootItem->getChildren()->operator [](layer)), lastSize, newSize - 1);
		endInsertRows();
	}else{
		beginRemoveRows(createIndex(layer, 0, rootItem->getChildren()->operator [](layer)), newSize, lastSize - 1);
		endRemoveRows();
	}
}

void ann_gui::ANNModelWrapper::init(ArtificialNeuralNetwork *ann)
{
	if(ann == 0) return;

	canEditLayerSize = true;
	canEditWeights = true;
	visibleNeurons = true;
	visibleWeightValues = true;
	visibleOutputLayer = true;

	setArtificialNeuralNetwork(ann);
	setViewType(Tree);
}

void ann_gui::ANNModelWrapper::setupTree()
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
			vector<vector<vector<double> > > weights = mlp->getWeights();

			int
					lCount = (int)weights.size(),
					nCount = 0,
					wCount = 0;
			QVector<QVariant> data(2);
			QVector<Qt::ItemFlags> flags(2);
			ANNModelTree
					*layerItem,
					*neuronItem,
					*weightItem;

			rootItem = new ANNModelTree(QVector<QVariant>(2), QVector<Qt::ItemFlags>(2), ANNModelTree::Root, 0);

			for(int l = 0; l < lCount; l++){
				nCount = (int)weights[l].size();
				data[0] = l == lCount - 1 ?  "Output layer" : "Layer: " + QString::number(l);
				data[1] = nCount;
				flags[0] = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
				flags[1] = getCanEditLayerSize() ? Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable : Qt::ItemIsEnabled | Qt::ItemIsSelectable;

				layerItem = new ANNModelTree(data, flags, ANNModelTree::Layer, rootItem);
				layerItem->setIndex(l, -1, -1);

				rootItem->addChildItem(layerItem);

				if(getVisibleNeurons()){
					for(int n = 0; n < nCount; n++){
						wCount = (int)weights[l][n].size();
						data[0] = "Neuron: " + QString::number(n);
						data[1] = wCount;
						flags[0] = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
						flags[1] = flags[0];

						neuronItem = new ANNModelTree(data, flags, ANNModelTree::Neuron, layerItem);
						neuronItem->setIndex(l, n, -1);

						layerItem->addChildItem(neuronItem);

						if(getVisibleWeightValues()){
							for(int w = 0; w < wCount; w++){
								data[0] = "w: " + QString::number(w);
								data[1] = weights[l][n][w];
								flags[0] = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
								flags[1] = getCanEditWeights() ? Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable | Qt::ItemNeverHasChildren : Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemNeverHasChildren;

								weightItem = new ANNModelTree(data, flags, ANNModelTree::Weight, neuronItem);
								weightItem->setIndex(l, n, w);

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

void ann_gui::ANNModelWrapper::updateTree()
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
			vector<vector<vector<double> > > weights = mlp->getWeights();

			int
					lCount = (int)weights.size(),
					nCount = 0,
					wCount = 0;
			QVector<QVariant> data(2);
			QVector<Qt::ItemFlags> flags(2);
			ANNModelTree
					*lItem,
					*nItem,
					*wItem;
			int lastSize;

			QVector<ANNModelTree*>
					*rChildren = rootItem->getChildren(),
					*lChildren,
					*nChildren;

			if(lCount != rChildren->size()){

				lastSize = rChildren->size();

				//Dont use resize to fill vector with new TreeItems because it will create new items with a value
				//pointing the same address. At least that's what I believe. Probe it
				rChildren->resize(lCount);

				//this ensures each item is pointing to a diferent address
				if(lastSize < lCount){
					for(int i = lastSize; i < lCount; i++){
						rChildren->operator [](i) = new ANNModelTree(QVector<QVariant>(2), QVector<Qt::ItemFlags>(2), ANNModelTree::Layer, 0);
					}
				}
			}

			for(int l = 0; l < lCount; l++){
				nCount = (int)weights[l].size();
				data[0] = l == lCount - 1 ?  "Output layer" : "Layer: " + QString::number(l);
				data[1] = nCount;
				flags[0] = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
				flags[1] = getCanEditLayerSize() ? Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable : Qt::ItemIsEnabled | Qt::ItemIsSelectable;

				lItem = rootItem->getChildren()->operator [](l);

				lItem->setData(data);
				lItem->setFlags(flags);
				lItem->setType(ANNModelTree::Layer);
				lItem->setParent(rootItem);
				lItem->setIndex(l, -1, -1);

				if(getVisibleNeurons()){

					lChildren = lItem->getChildren();

					if(nCount != lChildren->size()){

						lastSize = lItem->getChildren()->size();

						lChildren->resize(nCount);

						if(lastSize < nCount){
							for(int i = lastSize; i < nCount; i++){
								lChildren->operator [](i) = new ANNModelTree(QVector<QVariant>(2), QVector<Qt::ItemFlags>(2), ANNModelTree::Neuron, 0);
							}
						}
					}
					for(int n = 0; n < nCount; n++){
						wCount = (int)weights[l][n].size();
						data[0] = "Neuron: " + QString::number(n);
						data[1] = wCount;
						flags[0] = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
						flags[1] = flags[0];

						nItem = lChildren->operator [](n);

						nItem->setData(data);
						nItem->setFlags(flags);
						nItem->setType(ANNModelTree::Neuron);
						nItem->setParent(lItem);
						nItem->setIndex(l, n, -1);

						if(getVisibleWeightValues()){

							nChildren = nItem->getChildren();

							if(wCount != nChildren->size()){

								lastSize = nChildren->size();

								nChildren->resize(wCount);

								if(lastSize < wCount){
									for(int i = lastSize; i < wCount; i++){
										nItem->getChildren()->operator [](i) = new ANNModelTree(QVector<QVariant>(2), QVector<Qt::ItemFlags>(2), ANNModelTree::Weight, 0);
									}
								}
							}
							for(int w = 0; w < wCount; w++){
								data[0] = "w: " + QString::number(w);
								data[1] = weights[l][n][w];
								flags[0] = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
								flags[1] = getCanEditWeights() ? Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable | Qt::ItemNeverHasChildren : Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemNeverHasChildren;

								wItem = nItem->getChildren()->operator [](w);

								wItem->setData(data);
								wItem->setFlags(flags);
								wItem->setType(ANNModelTree::Weight);
								wItem->setParent(nItem);
								wItem->setIndex(l, n, w);
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

QColor ann_gui::ANNModelWrapper::getWeightColor(double value, const QVector<ANNModelTree *> &sibling) const
{
	vector<double> vec(sibling.size());

	for(int i = 0; i < sibling.size(); i++){
		vec[i] = sibling[i]->getData(1).toDouble();
	}

	return getHeatColor(value, vec);
}

ann_gui::ANNModelTree *ann_gui::ANNModelWrapper::getItem(const QModelIndex &index) const
{
	if (index.isValid()) {
		ANNModelTree *item = static_cast<ANNModelTree*>(index.internalPointer());
		if (item)
			return item;
	}
	return rootItem;
}
