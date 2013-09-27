#ifndef GRAPHICMLPELEMENT_H
#define GRAPHICMLPELEMENT_H

#include <graphicimageeffectelement.h>
#include <graphicmlpelementpropertydialog.h>
#include <mlptrainingdialog.h>
#include <dotmatrix.h>
#include <graphicelement.h>
#include <ANNFramework/multilayerperceptron.h>
#include <INSYDECommon/insydefunctions.h>

//using namespace CommonFunctions;

/**
  @class GraphicMLPElement es una clase que representa graficamente un objeto
  del tipo MultilayerPerceptron, contiene funciones de entrenamiento y ajuste de propiedades,
  entre otras cosas.
  */
class GraphicMLPElement : public GraphicElement
{
		Q_OBJECT


	public:

		/**
		  Tipo de este objeto
		  */
		enum {GraphicMLPElementType = UserType + 2};

		/**
		  Construye un objeto a partir de un puntero a un objeto MultilayerPerceptron

		  @param MultilayerPerceptron *mlp - Este objeto contiene las propiedades de la red neuronal que se representara
		  */
		explicit GraphicMLPElement(MultilayerPerceptron *mlp);

		/**
		 * @brief GraphicMLPElement
		 * @param mlp
		 */
		explicit GraphicMLPElement(MultilayerPerceptron *mlp, TrainingSet *ts);

		/**
		  Destructor
		  */
		~GraphicMLPElement();

		//Heredado de clase base
		QMenu* getContextMenu(QMenu *cntxMenu);
//		void showPropertyDialog();

		//Heredado de clase base
		void setInputElement(GraphicElement *ge);

		/**
		  Vease funcion @code{type()} de la clase @code{QGraphicsItem}

		  @see type
		  */
		int type() const;

		/**
		 * @brief setTrainingSet Asigna un conjunto de entrenamiento a la red neuronal
		 * @param ts Conjunto de entrenamiento que se le asignara a la red
		 */
		void setTrainingSet(TrainingSet *ts);

		/**
		 * @brief getTrainingSet Obtiene el conjunto de entrenamiento actual de la red neuronal
		 * @return
		 */
		TrainingSet *getTrainingSet() const;

		/**
		 * @brief setMultilayerPerceptron Asigna la red neuronal del tipo @code{MultilayerPerceptron} a este objeto grafico
		 * @param mlp Red neuronal que se le asignara
		 */
		void setMultilayerPerceptron(MultilayerPerceptron *mlp);

		/**
		 * @brief getMultilayerPerceptron Devuelve la red neuronal asignada a este objeto grafico
		 * @return
		 */
		MultilayerPerceptron *getMultilayerPerceptron();

	signals:

		/**
		 * @brief outputChanged Evento que indica cuando la salida del objeto ha cambiado
		 * @param outputs Vector que contien los valores de la salida
		 */
		void outputChanged(QVector<double> outputs);

		void outputChanged(QVector<char> chars);


	protected:

		//Eventos heredados
//		void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	public slots:

	protected slots:

		//Heredado
		void onPropertyClick();
		void onOpenClick();

	private:

		QString result;

		QInputDialog *input;
//		QVector<double> inputs;

		//Conjunto de entrenamiento de esta red
		TrainingSet *ts;
		//Instancia de la red neuronal
		MultilayerPerceptron *mlp;

		/**
		 * @brief initMLP Funcion auxiliar para inicializar este objeto grafico
		 * @param mlp
		 */
		void initMLP(MultilayerPerceptron *mlp, TrainingSet *ts);

		vector<double> filterMayorThan(vector<double> vec, double value);

	private slots:

		/**
		 * @brief onAddToTrainingSet Se activa cuando se agrega un elemento al conjunto de entrenamiento
		 */
		void onAddToTrainingSet();

		/**
		 * @brief onDotMatrixStatusChanged Se activa cuando el elemento (de tipo @code{DotMatrix}) conectado a este objeto grafico cambia su salida
		 * @param outputs
		 */
		void onDotMatrixStatusChanged(QVector<int> outputs);

		/**
		  Se activa cuando se hace click sobre el elemento "Entrenar"
		  del menu contextual de este objeto
		  */
		void onTrainClick();

		/**
		 * @brief onAnalizeClick Este metodo esta diseñado para uso temporal. Puede ser modificado
		 *Es llamado cuando se requiere que el objeto analice y genere una salida a partir del objeto
		 *conectado en la entrada.
		 */
		void onAnalizeClick();
		void updateInputCursor(int pos);
};

#endif // GRAPHICMLPELEMENT_H
