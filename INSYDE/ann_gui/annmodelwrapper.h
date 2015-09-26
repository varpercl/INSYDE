#ifndef ANNMODELWRAPPER_H
#define ANNMODELWRAPPER_H

#include <QtCore>

#include "treeitem.h"

#include "../ann_base/mlp.h"

using namespace ann_base;

/*!
 * \brief The ANNModelWrapper class is intended to be an intermediate class between MLP and Model/View.
 * This class wraps a MLP to be used as a Model into any View. You will can show, edit and remove weights and
 * other properties.
 *
 * \author Ing. Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 23/08/2015
 */
class Q_DECL_EXPORT ANNModelWrapper : public QAbstractItemModel
{
	public:

		enum ViewType{
			Tree,
			Table
		};

		explicit ANNModelWrapper();

		explicit ANNModelWrapper(ArtificialNeuralNetwork *ann, QObject *parent = 0);

		~ANNModelWrapper();

		void setArtificialNeuralNetwork(ArtificialNeuralNetwork *ann);

		QVariant data(const QModelIndex &index, int role) const;

		bool setData(const QModelIndex &index, const QVariant &value, int role);

		QVariant headerData(int section, Qt::Orientation orientation, int role) const;

		Qt::ItemFlags flags(const QModelIndex &index) const;

		QModelIndex index(int row, int column, const QModelIndex &parent) const;
		QModelIndex parent(const QModelIndex &child) const;

		bool hasChildren(const QModelIndex &parent) const;

		int rowCount(const QModelIndex &parent = QModelIndex()) const;
		int columnCount(const QModelIndex &parent = QModelIndex()) const;

		void setVisibleWeightValues(bool b);

		bool getVisibleWeightValues() const;

		void setVisibleNeurons(bool b);

		bool getVisibleNeurons() const;

		void setCanEditLayerSize(bool b);

		bool getCanEditLayerSize() const;

		void setCanEditWeights(bool b);

		bool getCanEditWeights() const;

		void randomizeWeights(double min = -0.01, double max = 0.01);

		void setViewType(ViewType type);

	signals:

		void trainingAboutStart();

		void trainingFinished();

	private slots:

		void onWeightsChanged();

		void onTrainingFinished();

		void onTrainingAboutStart();

	private:
		Q_OBJECT

		bool
		canEditLayerSize,
		canEditWeights,
		visibleNeurons,
		visibleWeightValues;

		TreeItem *rootItem;

		ViewType vType;

		MultilayerPerceptron *mlp;

		ArtificialNeuralNetwork *ann;

		void init(ArtificialNeuralNetwork *ann);

		/*!
		 * \brief setupTree This simple method converts a layer-weights array to a tree made from TreeItems.
		 * \param weights
		 */
		void setupTree(const vector<vector<vector<double> > > &weights);

		/*!
		 * \brief getLevel Returns deep of tree
		 * \param parent
		 * \return
		 */
		int getDeepLevel(const QModelIndex &index) const;

		QColor getWeightColor(double value, const vector<double> &vec) const;
		QColor getWeightColor(double value, const QList<TreeItem *> &vec) const;

		TreeItem *getItem(const QModelIndex &index) const;
};

#endif // ANNMODELVIEWWRAPPER_H
