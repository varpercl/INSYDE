#ifndef GRAPHICMLPELEMENT_H
#define GRAPHICMLPELEMENT_H

#include <InSyDeGui.h>
#include <RNALibrary/multilayerperceptron.h>

class GraphicMLPElement : public GraphicElement
{
	public:
		explicit GraphicMLPElement(MultilayerPerceptron *mlp);

		~GraphicMLPElement();

		QMenu* getContextMenu(QMenu *cntxMenu);
//		void showPropertyDialog();

		int type() const{
			return MLPElement;
		}

	public slots:
		void onTrainClick();

	protected:

//		void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	private:
		Q_OBJECT

		enum {MLPElement = UserType + 2};
		MultilayerPerceptron *mlp;

		void initMLP(MultilayerPerceptron *mlp);
};

#endif // GRAPHICMLPELEMENT_H
