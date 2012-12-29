#ifndef BINARYOUTPUTREPRESENTATION_H
#define BINARYOUTPUTREPRESENTATION_H

#include <vector>
#include <graphicelement.h>

using namespace std;

class BinaryOutputRepresentation : public GraphicElement
{
	public:
		explicit BinaryOutputRepresentation(int inputs = 1);

		void setInputSize(int inputs);
		void setInputs(const vector<double> &inputs);
		vector<double> getInputs();
		vector<int> getBinaryInputs();

	protected:

		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	private:
		Q_OBJECT

		int nInputs;

		void initBOR(int inputs);
};

#endif // BINARYOUTPUTREPRESENTATION_H
