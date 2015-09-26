#ifndef MAPA_H
#define MAPA_H

#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsScene>

#include <QPainter>
#include <QMimeData>
#include "../core/common.h"

using namespace common;

/*!
 * \brief La clase @code{Enviroment} define un entorno en el que se ubicaran los agentes y demas objetos que formaran
 * parte de un sistema inteligente.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT Enviroment : public QGraphicsScene
{
		Q_OBJECT

		QPixmap grid;
		int gridSpace;

		/**
		  Inicializa el ambiente actual
		  */
		void initMapa();

	public:
		explicit Enviroment(QObject *parent = 0);

	protected:

		/**

		  */
		/*!
		 * \brief drawBackground Implementacion del metodo heredado de la clase QGraphicsScene se usa en este
		 * caso para dibujar una grilla y otros elementos que puedan ir de fondo
		 * \param painter
		 * \param rect
		 */
		void drawBackground(QPainter *painter, const QRectF &rect);

		void dragEnterEvent(QGraphicsSceneDragDropEvent *e);
//        void dragMoveEvent(QGraphicsSceneDragDropEvent *e);
//        void dropEvent(QGraphicsSceneDragDropEvent *e);
};

#endif // MAPA_H
