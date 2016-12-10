#ifndef WEIGHTLINE_H
#define WEIGHTLINE_H

#include <QObject>
#include <QGraphicsLineItem>

#include "share_ann_gui_lib.h"
#include "../ann_base/simpleperceptron.h"

using namespace ann_base;

/*!
 * \class
 *
 * \brief La clase WeightLine representa las lineas que conectan el nucleo
 * con las entradas, estas lineas tienen propiedades especificas como el color,
 * que varia en funcion de su peso sinaptico correspondiente. Asimismo, poseen un
 * indice que permite identificar a que peso sinaptico corresponde en la red
 * neuronal
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class ANN_GUI_LIB_IMPORT_EXPORT WeightLine : public QObject, public QGraphicsLineItem
{
	public:
		explicit WeightLine(const QLineF &line, SimplePerceptron *sp, int index, QGraphicsItem *parent = 0);

		explicit WeightLine(const QLineF &line, double weight, double maxWeight, double minWeight, int lineWidth, SimplePerceptron *sp, int index, QGraphicsItem *parent = 0);

		~WeightLine();

		void setWeightValue(double w);
		double getWeightValue() const;

		void setMaxWeightValue(double wu);
		double getMaxWeightValue() const;

		void setMinWeightValue(double wl);
		double getMinWeightValue() const;

		void setLineWidht(int lw);
		int getLineWidth() const;

		void setAutomaticWeightLimits(bool aw);
		bool getAutomaticWeightLimit() const;

		void setWeightIndex(int i);
		int getWeightIndex() const;

		QColor getWeightLineColor() const;

		void updateWeightColor();

	signals:
		void weightValueChanged(int index, double before, double after);

	protected:
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
		void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
		void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
		void mousePressEvent(QGraphicsSceneMouseEvent *event);
		void focusOutEvent(QFocusEvent *event);

	private:

		Q_OBJECT

		int wi;
		SimplePerceptron *sp;
		bool automaticWeightsLimit;
		int lineWidth;
//		WeightEditProxy* piWeightEdit;
		QColor wlColor;
		double weight;
		double weightUpper;
		double weightLower;

		void init(SimplePerceptron *sp, int index, double weight = 0, double maxW = 100, double minW = -100, int lineWidth = 2);
};

#endif // WEIGHTLINE_H
