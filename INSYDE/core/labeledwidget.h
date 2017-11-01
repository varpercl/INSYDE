#ifndef LABELEDWIDGET_H
#define LABELEDWIDGET_H

#include <QtWidgets>

#include "definitions.h"
#include "share_core_lib.h"

namespace core{

/*!
 * \brief The LabeledWidget class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT LabeledWidget : public QWidget
{
	public:

		/*!
		 * \brief LabeledWidget
		 * \param labelText
		 * \param pos
		 * \param parent
		 */
		explicit LabeledWidget(const QString &labelText = "Value", const Position &pos = Left, QWidget *parent = 0);

		~LabeledWidget();

		void setLabelText(const QString &text);
		QString getLabelText() const;

		void setLabelPosition(const Position &pos);
		Position getLabelPosition() const;

		void setLabel(QLabel *lbl);
		QLabel *getLabel() const;

		virtual void setUnits(Units unit);
		Units getUnits() const;

		QLayout *getLayout() const;

	protected:
		QLabel *label;

		void setCentralWidget(QWidget *w);

	private:
		Q_OBJECT

		Units units;

		Position labelPosition;

		QGridLayout *mainLayout;

		void init(const QString &str, const Position &pos);
};
}
#endif // LABELEDWIDGET_H
