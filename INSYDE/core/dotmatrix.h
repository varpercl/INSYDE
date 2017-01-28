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
 * \brief The DotMatrix class represents a graphic view of a binary MxN matrix.
 * This class is useful to see the status of each index of the matrix. Actually
 * this matrix allows only binary information.
 *
 * TODO: should be created a new class to support real values with heat colors
 * or another representation.
 *
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT DotMatrix : public GraphicObject
{

	public:

		/*!
		 * \brief The Dot struct holds information about a particular dot.
		 * The information is the row an col.
		 */
        struct Dot{
            public:
				int
				row, /**< The row of this dot. */
				col; /**< The column of this dot. */

        };

		/*!
		 * \brief The DataFormat enum enlist all possible data formats.
		 *
		 */
		enum DataFormat{
			Unipolar, /**< The values could be or 0 or 1. */
			Bipolar /**< The values could be -1 or 1 */
		};

		/*!
		 * \brief Construct an empty dot matrix.
		 */
		explicit DotMatrix();

		/*!
		 * \brief Construct a \p rows x \p cols matrix with a data format \p dt.
		 * \param rows The rows this matrix will have.
		 * \param cols The columns this matrix will have.
		 * \param dt The current format of the data.
		 */
		explicit DotMatrix(int rows, int cols, const DataFormat &dt = Unipolar);

		/*!
		 * \brief Builds this DotMatrix object with a specified dot size. This allows user to have
		 * different geometries.
		 *
		 * \param dotsize The size of the dots.
		 * \param rows The rows this matrix will have.
		 * \param cols The columns this matrix will have.
		 * \param dt The type of data format. \see DataFormat
		 */
		explicit DotMatrix(int dotsize, int rows, int cols, const DataFormat &dt = Unipolar);

		/*!
		 * \brief A DotMatrix with a determined \p dotList, this means the matrix will have a prebuilt
		 * data information.
		 *
		 * \param dotList The dot list. This is a vector of Dot's objects that have a respective \c row and \c col.
		 * \param dotsize The size of each dot.
		 * \param rows The rows of this DotMatrix.
		 * \param cols The columns of this DotMatrix.
		 * \param dt The data format.
		 */
		explicit DotMatrix(QVector<Dot> *dotList, int dotsize, int rows, int cols, const DataFormat &dt = Unipolar);


		/*!
		 * \brief Gets the number of rows this matrix has.
		 * \return An integer with the number of rows.
		 */
		int getRows() const;

		/*!
		 * \brief Gets the columns of this matrix.
		 * \return An integer with the number of columns.
		 */
		int getCols() const;

		/*!
		 * \brief Returns the total size of this DotMatrix. This is not the rows and columns, but
		 * the width and height of this objects.
		 * \return A QSize object which contains size information.
		 */
		QSizeF getSize() const override;

		/*!
		 * \brief Sets the current inputs in a std::vector. This inputs will be represented
		 * depending on DataFormat choosen.
		 *
		 * \param inputs A std::vector containing all inputs.
		 */
		void setInputs(const vector<double> &inputs);

		/*!
		 * \overload
		 */
		void setInputs(const vector<int> &inputs);

		/*!
		 * \brief This is an overloaded function that not only sets the inputs of this DotMatrix,
		 * but also sets the rows and columns in one step.
		 *
		 * \param inputs A std::vector containing all inputs.
		 * \param rows The rows of this class.
		 * \param cols The columns of this class.
		 */
		void setInputs(const vector<double> &inputs, int rows, int cols);

		/*!
		 * \overload
		 */
		void setInputs(const vector<int> &inputs, int rows, int cols);

		/*!
		 * \overload
		 */
		void setInputs(const QVector<double> &inputs);

		/*!
		 * \overload
		 */
		void setInputs(const QVector<double> &inputs, int rows, int cols);

		/*!
		 * \overload
		 */
		void setInputs(const QVector<int> &inputs);

		/*!
		 * \overload
		 */
		void setInputs(const QVector<int> &inputs, int rows, int cols);

		/*!
		 * \brief This overloaded method allows to set the values of the matrix with a
		 * input \p matrix.
		 *
		 *
		 *
		 * \param matrix The matrix with the data.\note The \p matrix param must be
		 * consistent in dimensions.
		 */
		void setInputs(const vector<vector<int> > &matrix);

		/*!
		 * \overload
		 */
		void setInputs(const QVector<QVector<int> > &matrix);

		/*!
		 * \brief Returns a matrix represented as a QVector of QVectors.
		 *
		 * TODO: implement a std::vector<std::vector<int> > output function.
		 *
		 * \return The data contained in a QVector<QVector<int> > structure.
		 */
		QVector<QVector<int> > getInputs() const;

		/*!
		 * \brief Sets the format of the data.
		 * \param dt The format of the data.
		 *
		 * \see DataFormat
		 */
		void setDataType(const DataFormat &dt);

		/*!
		 * \brief Gets the format of the data.
		 *
		 * \return A DataFormat value.
		 *
		 * \see DataFormat
		 */
		DataFormat getDataType() const;

		/*!
		 * \brief Sets an inputs element connected to this object.
		 * If \p ge param can be null, in that case this object will have no input object connected.
		 *
		 * \param ge The GraphicObject this will be connected.
		 *
		 * \reimp
		 */
		void setInputElement(GraphicObject *ge);

		/*!
		 * \brief Gets the current type of this GraphicObject.
		 *
		 * \return In this case this function will return
		 *
		 * \reimp
		 */
		int type() const;

		/*!
		 * \brief Allows this object to be interactive and editable. This means user can
		 * manually click over any dot and change its status.
		 *
		 * \param value True if this object can be editable.
		 */
		void setEnableEdit(bool value);

		/*!
		 * \brief Gets the "editable" status.
		 *
		 * \return True in case this object is editable.
		 */
		bool getEnableEdit() const;

		/*!
		 * \brief Gets an XML string which contains all information about this object.
		 *
		 * \return A string containing all XML information of this object.
		 *
		 */
		QString getXML() const;

		/*!
		 * \brief Gets the size of each dot.
		 * \return An integer representing the size of each dot in this matrix.
		 */
		int getDotSize() const;

		/*!
		 * \brief Returns the status of the "Continuous Drawing" property.
		 * \return True if Continuous Drawing is enabled.
		 */
		bool getEnableContinuousDrawing() const;

		/*!
		 * \brief Returns the status of the "Eraser Pen" tool.
		 * \return True if the "Eraser Pen" is enabled.
		 */
		bool getEnableEraserPen() const;

		/*!
		 * \brief Sets a new list of dots that will be displayed.
		 *
		 * Dot matrix object works with a dot list. This dot list indicates which dots are ones, the
		 * size of the list can vary depending on how many dots user has set. Maximum size of this list is
		 * \code{getCols() * getRows()}, in that case it is supposed all dots are ones and dot matrix should be shown
		 * completely filled.
		 *
		 * With this method you can set any dot list you want. Passing a pointer ensures data can be changed from diferent
		 * sources and affect different dot matrix, this is useful in case we want to show a dot matrix object in
		 * different windows but representing the same data.
		 *
		 * \param[in] dots
		 */
		void setDotList(QVector<Dot> *dots);

		/*!
		 * \brief Returns the pointer to the current dot list.
		 *
		 * \return A QVector pointer with every pressed dot in this dot matrix.
		 */
		QVector<Dot> *getDotList() const;

		/*!
		 * \brief Returns the matrix size, this differs from size of this object.
		 * \return A QSize containing information about dimension of the matrix.
		 */
		QSize getMatrixSize() const;


	public slots:

		/*!
		 * \brief Enables the Continuous Drawing property. This property allows users to
		 * manipulate each dot as a continuos line. User just need to keep pressed the
		 * left button of the mouse and move over Dot matrix and dots will be set.
		 *
		 * \param b If true the property will be enabled.
		 *
		 */
		void setEnableContinuousDrawing(bool b);

		/*!
		 * \brief Enables the Eraser Pen tool. This tool allows users to erase point by point
		 * just keeping the left button pressed and displaced over the matrix.
		 *
		 * \param b If true Eraser pen will be enabled.
		 */
		void setEnableEraserPen(bool b);

		/*!
		 * \brief Sets the amount of rows of this matrix.
		 *
		 * \param value The amount of rows this matrix will have.
		 *
		 */
		void setRows(int value);

		/*!
		 * \brief Sets the amount of columns of this matrix.
		 * \param value The amount of columns this matrix will have.
		 *
		 */
		void setCols(int value);

		/*!
		 * \brief Sets the size of each dot. Each dot is a rectangle with
		 * width and height equals.
		 *
		 * \param size The size of each dot.
		 */
		void setDotSize(int size);

		/*!
		 * \overload
		 */
		void setMatrixSize(const QSize &size);

		/*!
		 * \brief Sets a particular dot to a high level value \p b.
		 * \param row The row of the dot.
		 * \param col The column of the dot.
		 * \param b The value to be set.
		 */
		void setDot(int row, int col, bool b);

		/*!
		 * \brief Clears the matrix. All dots will be a low level bit.
		 */
		void clear();

		/*!
		 * \brief Fills the current matrix. All dots will be a high level bit.
		 */
		void fill();

	signals:

		/*!
		 * \brief This signal is thrown when the current status of this dot
		 * matrix has changed.
		 *
		 * \param matrix A matrix with all values.
		 */
		void statusChanged(const QVector<QVector<int> > &matrix);

		/*!
		 * \overload
		 */
		void statusChanged(const QVector<int> &inputs);

		/*!
		 * \brief Thrown when an specified \p row has changed.
		 * \param row The row index.
		 */
		void rowCountChanged(int row);

		/*!
		 * \brief Thrown when a column \p col has changed.
		 *
		 * \param col The column index.
		 */
		void colCountChanged(int col);

		/*!
		 * \brief Thrown when the size of the dots has changed.
		 * \param size The new size.
		 */
		void dotSizeChanged(int size);

		/*!
		 * \brief Thrown when matrix dimension has changed.
		 * \param size The new dimension of the matrix.
		 */
		void matrixSizeChanged(const QSize &size);

	protected:

		void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
		void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
		void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
		void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	protected slots:

		void copyClick();
		void cutClick();
		void pasteClick();
		void saveClick();
		void propertyClick();

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

		DataFormat dataType;

		QVector<Dot > *ptsList;

		int
		curRowIndex,
		curColIndex,
		cols,
		rows,
		size;

		QPointF
		objectPosAtPress;

		QRectF
		mouseRect; /**< Rectangulo del tamaño de un cuadro ubicado en la posicion del mouse */

		/*!
		 * \brief Initialize everything in this class.
		 * \param size The size of each dot.
		 * \param rows The amount of rows.
		 * \param cols The amount of cols.
		 * \param dt The DataFormat.
		 *
		 * \see DataFormat enum
		 */
		void init(int size, int rows, int cols, DataFormat dt);

		/*!
		 * \brief This helper function will return a rectangle that is the container
		 * of all dots.
		 *
		 * \return A QRectF object that contains all information of the rectangle.
		 */
		QRectF getContainer() const;

		/*!
		 * \brief Updates all this matrix. This is called when some changes on the data has ocurred.
		 */
		void updateDotList();

		/*!
		 * \brief Tells the user if the current \p rect is over a valid dot.
		 *
		 * \param rect The rectangle to be evaluated.
		 *
		 * \return True in case of \p rect being a valid dot.
		 */
		bool isValidDot(const QRectF &rect);

		/*!
		 * \brief Update the rectangle drawn when the mouse is over a dot.
		 * If the mouse is over a valid dot the color of the rectangle will be green.
		 */
		void updateMouseRectangle(const QPointF &pos);

		/*!
		 * \brief Update the current dot depending on position \p pos.
		 * \param pos The position to be updated.
		 */
		void updateCurRowAndColIndexes(const QPointF &pos);

};

/*!
 * \brief Performs basic compare operation. Determines if both \p dotleft and \p dotright
 * are equals.
 *
 * \param dotleft The left operand.
 * \param dotright The right operand.
 * \return True in case of both are equal.
 *
 */
bool operator ==(const DotMatrix::Dot &dotleft, const DotMatrix::Dot &dotright);
}
#endif // DOTMATRIX_H
