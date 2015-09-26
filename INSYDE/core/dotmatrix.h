#ifndef DOTMATRIX_H
#define DOTMATRIX_H

#include <QGraphicsSceneHoverEvent>

#include <QtCore>

#include "common.h"
#include "dotmatrixpropertydialog.h"
#include "graphicobject.h"
#include "../ann_gui/graphicmlpelement.h"
#include "interfaces.h"

/*!
 * \class
 *
 * \brief The DotMatrix class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT DotMatrix : public GraphicObject, public Resizable
{
	public:

		enum {DotMatrixObject = UserType + 3};

		enum DataType{
			Unipolar,
			Bipolar
		};

		/*!
		 * \brief DotMatrix
		 * \param rows
		 * \param cols
		 * \param dt
		 */
		explicit DotMatrix(int rows, int cols, const DataType &dt = Unipolar);

		/*!
		 * \brief DotMatrix
		 * \param dotSize
		 * \param rows
		 * \param cols
		 * \param dt
		 */
		explicit DotMatrix(int dotSize, int rows, int cols, const DataType &dt = Unipolar);

		/*!
		 * \brief setRows
		 * \param value
		 */
		void setRows(int value);

		/*!
		 * \brief getRows
		 * \return
		 */
		int getRows() const;

		/*!
		 * \brief setCols
		 * \param value
		 */
		void setCols(int value);

		/*!
		 * \brief getCols
		 * \return
		 */
		int getCols() const;

		/*!
		 * \brief setSize
		 * \param dotSize
		 */
		void setSize(const QSize &dotSize);

		/*!
		 * \brief getSize
		 * \return
		 */
		QSize getSize() const;

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
		 * \brief setWidth Funcion identica a setCols
		 * \param w Numero de columnas que tendra el objeto
		 */
		void setWidth(int w);

		/*!
		 * \brief getWidth Funcion identica a getCols
		 * \return
		 */
		int getWidth() const;

		/*!
		 * \brief setHeight Funcion identica a setRows
		 * \param h Numero de filas que tendra el objeto
		 */
		void setHeight(int h);

		/*!
		 * \brief getHeight Funcion identica a getRows
		 * \return
		 */
		int getHeight() const;

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

	protected:

		//TODO: evaluar si es necesaria la implementacion de estos metodos ya que pueden ser ambiguos e innecesarios
		//es mas conveniente el uso de setDotMatrix

		void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
		void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
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
		 * \brief onMLPOutputChanged
		 * \param inputs
		 */
		void onMLPOutputChanged(QVector<double> inputs);

	private:
		Q_OBJECT

		bool enableEdit;

		DataType dataType;

		QList<QPoint> ptsList;

		int
		curYIndex,
		curXIndex,
		cols,
		rows,
		dotSize;

		QRectF
		mouseRect; /**< Rectangulo del tamaño de un cuadro ubicado en la posicion del mouse */

		/*!
		 * \brief init
		 * \param dotSize
		 * \param rows
		 * \param cols
		 * \param dt
		 */
		void init(int dotSize, int rows, int cols, DataType dt);

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

};

#endif // DOTMATRIX_H
