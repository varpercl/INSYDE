#ifndef DOTMATRIZREPRESENTATION_H
#define DOTMATRIZREPRESENTATION_H

#include <QtGui>

#include "share_core_lib.h"
#include "datarepresentationwidget.h"
#include "dotmatrixdetailedwindow.h"
#include "integersizewidget.h"
#include "undo.h"

namespace core{

class DotMatrix;
class DotMatrixDetailedWindow;

/*!
 * \brief The DotMatrixRepresentation class is a specialized DataRepresentationWidget class.
 * This will always show a DotMatrix and its properties.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT DotMatrixRepresentation : public DataRepresentationWidget, public IResizable
{
	public:

		/*!
		 * \brief Builds a widget with all controls to set information of the DotMatrix object being represented.
		 * \param inputs The inputs with this representation will be built.
		 * \param[in] parent The parent of this widget.
		 */
		explicit DotMatrixRepresentation(const vector<double> &inputs, QWidget *parent = 0);

		~DotMatrixRepresentation();

		void setInputs(const vector<double> &inputs);

		/*!
		 * \brief Gets the current inputs of this representation.
		 * \return
		 */
		vector<double> getInputs() const;

		QSize getSize() const override;
		void setWidth(int w) override;
		int getWidth() const override;
		void setHeight(int h) override;
		int getHeight() const override;

		/*!
		 * \brief Sets a new DotMatrix object \p obj.
		 * \note User is responsible for managing the resulting hangling pointer.
		 * \param[in] obj A pointer to the DotMatrix object.
		 */
		void setDotMatrixObject(DotMatrix *obj);

		/*!
		 * \brief Gets the pointer to the current DotMatrix object.
		 * \return
		 */
		DotMatrix *getDotMatrixObject() const;

	signals:

		/*!
		 * \brief Thrown when size of the DotMatrix object has changed.
		 * \param size The new size.
		 */
		void sizeChanged(const QSizeF &size);

		/*!
		 * \brief Thrown when height of the DotMatrix object has changed.
		 * \param h The new height.
		 */
		void heightChanged(double h);

		/*!
		 * \brief Thrown when width of the DotMatrix object has changed.
		 * \param w The new width.
		 */
		void widthChanged(double w);

	public slots:

		/*!
		 * \brief Sets the size of the DotMatrix object.
		 * \param size The new size.
		 */
		void setSize(const QSize &size) override;

	private:
		Q_OBJECT

		QVBoxLayout *gbPropLayout;
		QGroupBox *gbProperties;
		DotMatrixDetailedWindow *dmWidget;
		IntegerSizeWidget *isw;

		/*!
		 * \brief The init method responsible for setting up the GUI.
		 */
		void init();
};
}
#endif // DOTMATRIZREPRESENTATION_H
