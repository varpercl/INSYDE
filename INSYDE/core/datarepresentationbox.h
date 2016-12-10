#ifndef GBGRAPHICREPRESENTATION_H
#define GBGRAPHICREPRESENTATION_H

#include <QtWidgets>

#include <vector>

#include "share_core_lib.h"
#include "datarepresentation.h"
#include "dotmatrixrepresentation.h"
#include "imagerepresentationwidget.h"
#include "rawrepresentationwidget.h"
#include "dotmatrixdetailedwindow.h"
#include "labeledcombobox.h"

using namespace std;

namespace Ui {
	class gbGraphicRepresentation;
}

class DotMatrixDetailedWindow;
class DotMatrixRepresentation;
class ImageRepresentationWidget;

/*!
 * \class
 *
 * \brief The DataRepresentationBox class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT DataRepresentationBox : public QGroupBox
{

	public:

		/*!
		 * \brief DataRepresentationBox
		 * \param parent
		 */
		explicit DataRepresentationBox(QWidget *parent = 0);

		/*!
		 * \brief DataRepresentationBox
		 * \param inputdata
		 * \param dr
		 * \param parent
		 */
		explicit DataRepresentationBox(const vector<double> &inputdata, DataRepresentation *dr, QWidget *parent = 0);

		~DataRepresentationBox();

		/*!
		 * \brief setInputs
		 * \param inputs
		 */
		virtual void setInputs(const vector<double> &inputs);

		/*!
		 * \brief getInputs
		 * \return
		 */
		vector<double> getInputs() const;

		/*!
		 * \brief getDataRepresentationWidget
		 * \return
		 */
		DataRepresentationWidget *getDataRepresentationWidget() const;

		/*!
		 * \brief getDataRepresentation
		 * \return
		 */
		DataRepresentation *getDataRepresentation() const;

		/*!
		 * \brief setDataRepresentation
		 * \param value
		 */
		void setDataRepresentation(DataRepresentation *value);

		/*!
		 * \brief update
		 */
		void update();

	private slots:

		/*!
		 * \brief changeDataRepresentation
		 * \param index
		 */
		void changeDataRepresentation(int index);

		/*!
		 * \brief onImageSizeChanged
		 * \param size
		 */
		void onSizeChanged(const QSize &size);

		/*!
		 * \brief onImageFormatChanged
		 * \param format
		 */
		void onImageFormatChanged(const QImage::Format &format);

	private:
		Q_OBJECT

		QVBoxLayout *mainLayout;
		LabeledComboBox *repType;

		DataRepresentation *dataRepresentation;
		DataRepresentationWidget *currentRepWidget;
		RawRepresentationWidget *rrw;
		ImageRepresentationWidget *irw;
		DotMatrixRepresentation *dmrw;

		vector<double> inputs;

		/*!
		 * \brief init
		 * \param inputdata
		 * \param dr
		 */
		void init(const vector<double> &inputdata, DataRepresentation *dr);

};

#endif // GBGRAPHICREPRESENTATION_H
