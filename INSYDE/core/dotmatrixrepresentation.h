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
 * \class
 *
 * \brief The DotMatrixRepresentation class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT DotMatrixRepresentation : public DataRepresentationWidget, public IResizable
{
	public:

		/*!
		 * \brief DotMatrixRepresentation
		 * \param inputs
		 * \param parent
		 */
		explicit DotMatrixRepresentation(const vector<double> &inputs, QWidget *parent = 0);

		~DotMatrixRepresentation();

		/*!
		 * \brief setInputs
		 * \param inputs
		 */
		void setInputs(const vector<double> &inputs);

		/*!
		 * \brief getInputs
		 * \return
		 */
		vector<double> getInputs() const;

		/*!
		 * \brief setSize
		 * \param size
		 */
		void setSize(const QSize &size) override;

		/*!
		 * \brief getSize
		 * \return
		 */
		QSize getSize() const override;

		/*!
		 * \brief setWidth
		 * \param w
		 */
		void setWidth(int w) override;

		/*!
		 * \brief getWidth
		 * \return
		 */
		int getWidth() const override;

		/*!
		 * \brief setHeight
		 * \param h
		 */
		void setHeight(int h) override;

		/*!
		 * \brief getHeight
		 * \return
		 */
		int getHeight() const override;

		/*!
		 * \brief setDotMatrixObject
		 * \param obj
		 */
		void setDotMatrixObject(DotMatrix *obj);

		/*!
		 * \brief getDotMatrixObject
		 * \return
		 */
		DotMatrix *getDotMatrixObject() const;

	signals:

		void sizeChanged(const QSizeF &size);
		void heightChanged(double h);
		void widthChanged(double w);

	private slots:
		void onWidgetSizeChanged(const QSize &s);

	private:
		Q_OBJECT

		QVBoxLayout *gbPropLayout;
		QGroupBox *gbProperties;
		DotMatrixDetailedWindow *dmWidget;
		IntegerSizeWidget *isw;

		void init();
};
}
#endif // DOTMATRIZREPRESENTATION_H
