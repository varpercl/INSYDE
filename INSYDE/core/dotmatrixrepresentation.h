#ifndef DOTMATRIZREPRESENTATION_H
#define DOTMATRIZREPRESENTATION_H

#include <QtGui>

#include "datarepresentationwidget.h"
#include "dotmatrixdetailedwindow.h"
#include "integersizewidget.h"
#include "interfaces.h"

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
class Q_DECL_EXPORT DotMatrixRepresentation : public DataRepresentationWidget, public Resizable
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
		void setSize(const QSize &size);

		/*!
		 * \brief getSize
		 * \return
		 */
		QSize getSize() const;

		/*!
		 * \brief setWidth
		 * \param w
		 */
		void setWidth(int w);

		/*!
		 * \brief getWidth
		 * \return
		 */
		int getWidth() const;

		/*!
		 * \brief setHeight
		 * \param h
		 */
		void setHeight(int h);

		/*!
		 * \brief getHeight
		 * \return
		 */
		int getHeight() const;

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

		void sizeChanged(const QSize &size);
		void heightChanged(int h);
		void widthChanged(int w);

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

#endif // DOTMATRIZREPRESENTATION_H
