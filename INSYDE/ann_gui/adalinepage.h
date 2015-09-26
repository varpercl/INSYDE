#ifndef ADALINEPAGE_H
#define ADALINEPAGE_H

#include <QtGui>
#include <QtWidgets>

namespace Ui{
	class AdalinePage;
}

/*!
 * \class
 *
 * \brief The AdalinePage class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class Q_DECL_EXPORT AdalinePage : public QWizardPage
{
	public:
		AdalinePage();

	protected:
		int nextId() const;

	private:
		Ui::AdalinePage *ui;
};

#endif // ADALINEPAGE_H
