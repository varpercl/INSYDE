#ifndef LABELEDWIDGET_H
#define LABELEDWIDGET_H

#include <QtWidgets>

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

		//TODO: 16/4/15 should add volume, time units.
		enum Units{
			Nothing,
			Pixels,
			Dots,
			Points,
			Milimeters,
			Centimeters,
			Kilometers,
			Meters,
			Inches,
			Feets,
			Miles,
			Percentaje
		};

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

		virtual void setUnits(Units unit);
		Units getUnits() const;

	protected:
		QLabel *label;

	private:
		Q_OBJECT

		Units units;

		Position labelPosition;

		QGridLayout *mainLayout;

		void init(const QString &str, const Position &pos);
};
}
#endif // LABELEDWIDGET_H
