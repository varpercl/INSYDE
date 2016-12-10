/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

/*
	treeitem.cpp

	A container for items of data supplied by the simple tree model.
*/

#include "annmodeltree.h"

#include <QStringList>

//! [0]
ANNModelTree::ANNModelTree(const QVector<QVariant> &data, const QVector<Qt::ItemFlags> &flags, ItemType itemType, ANNModelTree *parent)
{
	childItems = new QVector<ANNModelTree*>();
	parentItem = parent;
	itemData = data;
	itemFlags = flags;
	this->itemType = itemType;
}
ANNModelTree::~ANNModelTree()
{
//	qDeleteAll(childItems);
	childItems->clear();
}

ANNModelTree *ANNModelTree::getChild(int number)
{
	return childItems->operator [](number);
}

QVector<ANNModelTree *> *ANNModelTree::getChildren() const
{
	return childItems;
}

int ANNModelTree::getChildrenCount() const
{
	return childItems->size();
}

int ANNModelTree::childIndex() const
{
	if (parentItem)
//		return find(parentItem->childItems.begin(), parentItem->childItems.end(), const_cast<TreeItem*>(this)) - parentItem->childItems.begin();
		return parentItem->childItems->indexOf(const_cast<ANNModelTree*>(this));

	return 0;
}

int ANNModelTree::getColumnCount() const
{
	return itemData.count();
}

void ANNModelTree::clear()
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

ANNModelTree::ItemType ANNModelTree::getType() const
{
	return itemType;
}

Qt::ItemFlags ANNModelTree::getFlags(int column) const
{
	if(column < itemFlags.size()){
		return itemFlags[column];
	}
	return Qt::NoItemFlags;
}

QVariant ANNModelTree::getData(int column) const
{
	return itemData[column];
}

bool ANNModelTree::addChildItem(ANNModelTree *child)
{
	if(child){
		childItems->push_back(child);
		return true;
	}
	return false;
}
//! [6]

//! [7]
bool ANNModelTree::insertChildren(int /*position*/, int /*count*/, int /*columns*/)
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

bool ANNModelTree::insertColumns(int position, int columns)
{
	if (position < 0 || position > itemData.size())
		return false;

	for (int column = 0; column < columns; ++column)
		itemData.insert(position, QVariant());

	foreach (ANNModelTree *child, *childItems)
		child->insertColumns(position, columns);

	return true;
}

ANNModelTree *ANNModelTree::getParent() const
{
	return parentItem;
}

bool ANNModelTree::removeChildren(int position, int count)
{
	if (position < 0 || position + count > childItems->size())
		return false;

	childItems->erase(childItems->begin() + position, childItems->begin() + position + count);

//	for (int row = 0; row < count; ++row)
//		childItems.erase(childItems.begin() + position);

	return true;
}

bool ANNModelTree::removeColumns(int position, int columns)
{
	if (position < 0 || position + columns > itemData.size())
		return false;

	for (int column = 0; column < columns; ++column)
		itemData.remove(position);

	foreach (ANNModelTree *child, *childItems)
		child->removeColumns(position, columns);

	return true;
}

void ANNModelTree::setData(int column, const QVariant &value)
{
	itemData[column] = value;
}

void ANNModelTree::setData(const QVector<QVariant> &value)
{
	itemData = value;
}

void ANNModelTree::setFlags(int column, const Qt::ItemFlags &value)
{
	itemFlags[column] = value;
}

void ANNModelTree::setFlags(const QVector<Qt::ItemFlags> &value)
{
	itemFlags = value;
}

void ANNModelTree::setType(ANNModelTree::ItemType type)
{
	itemType = type;
}

void ANNModelTree::setParent(ANNModelTree *parent)
{
	parentItem = parent;
}

void ANNModelTree::setChildren(QVector<ANNModelTree *> *children)
{
	childItems = children;
}

void ANNModelTree::setIndex(int layer, int neuron, int weight)
{
	this->layer = layer;
	this->neuron = neuron;
	this->weight = weight;
}

ANNModelTree &ANNModelTree::operator=(const ANNModelTree &item)
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
