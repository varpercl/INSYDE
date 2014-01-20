#ifndef ADDAGENTSDIALOG_H
#define ADDAGENTSDIALOG_H

#include <QtCore>

#if QT_VERSION > 0x050000
#include <QtWidgets>
#else
#include <QtGui>
#endif

#include "../INSYDEUI_global.h"

namespace Ui {
	class AddAgentsDialog;
}

/**
  La clase @class AddAddAgentsDialog crea un cuadro de dialogo que especifica las propiedades
  iniciales de los agentes que se van a ingresar en un entorno virtual grafico.
  */

class INSYDEUISHARED_EXPORT AddAgentsDialog : public QDialog
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

#endif // ADDAGENTSDIALOG_H
