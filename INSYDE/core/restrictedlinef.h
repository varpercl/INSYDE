#ifndef RESTRICTEDPOINTF_H
#define RESTRICTEDPOINTF_H

#include <QtCore>

#include "share_core_lib.h"

class CORE_LIB_IMPORT_EXPORT RestrictedLineF : public QLineF
{
	public:
		
		enum Constrain{
			Horizontal = Qt::Horizontal,
			Vertical = Qt::Vertical,
			HorizontalLeft,
			HorizontalRight,
			VerticalUp,
			VerticalDown,
			Both,
			None
		};
		
		explicit RestrictedLineF();
		
		explicit RestrictedLineF(const QPointF & p1, const QPointF & p2, Constrain lc = None);

		explicit RestrictedLineF(qreal x1, qreal y1, qreal x2, qreal y2, Constrain lc = None);
				
		~RestrictedLineF();
		
		void setConstrain(Constrain lc);
		
		Constrain getConstrain() const;
		
		void setP1(const QPointF &p1);
		
		void setP2(const QPointF &p2);

		/*!
		 * \brief getCorrectedP2 Returns a corrected point P2 (in case of apply).
		 * A corrected point is obtained when some restriction apply to this line.
		 * If you input some point that is not inside restriction range then it will be processed.
		 *
		 * This function is useful when user want to check a point before set it.
		 *
		 * Note: correction ONLY apply over P2 because you must remember P1 is the start point of
		 * the line so it's not anchored to anything.
		 *
		 * \param p2 An optative point the user want to get corrected.
		 * \return
		 */
		QPointF getCorrectedP2(const QPointF &p2);

		void setPoints(const QPointF &p1, const QPointF &p2);

		bool isHorizontal() const;

		bool isVertical() const;

//		RestrictedLineF &operator=(const RestrictedLineF &rl);

	private:
		
		Constrain lineConstrain;

};

#endif // RESTRICTEDPOINTF_H
