#ifndef MAPA_H
#define MAPA_H

#include <QtCore>
#include <QtWidgets>

#include "share_core_lib.h"
#include "common.h"

namespace core{

/*!
 * \brief The Enviroment class defines an graphic space where user can allocate every agent, neural network and another
 * system block.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT Enviroment : public QGraphicsScene
{

	public:

		/*!
		 * \brief Builds an empty enviroment.
		 * \param [in] parent The parent of this enviroment.
		 */
		explicit Enviroment(QObject *parent = 0);

		/*!
		 * \brief Determines if dotted grid will be visible.
		 * \param b True will make the grid visible.
		 */
		void setGridVisible(bool b);

		/*!
		 * \brief Gets the current visible status of the grid.
		 * \return True in case of grid visible.
		 */
		bool getGridVisible() const;

		/*!
		 * \brief Determines wether a marker will be drawn at the center of the enviroment.
		 * \param b True will make the marker to be visible.
		 */
		void setCenterMarkerVisible(bool b);

		/*!
		 * \brief Gets the status of the center marker visibility.
		 * \return True in case of the marker visible.
		 */
		bool getCenterMarkerVisible() const;

	protected:

		/*!
		 * \brief This is a reimplemented method. In this case it draws the grid and other
		 * background elements.
		 *
		 * \param[in] painter The passed painter object.
		 * \param rect The rectangle to be drawn.
		 */
		void drawBackground(QPainter *painter, const QRectF &rect) override;


	private:
		Q_OBJECT

		bool
		visibleCenterMarker,
		visibleGrid;

		QPixmap grid;
		int gridSpace;

		/*!
		 * \brief Initializes all graphic interface.
		 */
		void init();
};
}
#endif // MAPA_H
