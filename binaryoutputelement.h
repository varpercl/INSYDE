#ifndef BINARYOUTPUTREPRESENTATION_H
#define BINARYOUTPUTREPRESENTATION_H

#include <vector>
#include <graphicelement.h>
#include <graphicmlpelement.h>

using namespace std;

class BinaryOutputElement : public GraphicElement
{
	public:

		enum{BinaryOutputRepresentationType = UserType + 4};

		enum Align{
			Horizontal,
			Vertical
		};

		enum ThresholdType{
			LESS_THAN,
			LESS_EQUAL_THAN,
			GREATER_THAN,
			GREATER_EQUAL_THAN,
			GREATER_THAN_ALL,
			LESS_THAN_ALL
		};

		explicit BinaryOutputElement(int inputs, Align a = Vertical, double threshold = 0, ThresholdType tt = GREATER_THAN);

		void setInputs(const QVector<double> &inputs);
		QVector<double> getInputs();
		QVector<bool> getBinaryInputs();

		void setAligment(Align a);
		Align getAligment();

		void setThresholdType(ThresholdType tt);
		void setThreshold(double threshold);

		void setInputElement(GraphicElement *ge);

		/**
		  Vease funcion @code{type()} de la clase @code{QGraphicsItem}

		  @see type
		  */
		int type() const;

	protected:

		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	protected slots:

		void onInputChanged(QVector<double> input);
		void onPropertyClick();
		void onOpenClick();

	private:
		Q_OBJECT

		double threshold;
		ThresholdType tt;
		QVector<double> inputs;
		Align aligment;
		QRectF intRect;

		void initBOR(int inputs, Align a = Vertical, double threshold = 0, ThresholdType tt = GREATER_THAN);
		void setInputSize(int inputs);
};

#endif // BINARYOUTPUTREPRESENTATION_H
