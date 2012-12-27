#ifndef ADALINEPAGE_H
#define ADALINEPAGE_H

#include <QtGui>

namespace Ui{
    class AdalinePage;
}


class AdalinePage : public QWizardPage
{
    public:
        AdalinePage();

    protected:
        int nextId() const;

    private:
        Ui::AdalinePage *ui;
};

#endif // ADALINEPAGE_H
