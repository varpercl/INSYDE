#ifndef GBGRAPHICREPRESENTATION_H
#define GBGRAPHICREPRESENTATION_H

#include <QtWidgets>

#include <vector>

#include "share_core_lib.h"
#include "chartrepresentation.h"
#include "datarepresentation.h"
#include "dotmatrixrepresentation.h"
#include "imagerepresentationwidget.h"
#include "rawrepresentationwidget.h"
//#include "dotmatrixdetailedwindow.h"
#include "labeledcombobox.h"

using namespace std;

namespace Ui {
	class gbGraphicRepresentation;
}

class DotMatrixDetailedWindow;
class DotMatrixRepresentation;
class ImageRepresentationWidget;

namespace core{

/*!
 * \brief The DataRepresentationBox class if a specialized widget that holds all information of a
 * DataRepresentation object. This class automatically sets and updates all inputs, combo boxes and
 * graphics when the type of data representation or any parameter has changed.
 *
 * This box contains itself a determined DataRepresentationWidget that will be updated acording to the
 * type of data to be represented.
 *
 * Each DataRepresentationWidget contains a DataRepresentation object which is the trunk of this implementation.
 *
 * \see DataRepresentationWidget
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT DataRepresentationBox : public QGroupBox
{

	public:

		/*!
		 * \brief An empty DataRepresentationBox. This doesn't mean that nothing will be shown.
		 * It just only means the widget will be set automatically to Raw data type.
		 * \param parent
		 */
		explicit DataRepresentationBox(QWidget *parent = 0);

		/*!
		 * \brief Construct a DataRepresentationBox with \p inputdata and a respective data representation
		 * \p dr.
		 *
		 * \param inputdata The data to be represented.
		 * \param[in] dr The data representation information to graphically show \p inputdata.
		 * \param[in] parent The parent containter of this widget. Shouldn't be null.
		 */
		explicit DataRepresentationBox(const vector<double> &inputdata, DataRepresentation *dr, QWidget *parent = 0);

		~DataRepresentationBox();

		/*!
		 * \brief Establish the current input data to be represented by this class.
		 *
		 * \param inputs The input data contained inside an std::vector.
		 */
		virtual void setInputs(const vector<double> &inputs);

		/*!
		 * \brief Returns the input data passed to this class.
		 * \return An std::vector which contains the input data passed to this class.
		 */
		vector<double> getInputs() const;

		/*!
		 * \brief Returns the inner widget contained by this box. The widget will depends on
		 * the type of the data, so this means the pointer will be different depending of type itself.
		 * \return A pointer to the DataRepresentationWidget contained by this Box.
		 */
		DataRepresentationWidget *getDataRepresentationWidget() const;

		/*!
		 * \brief Returns the DataRepresentation object who is the base information to sets this
		 * and child widget to its respective structure depending on the type of data representation type.
		 * \return A pointer to the DataRepresentation object.
		 *
		 * \see DataRepresentation
		 */
		DataRepresentation *getDataRepresentation() const;

		/*!
		 * \brief Establish the current data representation and updates all interface.
		 * \param[in] value The data representation object.
		 */
		void setDataRepresentation(DataRepresentation *dr);

		/*!
		 * \brief Updates the graphic interface when called.
		 */
		void update();

	private slots:

		/*!
		 * \brief Change the data representation based on index. This means the current
		 * by-user selected DataRepresentation type.
		 * \param index The index representing the data representation to be shown.
		 */
		void changeDataRepresentation(int index);

		/*!
		 * \brief When changed the size of an image this will update information on DataRepresentation object.
		 *
		 * \param size The new size to be set.
		 */
		void onSizeChanged(const QSize &size);

		/*!
		 * \brief Updates all graphic interface when users have changed the image format.
		 * \param format The new format of the image.
		 */
		void onImageFormatChanged(const QImage::Format &format);

	private:
		Q_OBJECT

		QVBoxLayout *mainLayout;
		LabeledComboBox *repType;

		DataRepresentation *dataRepresentation;

		//The different representation widgets.
		DataRepresentationWidget *currentRepWidget;
		RawRepresentationWidget *rrw;
		ImageRepresentationWidget *irw;
		DotMatrixRepresentation *dmrw;
		ChartRepresentation *crw;

		vector<double> inputs;

		/*!
		 * \brief init
		 * \param inputdata
		 * \param dr
		 */
		void init(const vector<double> &inputdata, DataRepresentation *dr);

};
}
#endif // GBGRAPHICREPRESENTATION_H
