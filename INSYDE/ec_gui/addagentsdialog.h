#ifndef ADDAGENTSDIALOG_H
#define ADDAGENTSDIALOG_H

#include <QtGui>
#include <QtWidgets>

#include "share_ec_gui.h"
#include "../core/common.h"

namespace Ui {
	class AddAgentsDialog;
}

namespace ec_gui
{

/*!
 * \brief The AddAgentsDialog class represents a dialog with all basic properties
 * of a basic agent the user will add to the enviroment.
 */
class EC_GUI_LIB_IMPORT_EXPORT AddAgentsDialog : public QDialog
{

	public:

		explicit AddAgentsDialog(QWidget *parent = 0);
		~AddAgentsDialog();

		int getMaxVitality();
		int getInitialVitality();
		int getMaxEnergy();
		int getInitialEnergy();
		int getSpeed();
		int getVisualScope();
		int getNumOfUnits();
		int getCurrentController();
		int getCurrentColor();
		int getCurrentAgentType();
		int getPowerValue();
		int getRangeValue();

	protected:

	private slots:
		void on_cmbAgentType_currentIndexChanged(int index);

	private:
		Q_OBJECT
		Ui::AddAgentsDialog *ui;
};
}
#endif // ADDAGENTSDIALOG_H
