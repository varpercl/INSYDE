#ifndef LABELEDWIDGET_H
#define LABELEDWIDGET_H

#include <QtWidgets>

/*!
 * \class
 *
 * \brief The LabeledWidget class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class LabeledWidget : public QWidget
{
	public:

		enum Position{
			Top,
			Bottom,
			Left,
			Right
		};

		explicit LabeledWidget(const QString &str = "Value", const Position &pos = Left, QWidget *parent = 0);

		~LabeledWidget();

		void setLabelText(const QString &text);
		QString getLabelText() const;

		void setLabelPosition(const Position &pos);
		Position getLabelPosition() const;

		void setLabel(QLabel *lbl);
		QLabel *getLabel() const;

	protected:
		QLabel *label;

	private:
		Q_OBJECT

		Position labelPosition;
		QGridLayout *mainLayout;

		void init(const QString &str, const Position &pos);
};

#endif // LABELEDWIDGET_H
