#ifndef MAPA_H
#define MAPA_H

#include <QtCore>
#include <QtWidgets>

#include "share_core_lib.h"
#include "common.h"

namespace core{

/*!
 * \brief La clase @code{Enviroment} define un entorno en el que se ubicaran los agentes y demas objetos que formaran
 * parte de un sistema inteligente.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT Enviroment : public QGraphicsScene
{

	public:
		explicit Enviroment(QObject *parent = 0);

		/*!
		 * \brief setEnableGrid Determines if dotted grid will be visible
		 * \param b
		 */
		void setGridVisible(bool b);

		/*!
		 * \brief getEnableGrid
		 * \return
		 */
		bool getGridVisible() const;

		/*!
		 * \brief setCenterMarkerVisible Determine wether a marker will be drawn at the center of the enviroment
		 * \param b
		 */
		void setCenterMarkerVisible(bool b);

		/*!
		 * \brief getCenterMarkerVisible
		 * \return
		 */
		bool getCenterMarkerVisible() const;

	protected:

		/**

		  */
		/*!
		 * \brief drawBackground Implementacion del metodo heredado de la clase QGraphicsScene se usa en este
		 * caso para dibujar una grilla y otros elementos que puedan ir de fondo
		 * \param painter
		 * \param rect
		 */
		void drawBackground(QPainter *painter, const QRectF &rect) override;

//		void dragEnterEvent(QGraphicsSceneDragDropEvent *e) override;
//        void dragMoveEvent(QGraphicsSceneDragDropEvent *e);
//        void dropEvent(QGraphicsSceneDragDropEvent *e);

	private:
		Q_OBJECT

		bool
		visibleCenterMarker,
		visibleGrid;

		QPixmap grid;
		int gridSpace;

		void init();
};
}
#endif // MAPA_H
