#ifndef GRAPHICMLPELEMENT_H
#define GRAPHICMLPELEMENT_H

#include <InSyDeGui.h>
#include <ANNFramework/multilayerperceptron.h>

/**
  @class GraphicMLPElement es una clase que representa graficamente un objeto
  del tipo MultilayerPerceptron, contiene funciones de entrenamiento y ajuste de propiedades,
  entre otras cosas.
  */
class GraphicMLPElement : public GraphicElement
{
	public:

		/**
		  Numero que corresponde al tipo de este objeto
		  */
		enum {GraphicMLPElementType = UserType + 2};

		/**
		  Construye un objeto a partir de un puntero a un objeto MultilayerPerceptron

		  @param MultilayerPerceptron *mlp - Este objeto contiene las propiedades de la red neuronal que se representara
		  */
		explicit GraphicMLPElement(MultilayerPerceptron *mlp);

		/**
		  Destructor
		  */
		~GraphicMLPElement();

		//Heredado de clase base
		QMenu* getContextMenu(QMenu *cntxMenu);
//		void showPropertyDialog();

		void setInputElement(GraphicElement *ge);
		GraphicElement* getInputElement();

		void setOutputElement(GraphicElement *ge);
		GraphicElement* getOutputElement();

		/**
		  Vease funcion @code{type()} de la clase @code{QGraphicsItem}

		  @see type
		  */
		int type() const;

		void setTrainingSet(const TrainingSet &ts);
		TrainingSet getTrainingSet() const;

		void setMultilayerPerceptron(MultilayerPerceptron *mlp);
		MultilayerPerceptron *getMultilayerPerceptron();

	signals:
		void outputChanged(QVector<double> outputs);

	public slots:
		/**
		  Este evento se activa cuando se hace click sobre el elemento "Entrenar"
		  del menu contextual de este objeto
		  */
		void onTrainClick();

	protected:

		//Eventos heredados
//		void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	protected slots:

		void onPropertyClick();

	private:
		Q_OBJECT

//		QVector<double> inputs;
		TrainingSet ts;
		//Instancia de la red neuronal
		MultilayerPerceptron *mlp;

		void initMLP(MultilayerPerceptron *mlp);

	private slots:

		void onAddToTrainingSet();
		void onDotMatrixStatusChanged(QVector<int> outputs);
};

#endif // GRAPHICMLPELEMENT_H
