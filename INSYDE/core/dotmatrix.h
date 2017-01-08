#ifndef DOTMATRIX_H
#define DOTMATRIX_H

#include <QGraphicsSceneHoverEvent>

#include <QtCore>

#include "share_core_lib.h"
#include "common.h"
#include "dotmatrixpropertydialog.h"
#include "graphicobject.h"


namespace core{

/*!
 * \class
 *
 * \brief The DotMatrix class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT DotMatrix : public GraphicObject
{
//		struct Dot;

	public:
        struct Dot{
            public:
                int
                row,
                col;

        };

		enum DataType{
			Unipolar,
			Bipolar
		};

		explicit DotMatrix();

		/*!
		 * \brief DotMatrix
		 * \param rows
		 * \param cols
		 * \param dt
		 */
		explicit DotMatrix(int rows, int cols, const DataType &dt = Unipolar);

		/*!
		 * \brief DotMatrix
		 * \param dotsize
		 * \param rows
		 * \param cols
		 * \param dt
		 */
		explicit DotMatrix(int dotsize, int rows, int cols, const DataType &dt = Unipolar);

		/*!
		 * \brief DotMatrix
		 * \param dotList
		 * \param dt
		 */
		explicit DotMatrix(QVector<Dot> *dotList, int dotsize, int rows, int cols, const DataType &dt = Unipolar);


		/*!
		 * \brief getRows
		 * \return
		 */
		int getRows() const;

		/*!
		 * \brief getCols
		 * \return
		 */
		int getCols() const;

		/*!
		 * \brief getSize
		 * \return
		 */
		QSizeF getSize() const override;

		/*!
		 * \brief setInputs
		 * \param inputs
		 */
		void setInputs(const vector<double> &inputs);

		/*!
		 * \brief setInputs
		 * \param inputs
		 * \param rows
		 * \param cols
		 */
		void setInputs(const vector<double> &inputs, int rows, int cols);

		/*!
		 * \brief setInputs
		 * \param inputs
		 */
		void setInputs(const vector<int> &inputs);

		/*!
		 * \brief setInputs
		 * \param inputs
		 * \param rows
		 * \param cols
		 */
		void setInputs(const vector<int> &inputs, int rows, int cols);

		/*!
		 * \brief setInputs
		 * \param inputs
		 */
		void setInputs(const QVector<double> &inputs);

		/*!
		 * \brief setInputs
		 * \param inputs
		 * \param rows
		 * \param cols
		 */
		void setInputs(const QVector<double> &inputs, int rows, int cols);

		/*!
		 * \brief setInputs
		 * \param inputs
		 */
		void setInputs(const QVector<int> &inputs);

		/*!
		 * \brief setInputs
		 * \param inputs
		 * \param rows
		 * \param cols
		 */
		void setInputs(const QVector<int> &inputs, int rows, int cols);

		/*!
		 * \brief setInputs
		 * \param matrix
		 */
		void setInputs(const vector<vector<int> > &matrix);

		/*!
		 * \brief setInputs
		 * \param matrix
		 */
		void setInputs(const QVector<QVector<int> > &matrix);

		/*!
		 * \brief getInputs
		 * \return
		 */
		QVector<QVector<int> > getInputs() const;

		/*!
		 * \brief setDataType
		 * \param dt
		 */
		void setDataType(const DataType &dt);

		/*!
		 * \brief getDataType
		 * \return
		 */
		DataType getDataType() const;

		/*!
		 * \brief setInputElement
		 * \param ge
		 */
		void setInputElement(GraphicObject *ge);

		/*!
		 * \brief Devuelve el tipo de objeto actual. Esta funcion es sumamente util para identificar el tipo de
		 * objeto sin necesidad de hacer casting.
		 *
		 * \return Un numero entero que indica el tipo de elemento.
		 *
		 * \reimp
		 */
		int type() const;

		/*!
		 * \brief getEnableEdit
		 * \return
		 */
		bool getEnableEdit() const;

		/*!
		 * \brief setEnableEdit
		 * \param value
		 */
		void setEnableEdit(bool value);

		/*!
		 * \brief getXML
		 * \return
		 */
		QString getXML() const;

		/*!
		 * \brief getDotSize
		 * \return
		 */
		int getDotSize() const;

		/*!
		 * \brief getEnableContinuousDotsWritting
		 * \return
		 */
		bool getEnableContinuousDrawing() const;

		/*!
		 * \brief getEnableEraserPen
		 * \return
		 */
		bool getEnableEraserPen() const;

