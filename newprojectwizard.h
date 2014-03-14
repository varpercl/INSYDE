#ifndef NEWPROJECTWIZARD_H
#define NEWPROJECTWIZARD_H


#if QT_VERSION >= 0x050000
#include <QWizard>
#else
#include <QtGui>
#endif

//#include <QWizard>

#include "INSYDEUI_global.h"
#include "selectprojectpage.h"
#include "chooseprojectnamepage.h"
#include "ANNGraphicInterface/perceptronpage.h"
#include "ANNGraphicInterface/adalinepage.h"

enum Pages{
	SelectProjectID,
	ChooseProjectNameID,
	PerceptronPageID,
	AdalinePageID
};

namespace Ui{
	class NewProjectWizard;
}

class INSYDEUISHARED_EXPORT NewProjectWizard : public QWizard
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
