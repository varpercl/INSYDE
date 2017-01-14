#include "annmodeltree.h"

#include <QStringList>

ann_gui::ANNModelTree::ANNModelTree(const QVector<QVariant> &data, const QVector<Qt::ItemFlags> &flags, ItemType itemType, ANNModelTree *parent)
{
	childItems = new QVector<ANNModelTree*>();
	parentItem = parent;
	itemData = data;
	itemFlags = flags;
	this->itemType = itemType;
}
ann_gui::ANNModelTree::~ANNModelTree()
{
//	qDeleteAll(childItems);
	childItems->clear();
}

ann_gui::ANNModelTree *ann_gui::ANNModelTree::getChild(int number)
{
	return childItems->operator [](number);
}

QVector<ann_gui::ANNModelTree *> *ann_gui::ANNModelTree::getChildren() const
{
	return childItems;
}

int ann_gui::ANNModelTree::getChildrenCount() const
{
	return childItems->size();
}

int ann_gui::ANNModelTree::childIndex() const
{
	if (parentItem)
//		return find(parentItem->childItems.begin(), parentItem->childItems.end(), const_cast<TreeItem*>(this)) - parentItem->childItems.begin();
		return parentItem->childItems->indexOf(const_cast<ANNModelTree*>(this));

	return 0;
}

int ann_gui::ANNModelTree::getColumnCount() const
{
	return itemData.count();
}

void ann_gui::ANNModelTree::clear()
{
//	for(int i = 0; i < childItems.size(); i++){
//		childItems[i]->clear();
//	}
	layer = -1;
	neuron = -1;
	weight = -1;
	itemType = Root;

	itemData = QVector<QVariant>();

	itemFlags = QVector<Qt::ItemFlags>();

	parentItem = NULL;

	childItems->clear();
}

ann_gui::ANNModelTree::ItemType ann_gui::ANNModelTree::getType() const
{
	return itemType;
}

Qt::ItemFlags ann_gui::ANNModelTree::getFlags(int column) const
{
	if(column < itemFlags.size()){
		return itemFlags[column];
	}
	return Qt::NoItemFlags;
}

QVariant ann_gui::ANNModelTree::getData(int column) const
{
	return itemData[column];
}

bool ann_gui::ANNModelTree::addChildItem(ANNModelTree *child)
{
	if(child){
		childItems->push_back(child);
		return true;
	}
	return false;
}
//! [6]

//! [7]
bool ann_gui::ANNModelTree::insertChildren(int /*position*/, int /*count*/, int /*columns*/)
{
	//TODO: 20/9/15 insertChildren: evaluate if necesary this function
//	if (position < 0 || position > childItems.size())
//		return false;

//	for (int row = 0; row < count; ++row) {
//		QVector<QVariant> data(columns);
//		QVector<Qt::ItemFlags> flags(columns);
//		TreeItem *item = new TreeItem(data, flags, this);
//		childItems.insert(position, item);
//	}

	return false;
}

bool ann_gui::ANNModelTree::insertColumns(int position, int columns)
{
	if (position < 0 || position > itemData.size())
		return false;

	for (int column = 0; column < columns; ++column)
		itemData.insert(position, QVariant());

	foreach (ANNModelTree *child, *childItems)
		child->insertColumns(position, columns);

	return true;
}

ann_gui::ANNModelTree *ann_gui::ANNModelTree::getParent() const
{
	return parentItem;
}

bool ann_gui::ANNModelTree::removeChildren(int position, int count)
{
	if (position < 0 || position + count > childItems->size())
		return false;

	childItems->erase(childItems->begin() + position, childItems->begin() + position + count);

//	for (int row = 0; row < count; ++row)
//		childItems.erase(childItems.begin() + position);

	return true;
}

bool ann_gui::ANNModelTree::removeColumns(int position, int columns)
{
	if (position < 0 || position + columns > itemData.size())
		return false;

	for (int column = 0; column < columns; ++column)
		itemData.remove(position);

	foreach (ANNModelTree *child, *childItems)
		child->removeColumns(position, columns);

	return true;
}

void ann_gui::ANNModelTree::setData(int column, const QVariant &value)
{
	itemData[column] = value;
}

void ann_gui::ANNModelTree::setData(const QVector<QVariant> &value)
{
	itemData = value;
}

void ann_gui::ANNModelTree::setFlags(int column, const Qt::ItemFlags &value)
{
	itemFlags[column] = value;
}

void ann_gui::ANNModelTree::setFlags(const QVector<Qt::ItemFlags> &value)
{
	itemFlags = value;
}

void ann_gui::ANNModelTree::setType(ANNModelTree::ItemType type)
{
	itemType = type;
}

void ann_gui::ANNModelTree::setParent(ANNModelTree *parent)
{
	parentItem = parent;
}

void ann_gui::ANNModelTree::setChildren(QVector<ANNModelTree *> *children)
{
	childItems = children;
}

void ann_gui::ANNModelTree::setIndex(int layer, int neuron, int weight)
{
	this->layer = layer;
	this->neuron = neuron;
	this->weight = weight;
}

ann_gui::ANNModelTree &ann_gui::ANNModelTree::operator=(const ANNModelTree &item)
{
	layer = item.getLayer();
	neuron = item.getNeuron();
	weight = item.getWeight();

	itemData[0] = item.getData(0);
	itemData[1] = item.getData(1);

	itemFlags[0] = item.getFlags(0);
	itemFlags[1] = item.getFlags(1);

	itemType = item.getType();

	childItems = item.getChildren();
	parentItem = item.getParent();

	return *this;
}
