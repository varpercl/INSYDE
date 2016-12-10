#ifndef NEWPROJECTWIZARD_H
#define NEWPROJECTWIZARD_H

#include <QtGui>

#include "../core/common.h"
#include "selectprojectpage.h"
#include "chooseprojectnamepage.h"
#include "../ann_gui/perceptronpage.h"
#include "../ann_gui/adalinepage.h"

enum Pages{
	SelectProjectID,
	ChooseProjectNameID,
	PerceptronPageID,
	AdalinePageID
};

namespace Ui{
	class NewProjectWizard;
}

/*!
 * \brief The NewProjectWizard class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class NewProjectWizard : public QWizard
{
		Q_OBJECT

	public:
		/**
		  Crea un nuevo asistente para la creacion de proyectos de distintos tipos

		  @param QWidget *parent Indica el widget que contendra este asistente, por lo general es la ventana principal quien sera el padre.
		  */
		explicit NewProjectWizard(QWidget *parent = 0);

	signals:

	public slots:

};

#endif // NEWPROJECTWIZARD_H
