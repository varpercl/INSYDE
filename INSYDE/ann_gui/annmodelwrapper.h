#ifndef ANNMODELWRAPPER_H
#define ANNMODELWRAPPER_H

#include <QtCore>

#include "annmodeltree.h"

#include "share_ann_gui_lib.h"

#include "../core/common.h"

#include "../ann_base/mlp.h"
#include "../ann_base/adaline.h"
#include "../ann_base/simpleperceptron.h"
#include "../ann_base/hopfield.h"
#include "../ann_base/kohonen.h"

using namespace common;
using namespace ann_base;

/*!
 * \brief The ANNModelWrapper class is intended to be an intermediate class between MLP and Model/View.
 * This class wraps a MLP to be used as a Model into any View. You will can show, edit and remove weights and
 * other properties.
 *
 * \author Ing. Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 23/08/2015
 */
class ANN_GUI_LIB_IMPORT_EXPORT ANNModelWrapper : public QAbstractItemModel
{
	public:

		enum ViewType{
			Tree,
			Table
		};

		/*!
		 * \brief ANNModelWrapper
		 */
		explicit ANNModelWrapper();

		/*!
		 * \brief ANNModelWrapper
		 * \param ann
		 * \param parent
		 */
		explicit ANNModelWrapper(ArtificialNeuralNetwork *ann, QObject *parent = 0);

		~ANNModelWrapper();

		/*!
		 * \brief setArtificialNeuralNetwork
		 * \param ann
		 */
		void setArtificialNeuralNetwork(ArtificialNeuralNetwork *ann);

		/*!
		 * \brief setVisibleOutputLayer
		 * \param b
		 */
		void setVisibleOutputLayer(bool b);

		/*!
		 * \brief getVisibleOutputLayer
		 * \return
		 */
		bool getVisibleOutputLayer() const;

		/*!
		 * \brief setVisibleWeightValues
		 * \param b
		 */
		void setVisibleWeightValues(bool b);

		/*!
		 * \brief getVisibleWeightValues
		 * \return
		 */
		bool getVisibleWeightValues() const;

		/*!
		 * \brief setVisibleNeurons
		 * \param b
		 */
		void setVisibleNeurons(bool b);

		/*!
		 * \brief getVisibleNeurons
		 * \return
		 */
		bool getVisibleNeurons() const;

		/*!
		 * \brief setCanEditLayerSize
		 * \param b
		 */
		void setCanEditLayerSize(bool b);

		/*!
		 * \brief getCanEditLayerSize
		 * \return
		 */
		bool getCanEditLayerSize() const;

		/*!
		 * \brief setCanEditWeights
		 * \param b
		 */
		void setCanEditWeights(bool b);

		/*!
		 * \brief getCanEditWeights
		 * \return
		 */
		bool getCanEditWeights() const;

		/*!
		 * \brief randomizeWeights
		 * \param min
		 * \param max
		 */
		void randomizeWeights(double min = -0.01, double max = 0.01);

		/*!
		 * \brief setViewType
		 * \param type
		 */
		void setViewType(ViewType type);

	protected:
		/*!
		 * \brief data
		 * \param index
		 * \param role
		 * \return
		 */
		QVariant data(const QModelIndex &index, int role) const;

		/*!
		 * \brief setData
		 * \param index
		 * \param value
		 * \param role
		 * \return
		 */
		bool setData(const QModelIndex &index, const QVariant &value, int role);

		/*!
		 * \brief headerData
		 * \param section
		 * \param orientation
		 * \param role
		 * \return
		 */
		QVariant headerData(int section, Qt::Orientation orientation, int role) const;

		/*!
		 * \brief flags
		 * \param index
		 * \return
		 */
		Qt::ItemFlags flags(const QModelIndex &index) const;

		/*!
		 * \brief index
		 * \param row
		 * \param column
		 * \param parent
		 * \return
		 */
		QModelIndex index(int row, int column, const QModelIndex &parent) const;

		/*!
		 * \brief parent
		 * \param child
		 * \return
		 */
		QModelIndex parent(const QModelIndex &child) const;

		/*!
		 * \brief hasChildren
		 * \param parent
		 * \return
		 */
		bool hasChildren(const QModelIndex &parent) const;

		/*!
		 * \brief rowCount
		 * \param parent
		 * \return
		 */
		int rowCount(const QModelIndex &parent = QModelIndex()) const;

		/*!
		 * \brief columnCount
		 * \param parent
		 * \return
		 */
		int columnCount(const QModelIndex &parent = QModelIndex()) const;


//	signals:

//		/*!
//		 * \brief trainingAboutStart
//		 */
//		void trainingAboutStart();

//		/*!
//		 * \brief trainingFinished
//		 */
//		void trainingFinished();

	private slots:

		/*!
		 * \brief onWeightsChanged
		 */
		void onWeightsChanged();

//		void onTrainingFinished();

//		void onTrainingAboutStart();

		/*!
		 * \brief onLayerCountChanged
		 * \param lastCount
		 * \param newCount
		 */
		void onLayerCountChanged(int lastCount, int newCount);

		/*!
		 * \brief onLayerRemoved
		 * \param index
		 */
		void onLayerRemoved(int index);

		/*!
		 * \brief onLayerSizeChanged
		 * \param layer
		 * \param lastSize
		 * \param newSize
		 */
		void onLayerSizeChanged(int layer, int lastSize, int newSize);

	private:
		Q_OBJECT

		bool
		canEditLayerSize,
		canEditWeights,
		visibleNeurons,
		visibleWeightValues,
		visibleOutputLayer;

		ANNModelTree *rootItem;

		ViewType vType;

		Adaline *adaline;
		SimplePerceptron *sp;
		Hopfield *hopfield;
		Kohonen *kohonen;
		MultilayerPerceptron *mlp;

		ArtificialNeuralNetwork *ann;

		/*!
		 * \brief init
		 * \param ann
		 */
		void init(ArtificialNeuralNetwork *ann);

		/*!
		 * \brief setupTree This simple method converts a layer-weights array to a tree made from TreeItems.
		 * \param weights
		 */
		void setupTree();

		/*!
		 * \brief updateTree Updates the current asociated tree. The difference between setup and update tree is that
		 * in this method is not created a new tree and is not created any new tree child (unless children size increased)
		 * It always works with current tree items, modifying its properties with new data as necessary.
		 */
		void updateTree();

		/*!
		 * \brief getWeightColor Get the heat color for a determine weight value taking as a max or min reference all values
		 * contained in \code{sibling}. It is supposed \code{sibling} parameter are ANNModelTree::Weight type
		 *
		 * \param value
		 * \param vec
		 * \return
		 */
		QColor getWeightColor(double value, const QVector<ANNModelTree *> &sibling) const;

		/*!
		 * \brief getItem
		 * \param index
		 * \return
		 */
		ANNModelTree *getItem(const QModelIndex &index) const;
};

#endif // ANNMODELVIEWWRAPPER_H
