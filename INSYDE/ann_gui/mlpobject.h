#ifndef GRAPHICMLPELEMENT_H
#define GRAPHICMLPELEMENT_H

#include <QtCore>
#include <QtWidgets>

#include "share_ann_gui_lib.h"
#include "mlpobjectpropertydialog.h"
#include "anntrainingdialog.h"
#include "definitions.h"

#include "../core/common.h"
#include "../core/imageeffect.h"
#include "../core/dotmatrix.h"
#include "../core/graphicobject.h"
#include "../ann_base/mlp.h"

/*!
 * \class
 *
 * \brief GraphicMLPElement es una clase que representa graficamente un objeto del tipo MultilayerPerceptron, contiene
 * funciones de entrenamiento y ajuste de propiedades, entre otras cosas.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class ANN_GUI_LIB_IMPORT_EXPORT MLPObject : public GraphicObject
{


	public:


		/**
		  Construye un objeto a partir de un puntero a un objeto MultilayerPerceptron

		  @param MultilayerPerceptron *mlp - Este objeto contiene las propiedades de la red neuronal que se representara
		  */
		/*!
		 * \brief GraphicMLPElement
		 * \param mlp
		 */
		explicit MLPObject(MultilayerPerceptron *mlp);

		/**
		 * @brief GraphicMLPElement
		 * @param mlp
		 */
		explicit MLPObject(MultilayerPerceptron *mlp, TrainingSet *trainingSet);

		/**
		  Destructor
		  */
		~MLPObject();

		//Heredado de clase base
		QMenu* getContextMenu(QMenu *cntxMenu);
//		void showPropertyDialog();

		//Heredado de clase base
		void setInputElement(GraphicObject *ge);

		/**
		  Vease funcion @code{type()} de la clase @code{QGraphicsItem}

		  @see type
		  */
		int type() const;

		/**
		 * @brief setTrainingSet Asigna un conjunto de entrenamiento a la red neuronal
		 * @param ts Conjunto de entrenamiento que se le asignara a la red
		 */
		void setTrainingSet(TrainingSet *trainingSet);

		/**
		 * @brief getTrainingSet Obtiene el conjunto de entrenamiento actual de la red neuronal
		 * @return
		 */
		TrainingSet *getTrainingSet() const;

		/*!
		 * \brief setValidationSet
		 * \param valSet
		 */
		void setValidationSet(TrainingSet *valSet);

		/*!
		 * \brief getValidationSet
		 * \return
		 */
		TrainingSet *getValidationSet() const;

		/*!
		 * \brief setTestSet
		 * \param testSet
		 */
		void setTestSet(TrainingSet *testSet);

		/*!
		 * \brief getTestSet
		 * \return
		 */
		TrainingSet *getTestSet() const;

		/**
		 * @brief setMultilayerPerceptron Asigna la red neuronal del tipo @code{MultilayerPerceptron} a este objeto grafico
		 * @param mlp Red neuronal que se le asignara
		 */
		void setMultilayerPerceptron(MultilayerPerceptron *mlp);

		/**
		 * @brief getMultilayerPerceptron Devuelve la red neuronal asignada a este objeto grafico
		 * @return
		 */
		MultilayerPerceptron *getMultilayerPerceptron() const;

		/*!
		 * \brief getXML
		 * \return
		 */
		QString getXML() const;

	signals:

		/*!
		 * \brief outputChanged Evento que indica cuando la salida del objeto ha cambiado
		 * \param outputs Vector que contiene los valores de la salida
		 */
		void outputChanged(QVector<double> outputs);

		/*!
		 * \brief outputChanged
		 * \param chars
		 */
		void outputChanged(QVector<char> chars);


	protected:

		/*!
		 * \brief paint
		 * \param painter
		 * \param option
		 * \param widget
		 */
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	protected slots:

		/*!
		 * \brief copyClick
		 */
		void copyClick();

		/*!
		 * \brief cutClick
		 */
		void cutClick();

		/*!
		 * \brief pasteClick
		 */
		void pasteClick();

		/*!
		 * \fn
		 *
		 * \brief saveClick
		 */
		void saveClick();

		/*!
		 * \brief propertyClick
		 */
		void propertyClick();

		/*!
		 * \brief openClick
		 */
		void openOnWindowClick();

	private slots:

		/*!
		 * \brief onAddToTrainingSet Se activa cuando se agrega un elemento al conjunto de entrenamiento
		 */
		void onAddToTrainingSet();

		/*!
		 * \brief onDotMatrixStatusChanged Se activa cuando el elemento (de tipo @code{DotMatrix}) conectado a este objeto grafico cambia su salida
		 * \param outputs
		 */
		void onDotMatrixStatusChanged(QVector<int> outputs);

		/*!
		 * \brief onDotMatrixStatusChanged Se activa cuando el elemento (de tipo @code{DotMatrix}) conectado a este objeto grafico cambia su salida
		 * \param outputs
		 */
		void onDotMatrixStatusChanged(vector<int> outputs);

		/**
		  Se activa cuando se hace click sobre el elemento "Entrenar"
		  del menu contextual de este objeto
		  */
		void onTrainClick();

		/**
		 * @brief onAnalizeClick Este metodo esta diseñado para uso temporal. Puede ser modificado
		 * Es llamado cuando se requiere que el objeto analice y genere una salida a partir del objeto
		 * conectado en la entrada.
		 */
		void onAnalizeClick();

		/*!
		 * \brief updateInputCursor
		 * \param pos
		 */
		void updateInputCursor(int pos);

	private:
		Q_OBJECT

		QString result;

		QInputDialog *input;

		//Conjunto de entrenamiento de esta red
		TrainingSet
		*trainingSet,
		*validationSet,
		*testSet;

		//Instancia de la red neuronal
		MultilayerPerceptron *mlp;

		/**
		 * @brief initMLP Funcion auxiliar para inicializar este objeto grafico
		 * @param mlp
		 */
		void init(MultilayerPerceptron *mlp, TrainingSet *trainingSet);

		/*!
		 * \brief filterMayorThan
		 * \param vec
		 * \param value
		 * \return
		 */
		vector<double> filterMayorThan(vector<double> vec, double value);

};

#endif // GRAPHICMLPELEMENT_H
