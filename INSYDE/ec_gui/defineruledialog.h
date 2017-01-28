#ifndef DEFINERULEDIALOG_H
#define DEFINERULEDIALOG_H

#include <QtWidgets>

#include "share_ec_gui.h"


namespace Ui {
	class DefineRuleDialog;
}

namespace ec_gui
{
/**
  @class DefineRuleDialog
  @author Edixon Vargas
  @date 08-06-2012

  La clase @code{DefineRuleDialog} crea un cuadro de dialogo que permite editar, insertar y eliminar reglas existentes o no
  el uso de reglas es vital a la hora de crear un comportamiento en los agentes.
  */

class EC_GUI_LIB_IMPORT_EXPORT DefineRuleDialog : public QDialog
{
		Q_OBJECT

	public:

		/**
		  Crea un nuevo cuadro de dialogo que permite hacer las definiciones de las reglas que utilizaran los agentes u
		  otro elementos que compongan una simulacion
		  */
		explicit DefineRuleDialog(QWidget *parent = 0);

		/**
		  Destructor de la clase
		  */
		~DefineRuleDialog();

	private:
		Ui::DefineRuleDialog *ui;
};
}
#endif // DEFINERULEDIALOG_H
