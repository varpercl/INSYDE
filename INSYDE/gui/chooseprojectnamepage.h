#ifndef CHOOSEPROJECTNAMEPAGE_H
#define CHOOSEPROJECTNAMEPAGE_H

#include <QWizardPage>

namespace Ui {
	class ChooseProjectNamePage;
}

/*!
 * \brief The ChooseProjectNamePage class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class ChooseProjectNamePage : public QWizardPage
{
		Q_OBJECT

	public:

		/**
		  Crea una pagina que permite escoger el nombre del proyecto que se va a crear

		  @param QWidget *parent Indica el padre de esta pagina que por lo general es un asistente del tipo QWizard
		  */
		explicit ChooseProjectNamePage(QWidget *parent = 0);
		~ChooseProjectNamePage();

		int nextId() const;

	private:
		Ui::ChooseProjectNamePage *ui;

	protected slots:
//        void show();

};


#endif // CHOOSEPROJECTNAMEPAGE_H
