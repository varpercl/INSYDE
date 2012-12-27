#ifndef ACO_H
#define ACO_H

#include <QDialog>

namespace Ui {
    class ACO;
}

class ACO : public QDialog
{
        Q_OBJECT

    public:
        explicit ACO(QWidget *parent = 0);
        ~ACO();

    private:
        Ui::ACO *ui;

    protected:
        void mousePressEvent(QMouseEvent *event);

};

#endif // ACO_H
