#ifndef WEIGHTSEDITORDIALOG_H
#define WEIGHTSEDITORDIALOG_H

#include "share_ann_gui_lib.h"
#include "../core/basicdialog.h"
#include "../core/basictree.h"
#include "../core/labeleddoublespinbox.h"

#include "../ann_base/simpleperceptron.h"

#include "../ann_gui/annmodelwrapper.h"

using namespace ann_base;

/*!
 * \class WeightEditorDialog
 *
 * \brief The WeightEditorDialog class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class ANN_GUI_LIB_IMPORT_EXPORT WeightEditorDialog : public BasicDialog
{
	public:

		/*!
		 * \brief WeightEditorDialog
		 * \param parent
		 */
		explicit WeightEditorDialog(QWidget *parent = 0);

		/*!
		 * \brief WeightEditorDialog
		 * \param ann
		 * \param parent
		 */
		explicit WeightEditorDialog(ArtificialNeuralNetwork *ann, QWidget *parent = 0);

		explicit WeightEditorDialog(ANNModelWrapper *mw, QWidget *parent = 0);

		~WeightEditorDialog();

		/*!
		 * \brief setArtificialNeuralNetwork
		 * \param ann
		 */
		void setArtificialNeuralNetwork(ArtificialNeuralNetwork *ann);

		/*!
		 * \brief getArtificialNeuralNetwork
		 * \return
		 */
		ArtificialNeuralNetwork *getArtificialNeuralNetwork() const;

	private slots:

		void onRandomizeClicked();

		void onUpdateClicked();

		void onTrainingAboutStart();

		void onTrainingFinished();

	private:

		Q_OBJECT

		QVBoxLayout *mainLayout;

		QHBoxLayout *hlyRandomize;

		LabeledDoubleSpinBox
		*ldsbFrom,
		*ldsbTo;

		QToolButton
		*btnUpdate,
		*btnRandomize;

		QWidget *centralWidget;

		ANNModelWrapper *model;

		QTreeView *btWeights;

		ArtificialNeuralNetwork *ann;

		void init();
		void init(ANNModelWrapper *mw);
		void init(ArtificialNeuralNetwork *ann);

		void setupUI();
};

#endif // FRMWEIGHTSEDITOR_H
