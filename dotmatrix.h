#ifndef DOTMATRIX_H
#define DOTMATRIX_H

#include <QtCore>

#include <dotmatrixelementpropertydialog.h>
#include <graphicelement.h>
#include <graphicmlpelement.h>


class DotMatrix : public GraphicElement
{
	public:
		enum {DotMatrixType = UserType + 3};

		enum DataType{
			Unipolar,
			Bipolar
		};

		explicit DotMatrix(int dotSize, int rows, int cols, DataType dt = Unipolar);

		void setDotMatrix(const QVector<QVector<int> > &matrix);
		QVector<QVector<int> > getDotMatrix();

		void setDotList(const QVector<int> &list);
		void setDotList(const QVector<int> &list, int rows, int cols);

		void setDotList(const QVector<double> &list);
		void setDotList(const QVector<double> &list, int rows, int cols);

		QVector<int> getDotList();

		void setDataType(const DataType &dt);
		DataType getDataType();

		void setInputElement(GraphicElement *ge);

		int type() const;
	signals:

		void statusChanged(QVector<QVector<int> > matrix);
		void statusChanged(QVector<int> matrix);

	protected:

		void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
//		void mousePressEvent(QGraphicsSceneMouseEvent *event);
		void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
		//        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	protected slots:

		void onPropertyClick();
		void onOpenClick();

	private:
		Q_OBJECT

		DataType dataType;
		int curYIndex, curXIndex;
		QVector<QPoint> ptsList;
		int cols, rows;
		int size;
		QRectF container, mouseRect;

		void initDM(int dotSize, int rows, int cols, DataType dt);

	private slots:
		void onMLPOutputChanged(QVector<double> inputs);
};

#endif // DOTMATRIX_H
