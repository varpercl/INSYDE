#ifndef ADDAGENTSDIALOG_H
#define ADDAGENTSDIALOG_H

#include "ECGraphicInterface_global.h"
#include <QtCore>
#include <QtGui>
#include "ui_addagentsdialog.h"

namespace Ui {
	class AddAgentsDialog;
}

/**
  La clase @class AddAddAgentsDialog crea un cuadro de dialogo que especifica las propiedades
  iniciales de los agentes que se van a ingresar en un entorno virtual grafico.
  */

class ECGRAPHICINTERFACESHARED_EXPORT AddAgentsDialog : public QDialog
{
		Q_OBJECT

	public:
		Ui::AddAgentsDialog *ui;

		explicit AddAgentsDialog(QWidget *parent = 0);
		~AddAgentsDialog();

	protected:

	private slots:
		void on_cmbAgentType_currentIndexChanged(int index);
};

#endif // ADDAGENTSDIALOG_H
