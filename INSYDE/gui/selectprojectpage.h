#ifndef SELECTPROJECTPAGE_H
#define SELECTPROJECTPAGE_H

#include <QTreeWidgetItem>
#include <QWizardPage>

#include "../ann_gui/weighteditordialog.h"
#include "newprojectwizard.h"

namespace Ui {
	class SelectProjectPage;
}

/*!
 * \brief The SelectProjectPage class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT SelectProjectPage : public QWizardPage
{
	public:

		Q_PROPERTY(int projectType READ projectType WRITE setProjectType NOTIFY projectTypeChanged)

		explicit SelectProjectPage(QWidget *parent = 0);
		~SelectProjectPage();

		int nextId() const;

		void setProjectType(int pt);
		int projectType() const;

	signals:
		void projectTypeChanged(int pt);

	private slots:

		/**
		  Este slot es llamado una vez que se ha cambiado el item seleccionado
		  actualmente, entrega dos parametros correspondientes al item actual
		  seleccionado y al item pasado, respectivamente.

		  @param QTreeWidgetItem *current Puntero al item actualmente seleccionado
		  @param QTreeWidgetItem *last Puntero al ultimo item seleccionado
		  */
		void currentItemProjectChanged(QTreeWidgetItem *current, QTreeWidgetItem *last);

		void on_treeProjects_itemDoubleClicked(QTreeWidgetItem *item, int column);

	private:

		Q_OBJECT

		int proType;
		Ui::SelectProjectPage *ui;

		/**
		  Inicializa este formulario
		  */
		void initializePage();

		/**
		  Conecta los eventos necesarios de todos los controles
		  */
		void connectEvents();

};

#endif // SELECTPROJECTPAGE_H
