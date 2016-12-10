#ifndef TREEITEM_H
#define TREEITEM_H

#include <QtCore>

#include "share_ann_gui_lib.h"

class ANN_GUI_LIB_IMPORT_EXPORT ANNModelTree
{
	public:

		enum ItemType{
			Root,
			Layer,
			Neuron,
			Weight
		};

		/*!
		 * \brief ANNModelTree
		 * \param data
		 * \param flags
		 * \param itemType
		 * \param getParent
		 */
		explicit ANNModelTree(const QVector<QVariant> &data, const QVector<Qt::ItemFlags> &flags, ItemType itemType, ANNModelTree *getParent = 0);

		~ANNModelTree();

		/*!
		 * \brief getChild
		 * \param number
		 * \return
		 */
		ANNModelTree *getChild(int number);

		/*!
		 * \brief setChildren
		 * \param children
		 */
		void setChildren(QVector<ANNModelTree*> *children);

		/*!
		 * \brief getChildren
		 * \return
		 */
		QVector<ANNModelTree *> *getChildren() const;

		/*!
		 * \brief childCount
		 * \return
		 */
		int getChildrenCount() const;

		/*!
		 * \brief getColumnCount
		 * \return
		 */
		int getColumnCount() const;

		/*!
		 * \brief clear
		 */
		void clear();

		/*!
		 * \brief getType
		 * \return
		 */
		ItemType getType() const;

		/*!
		 * \brief getFlags
		 * \param column
		 * \return
		 */
		Qt::ItemFlags getFlags(int column) const;

		/*!
		 * \brief getData
		 * \param column
		 * \return
		 */
		QVariant getData(int column) const;

		/*!
		 * \brief addChildItem
		 * \param getChild
		 * \return
		 */
		bool addChildItem(ANNModelTree *getChild);

		/*!
		 * \brief insertChildren
		 * \param position
		 * \param count
		 * \param columns
		 * \return
		 */
		bool insertChildren(int position, int count, int columns);

		/*!
		 * \brief insertColumns
		 * \param position
		 * \param columns
		 * \return
		 */
		bool insertColumns(int position, int columns);

		/*!
		 * \brief getParent
		 * \return
		 */
		ANNModelTree *getParent() const;

		/*!
		 * \brief removeChildren
		 * \param position
		 * \param count
		 * \return
		 */
		bool removeChildren(int position, int count);

		/*!
		 * \brief removeColumns
		 * \param position
		 * \param columns
		 * \return
		 */
		bool removeColumns(int position, int columns);

		/*!
		 * \brief childNumber
		 * \return
		 */
		int childIndex() const;

		/*!
		 * \brief setData
		 * \param column
		 * \param value
		 */
		void setData(int column, const QVariant &value);

		/*!
		 * \brief setData
		 * \param value
		 */
		void setData(const QVector<QVariant> &value);

		/*!
		 * \brief setFlags
		 * \param column
		 * \param value
		 */
		void setFlags(int column, const Qt::ItemFlags &value);

		/*!
		 * \brief setFlags
		 * \param value
		 */
		void setFlags(const QVector<Qt::ItemFlags> &value);

		/*!
		 * \brief setType
		 * \param type
		 */
		void setType(ItemType type);

		/*!
		 * \brief setParent
		 * \param parent
		 */
		void setParent(ANNModelTree *parent);

		/*!
		 * \brief setIndex
		 * \param layer
		 * \param neuron
		 * \param weight
		 */
		void setIndex(int layer, int neuron, int weight);

		/*!
		 * \brief getLayer
		 * \return
		 */
		inline int getLayer() const {return layer;}

		/*!
		 * \brief getNeuron
		 * \return
		 */
		inline int getNeuron() const {return neuron;}

		/*!
		 * \brief getWeight
		 * \return
		 */
		inline int getWeight() const {return weight;}


		ANNModelTree &operator=(const ANNModelTree &trset);


	private:

		int
		layer,
		neuron,
		weight;

		ItemType itemType;

		QVector<ANNModelTree*> *childItems;

		QVector<QVariant> itemData;

		QVector<Qt::ItemFlags> itemFlags;

		ANNModelTree *parentItem;
};

#endif // TREEITEM_H
