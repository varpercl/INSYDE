#ifndef DOUBLEMINMAXVALUEWIDGET_H
#define DOUBLEMINMAXVALUEWIDGET_H

#include <QtWidgets>

#include "share_core_lib.h"
#include "labeleddoublespinbox.h"

namespace core{

/*!
 * \brief The DoubleMinMaxValueWidget class is a widget built specially for those times
 * the user needs to inser a minimum and a maximum value. It's very usefull due user
 * doesn't need to manipulate manually any layout and labels. Everything is built.
 *
 * TODO: Should have validations when set the minimum/maximum acceptable values. I think
 * the method setMinValueMinimum and other related shouldn't exist. It has to be evaluated.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT DoubleMinMaxWidget : public QWidget
{
	public:

		/*!
		 * \brief Build a basic min and max widget.
		 * \param[in] parent The parent of this widget.
		 */
		explicit DoubleMinMaxWidget(QWidget *parent = 0);

		/*!
		 * \brief Build a min and max widget specifying the \p min and \p max values.
		 *
		 * \param min The minimum value the numeric up/down control will have.
		 * \param max The maximum value the numeric up/down control will have.
		 * \param[in] parent The parent of this widget.
		 */
		explicit DoubleMinMaxWidget(double min, double max, QWidget *parent = 0);

		~DoubleMinMaxWidget();

		/*!
		 * \brief Sets the value of the minimum spin box control.
		 * \param val The value to be set.
		 */
		void setMinValue(double val);

		/*!
		 * \brief Gets the current minimum value.
		 * \return A double value who is the minimum acceptable.
		 */
		double getMinValue() const;

		/*!
		 * \brief Sets the maximum acceptable value by the minimum spinbox control.
		 * \param val The maximum value set.
		 */
		void setMinValueMaximum(double val);

		/*!
		 * \brief Gets the maximum acceptable value by the minimum spinbox control.
		 * \return A double value which is the maximum acceptable value by the minimum spinbox control.
		 */
		double getMinValueMaximum() const;

		/*!
		 * \brief Sets the minimum acceptable value by the minimum spinbox control.
		 * \param val
		 */
		void setMinValueMinimum(double val);

		/*!
		 * \brief Gets the minimum acceptable value by the minimum spinbox control.
		 * \return A double value which is the maximum acceptable value by the minimum spinbox control.
		 */
		double getMinValueMinimum() const;

		/*!
		 * \brief Sets the value of the minimum spin box control.
		 * \param val The value to be set.
		 */
		void setMaxValue(double val);

		/*!
		 * \brief Gets the value of the maximum spin control.
		 * \return A double value which is the maximum.
		 */
		double getMaxValue() const;

		/*!
		 * \brief Sets the maximum acceptable value of the maximum spin control.
		 * \param val The value to be set.
		 */
		void setMaxValueMaximum(double val);

		/*!
		 * \brief Gets the value of the maximum spin control.
		 * \return A double value which is the maximum.
		 */
		double getMaxValueMaximum() const;

		/*!
		 * \brief Sets the minimum acceptable value of the maximum spin control.
		 * \param val The minimum value to be set.
		 */
		void setMaxValueMinimum(double val);

		/*!
		 * \brief Gets the minimum acceptable value of the maximum spin control.
		 * \return A double value which is the maximum.
		 */
		double getMaxValueMinimum() const;

		/*!
		 * \brief Sets the number of decimals accepted by each spin box.
		 * \param n The number of decimals.
		 */
		void setDecimals(int n);

		/*!
		 * \brief Gets the number of decimals accepted by each spin box.
		 * \return An integer which is the number of decimals.
		 */
		int getDecimals() const;

		/*!
		 * \brief Allows users to set a customized maximum QDoubleSpinBox or another derived class.
		 *
		 * \note User is responsible for managing hangling pointers.
		 *
		 * \param[in] sb A pointer to a QDoubleSpinBox.
		 */
		void setMaxDoubleSpinBox(QDoubleSpinBox *sb);

		/*!
		 * \brief Gets the pointer to the maximum QDoubleSpinBox.
		 * \return A pointer to a QDoubleSpinBox.
		 */
		QDoubleSpinBox *getMaxDoubleSpinBox() const;

		/*!
		 * \brief Allows users to set a customized minimum QDoubleSpinBox or another derived class.
		 *
		 * \note User is responsible for managing hangling pointers.
		 *
		 * \param[in] sb A pointer to a QDoubleSpinBox.
		 */
		void setMinDoubleSpinBox(QDoubleSpinBox *sb);

		/*!
		 * \brief Gets the pointer to the minimum QDoubleSpinBox.
		 * \return A pointer to a QDoubleSpinBox.
		 */
		QDoubleSpinBox *getMinDoubleSpinBox() const;

		/*!
		 * \brief Sets the aligment of the gui. This can be horizontal and vertical.
		 *
		 * \param alig The wished alignment.
		 */
		void setAligment(Qt::Orientation alig);

		/*!
		 * \brief Gets the current alignment of this control.
		 * \return A Qt::Orientation enum which is the current alignment.
		 */
		Qt::Orientation getAlignment() const;

	private:
		Q_OBJECT

		Qt::Orientation alignment;

		LabeledDoubleSpinBox
		*ldsbMin,
		*ldsbMax;

		QGridLayout *mainLayout;

		/*!
		 * \brief Initialize everything in this gui.
		 * \param min The minimum default value.
		 * \param max The maximum default value.
		 */
		void init(double min, double max);
};
}
#endif // MINMAXVALUEWIDGET_H
