#ifndef PERCEPTRONDISPLAY_H
#define PERCEPTRONDISPLAY_H

#include <QtGui>

#include <float.h>

#include "RNALibrary/simpleperceptron.h"

class PerceptronInput;
class Soma;

class PerceptronDetailedDisplay : public QGraphicsScene
{
        Q_OBJECT

    public:
        explicit PerceptronDetailedDisplay(SimplePerceptron *sp);

        ~PerceptronDetailedDisplay();

        void setInputSize(int n);
        int getInputSize();

        void setPerceptron(SimplePerceptron *sp);
        SimplePerceptron* getPerceptron();

    signals:

    public slots:

    private:

        SimplePerceptron *sp;
        QVector<PerceptronInput*> piInputs;
        QVector<QGraphicsLineItem*> gliWeights;
        Soma *nucleo;

        void initPDisplay(SimplePerceptron *sp);
};

class PerceptronInput : public QGraphicsProxyWidget
{
        Q_OBJECT

    public:

        enum NodePosition{
            Left,
            Right,
            Top,
            Bottom
        };

        QLineEdit *leValue;

        explicit PerceptronInput();

        void setNodePosition(NodePosition nodePosition);
        NodePosition getNodePosition();

        QPointF getNodeCenter() const;

    protected:
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
//        QRectF boundingRect() const;
//        QPainterPath shape() const;

    private:
        NodePosition nodePosition;
        QWidget *wg;
        int nodeDiameter;
        QRectF nodeRect;

        void initPI();
};

class Soma : public QGraphicsEllipseItem
{
    public:
        explicit Soma(QGraphicsItem * parent = 0, QGraphicsScene *scene = 0);
        explicit Soma(const QRectF & rect, QGraphicsItem * parent = 0, QGraphicsScene *scene = 0);
        explicit Soma(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent = 0, QGraphicsScene *scene = 0);

        QPointF getCenter() const;

    protected:
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        QRectF boundingRect() const;
};

#endif // PERCEPTRONDISPLAY_H