		/*!
		 * \brief setDotList Dot matrix object works with a dot list. This dot list indicates which dots are ones, the
		 * size of the list can vary depending on how many dots user has set. Maximum size of this list is
		 * \code{getCols() * getRows()}, in this case it is supposed all dots are ones and dot matrix should be shown
		 * completely filled.
		 *
		 * With this method you can set any dot list you want. Passing a pointer ensures data can be changed from diferent
		 * sources and affect different dot matrix, this is useful in case we want to show a dot matrix object in
		 * different windows but representing the same data.
		 *
		 * \param dots
		 */
		void setDotList(QVector<Dot> *dots);

		/*!
		 * \brief getDotList
		 * \return
		 */
		QVector<Dot> *getDotList() const;

		/*!
		 * \brief getMatrixSize
		 * \return
		 */
		QSize getMatrixSize() const;


	public slots:

		/*!
		 * \brief setEnableContinuousDotsWritting
		 * \param b
		 */
		void setEnableContinuousDrawing(bool b);

		/*!
		 * \brief setEnableEraserPen
		 * \param b
		 */
		void setEnableEraserPen(bool b);

		/*!
		 * \brief setRows
		 * \param value
		 */
		void setRows(int value);

		/*!
		 * \brief setCols
		 * \param value
		 */
		void setCols(int value);

		/*!
		 * \brief setDotSize
		 * \param size
		 */
		void setDotSize(int size);

		/*!
		 * \brief setSize
		 * \param dotSize
		 */
		void setMatrixSize(const QSize &size);

	signals:

		/*!
		 * \brief statusChanged
		 * \param matrix
		 */
		void statusChanged(const QVector<QVector<int> > &matrix);

		/*!
		 * \brief statusChanged
		 * \param inputs
		 */
		void statusChanged(const QVector<int> &inputs);

		/*!
		 * \brief rowCountChanged
		 * \param value
		 */
		void rowCountChanged(int value);

		/*!
		 * \brief colCountChanged
		 * \param value
		 */
		void colCountChanged(int value);

		/*!
		 * \brief dotSizeChanged
		 * \param value
		 */
		void dotSizeChanged(int value);

		/*!
		 * \brief sizeChanged
		 * \param size
		 */
		void matrixSizeChanged(const QSize &size);

	protected:

		void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

		/*!
		 * \brief mouseReleaseEvent
		 * \param event
		 */
		void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

		/*!
		 * \brief mouseMoveEvent
		 * \param event
		 */
		void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

		/*!
		 * \brief hoverMoveEvent
		 * \param event
		 */
		void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;

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
		 * \brief saveClick
		 */
		void saveClick();

		/*!
		 * \brief propertyClick
		 */
		void propertyClick();

	private slots:

		/*!
		 * \brief onClearClicked
		 * \param checked
		 */
		void onClearClicked(bool checked);

		/*!
		 * \brief onFillClicked
		 * \param checked
		 */
		void onFillClicked(bool checked);



	private:
		Q_OBJECT



		QAction
		*continuousDrawingAction,
		*clearAction,
		*fillAction,
		*eraserAction;

		bool
		enableEdit,
		enableContinuousDrawing,
		enableEraser;

		DataType dataType;

		QVector<Dot > *ptsList;

		int
		curRowIndex,
		curColIndex,
		cols,
		rows,
		size; // Size of each dot

		QPointF
		objectPosAtPress;

		QRectF
		mouseRect; /**< Rectangulo del tamaño de un cuadro ubicado en la posicion del mouse */

		/*!
		 * \brief init
		 * \param dotSize
		 * \param rows
		 * \param cols
		 * \param dt
		 */
		void init(int size, int rows, int cols, DataType dt);

		/*!
		 * \brief getContainer
		 * \return
		 */
		QRectF getContainer() const;

		/*!
		 * \brief updateDotList
		 */
		void updateDotList();

		/*!
		 * \brief isValidDot
		 * \param rect
		 * \return
		 */
		bool isValidDot(const QRectF &rect);

		/*!
		 * \brief setDot
		 * \param row
		 * \param col
		 * \param b
		 */
		void setDot(int row, int col, bool b);

		/*!
		 * \brief updateMouseRectangle
		 */
		void updateMouseRectangle(const QPointF &pos);

		/*!
		 * \brief updateCurRowAndColIndexes
		 * \param pos
		 */
		void updateCurRowAndColIndexes(const QPointF &pos);

};

bool operator ==(const DotMatrix::Dot &dotleft, const DotMatrix::Dot &dotright);
}
#endif // DOTMATRIX_H
