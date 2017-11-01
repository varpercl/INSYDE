#ifndef EXTENDEDLINEEDIT_H
#define EXTENDEDLINEEDIT_H

#include <QtWidgets>

#include "definitions.h"
#include "labeledwidget.h"

namespace core
{

class CORE_LIB_IMPORT_EXPORT ExtendedLineEdit : public LabeledWidget
{
	public:
		ExtendedLineEdit();

		/*!
		 * \brief ExtendedTextBox
		 * \param parent
		 */
//		explicit ExtendedLineEdit(QWidget *parent = Q_NULLPTR);

		/*!
		 * \brief ExtendedTextBox
		 * \param label
		 * \param text
		 * \param parent
		 */
		explicit ExtendedLineEdit(const QString &label, const QString &text = QString(), QWidget *parent = Q_NULLPTR);

		/*!
		 * \brief ExtendedLineEdit
		 * \param cpy
		 */
		ExtendedLineEdit(const ExtendedLineEdit &cpy);

		/*!
		 * \brief getText
		 * \return
		 */
		QString getText() const;

		QLineEdit *getLineEdit() const;

	public slots:

		/*!
		 * \brief setText
		 * \param text
		 */
		void setText(const QString &text);


	private:
		Q_OBJECT

		QLineEdit *txt;

		/*!
		 * \brief init
		 */
		void init(const QString &label);

};

}


#endif // EXTENDEDTEXTBOX_H
