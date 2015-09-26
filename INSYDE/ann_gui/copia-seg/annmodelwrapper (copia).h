#ifndef ANNMODELWRAPPER_H
#define ANNMODELWRAPPER_H

#include <QtCore>

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

		void setVisibleNeurons(bool b);

		void canEditLayerSize(bool b);

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

		ViewType vType;

		MultilayerPerceptron *mlp;

		ArtificialNeuralNetwork *ann;

		void init(ArtificialNeuralNetwork *ann);

		/*!
		 * \brief getLevel Returns deep of tree
		 * \param parent
		 * \return
		 */
		int getDeepLevel(const QModelIndex &index) const;

		QColor getWeightColor(double value, const vector<double> &vec) const;
};

#endif // ANNMODELVIEWWRAPPER_H
