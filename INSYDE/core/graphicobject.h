#ifndef GRAPHICELEMENT_H
#define GRAPHICELEMENT_H

#include <QtWidgets>

#include "share_core_lib.h"
#include "undo.h"
#include "common.h"
#include "definitions.h"
#include "simulation.h"
#include "imath.h"
#include "iresizablef.h"
#include "clipboard.h"


namespace core{

class Simulation;

/*!
 * \brief The GraphicObject class is the base class for any object added to an enviroment or system.
 * This class has all basic methods and functions to make basic operations like cut, copy, paste, and manipulate
 * as an abstract object.
 *
 * A GraphicObject basicly consist of a rectangle with dots in the corners and sides to manipulate it. Anything
 * could be drawn inside this rectangle.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT GraphicObject : public QGraphicsObject, public Clipboard, public IResizableF
{
	public:

		/*!
		 * \brief The GraphicObjectTypes enum the list of current available objects.
		 */
		enum GraphicObjectTypes{
			gotGraphicObject, /**< An abstract graphic object. */
			gotADALINE, /**< An ADALINE network object. */
			gotMLP, /**< A MLP network graphic object. */
			gotHopfield, /**< A Hopfield network graphic object. */
			gotKohonen, /**< A Kohonen graphic object. */
			gotImage, /**< An Image graphic object. */
			gotImageEffect, /**< An Image effect graphic object. */
			gotDotMatrix, /**< A dot matrix graphic object. */
			gotRegion, /**< A region graphic object. */
			gotAgent, /**< An Agent graphic object. */
			gotGraphicPointer, /**< An Pointer graphic object. */
			gotConnector /**< An connector graphic object. */
		};

		/*!
		 * \brief The Port enum enlist the kind of connection ports.
		 */
		enum Port{
			portNone,
			portTop,
			portBottom,
			portLeft,
			portRight
		};

		/*!
		 * \brief An basic empty graphic object.
		 */
		explicit GraphicObject();

		/**
		  Construye un objeto con las dimensiones especificadas por @code{rect}

		  @param const QRectF &rect - Rectangulo que contiene las dimensiones del objeto grafico
		  @param int borde - Ancho del borde
		  */
		/*!
		 * \brief Builds a graphic object with an specified \p rect dimensions.
		 * \param rect The rect which represents the dimentions of this graphic object.
		 * \param border The border width.
		 */
		explicit GraphicObject(const QRectF &rect, int border = 2);

		~GraphicObject();

		/*!
		 * \brief Establish current dimension of an graphic object.
		 * Notice that this is the current area where an object is drawed, this doesn't encloses all QGraphicObject rect.
		 *
		 * This method must be called explicitly when graphic object dimension has changed
		 *
		 * \brief setRectangle Establece la dimension del objeto grafico
		 * \param rect Rectangulo con la dimension del objeto grafico
		 */
		virtual void setContainerRect(const QRectF &rect);

		/*!
		 * \brief Gets the current graphic object valid region.
		 * \param rect The current rectangle which represents the valid region.
		 *
		 */
		virtual void setContainerRect(const QRect &rect);

		/*!
		 * \brief Gets the current region of this object.
		 *
		 * \return A rectangle that represents the current valid region.
		 */
		virtual QRectF getContainerRect() const;

		/*!
		 * \brief Establish the inputs of this object.
		 * \param vec A vector with double values which are the inputs of this graphic object.
		 */
		virtual void setInputs(const vector<double> &vec);

		/*!
		 * \brief Gets the current inputs of this object.
		 * \return A vector with all inputs.
		 */
		vector<double> getInputs() const;

		/*!
		 * \brief Gets the inputs size.
		 * \return An integer with the input size.
		 */
		int getInputsSize() const;

		/*!
		 * \brief Establish a connection with another object which will be an input element.
		 *
		 * TODO: Validate the correctness of this method.
		 *
		 * \param[in] ge The current input graphic object.
		 */
		virtual void setInputElement(GraphicObject *ge);

		/*!
		 * \brief Gets the current associated input graphic object.
		 *
		 * \return A Pointer to the input graphic object.
		 */
		virtual GraphicObject* getInputElement() const;

		/**
		 * @brief setOutputElement Conecta este elemento grafico con un elemento al cual se le asignara la salida de este.
		 * @param ge Elemento grafico al cual sera conectado
		 */

		/*!
		 * \brief Establish \p ge as an linked output object.
		 *
		 * \param[in] ge The associated output object.
		 */
		virtual void setOutputElement(GraphicObject *ge);

		/*!
		 * \brief Gets the associated output element.
		 *
		 * \return A pointer to the output object.
		 */
		virtual GraphicObject* getOutputElement() const;

		/*!
		 * \brief The type of the object.
		 *
		 * \return An integer value that represents the type of the object.
		 *
		 * \see QAbstractItem::type()
		 */
		int type() const;

		/*!
		 * \brief Returns the current border of this graphic object.
		 * \return A QPen object which has all pen properties.
		 */
		QPen getBorder() const;

		/*!
		 * \brief Sets the current \p pen border.
		 * \param pen The associated pen to be setted.
		 *
		 */
		void setBorder(const QPen &pen);

		/*!
		 * \see QGraphicsItem::boundingRect
		 */
		QRectF boundingRect() const override;

		/*!
		 * \brief Gets the "Open" action.
		 * This action is located at the context menu when user clicks.
		 *
		 * \return The associated pointer to the action.
		 */
		QAction *getOpenAction() const;

		/*!
		 * \brief Gets the "Save" action.
		 * This is available at the context menu.
		 * \return A pointer to the respective QAction.
		 */
		QAction *getSaveAction() const;

		/*!
		 * \brief Gets the "Remove" action.
		 * This is available at the context menu.
		 * \return A pointer to the respective QAction.
		 */
		QAction *getRemoveAction() const;

		/*!
		 * \brief Gets the "Properties" action.
		 * This is available at the context menu.
		 * \return A pointer to the respective QAction.
		 */
		QAction *getPropertiesAction() const;

		/*!
		 * \brief Gets an XML string which contains all information about this object.
		 *
		 * TODO: Format must be designed up.
		 *
		 * \return A string containing all information of the current object.
		 */
		virtual QString getXML() const = 0;

		/*!
		 * \brief Gets the current status of the "locked" property of this object.
		 * \return True in case this object is locked.
		 */
		bool getObjectLocked() const;

		/*!
		 * \brief Sets a new simulation.
		 *
		 * \note User is responsible for managing hangling pointers.
		 *
		 * \param[in] sim The new simulation.
		 */
		void setSimulation(Simulation *sim);

		/*!
		 * \brief Returns the current simulation object.
		 * \return The pointer to the current simulation object.
		 */
		Simulation *getSimulation() const;

		/*!
		 * \brief Gets the "Locked" action.
		 * \return A pointer to the respective QAction.
		 */
		QAction *getLockAction() const;

		/*!
		 * \brief Returns current port depending on current mouse position, if no port is hovered it will
		 * return \c Port::portNone
		 * \return A Port type which is the closest port the mouse is.
		 */
		Port getCurrentPort();

		/*!
		 * \brief Returns the current position of the nearest port to \p pos.
		 * \note Notice in this function you have to specify the respective position \p pos.
		 *
		 * \param pos A position which you want to check if near a port. This position is in scene coordinates.
		 * \return
		 */
		Port getCurrentPort(const QPoint &pos);

		/*!
		 * \overload
		 */
		Port getCurrentPort(const QPointF &pos);

		/*!
		 * \brief Returns current port coordinate depending on current mouse position, if no port is
		 * hovered it will return center of the container rectangle which it could be considered an invalid port point.
		 *
		 * \return The current coordinates of the port.
		 */
		QPointF getCurrentPortPos();

		/*!
		 * \brief Returns the rectangle which encloses the current port neares to \p pos.
		 * \param pos The position to be evaluated.
		 *
		 * \return The rectangle which encloses the current port near to \p pos.
		 */
		QPointF getCurrentPortPos(const QPointF &pos);

		/*!
		 * \overload
		 */
		QPointF getCurrentPortPos(const QPoint &pos);

		/*!
		 * \brief Sets the size of this object.
		 * \param size The new size.
		 */
		void setSize(const QSizeF &size) override;

		/*!
		 * \brief Returns the size of this object.
		 * \return The size of this object.
		 *
		 * \see setWidth
		 */
		QSizeF getSize() const override;

		/*!
		 * \brief Sets the width of this object.
		 * \param w The new width.
		 */
		void setWidth(double w) override;

		/*!
		 * \brief Gets the current width of this object.
		 * \return A double value which is the width of this object.
		 */
		double getWidth() const override;

		/*!
		 * \brief Sets the height of this object.
		 * \param h The new height of this object.
		 */
		void setHeight(double h) override;

		/*!
		 * \brief Gets the current height of this object.
		 * \return A double value which is the height of this object.
		 */
		double getHeight() const override;

		/*!
		 * \brief Sets the size of the resizing rectangles of this object
		 * \param size The new size of the resize rectangles.
		 */
		void setResizeRectSize(double size);

		/*!
		 * \brief Establish the port sensitivity o clearance. This is, the minimum
		 * allowable distance to activate the nearest port.
		 *
		 * \param sensitivity The sensitivity for each port.
		 */
		void setPortSensitivity(double sensitivity);

	public slots:

		/*!
		 * \brief Sets the size of the input.
		 * \param size The new size.
		 */
		void setInputsSize(int size);

		/*!
		 * \brief Locks this object for edit or move options.
		 * \param locked True indicates this object is locked.
		 */
		void setObjectLocked(bool locked);

	signals:

		/*!
		 * \brief The signal is thrown when user clicks on the "Open on window" action.
		 * \param obj The object to be shown.
		 */
		void openOnWindowRequest(GraphicObject *obj);

		/*!
		 * \brief Thrown when \p obj is removed.
		 * \param obj The removed object.
		 */
		void objectRemoved(GraphicObject *obj);

		/*!
		  * \brief Thrown when the size of the input has been changed.
		  * \param size The new size.
		  */
		void inputsSizeChanged(int size);

	protected:

		QPointF currentMousePos;

		//Input element
		GraphicObject
		*inputElement,

		//Output element
		*outputElement;

		//current inputs
		vector<double> inputs;

		//current actions
		QAction
		*openAction,
		*saveAction,
		*lockAction,
		*removeAction,
		*propertiesAction;

		//Menu contextual
		QMenu contextMenu;

		//Overrided
		void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
		void mouseMoveEvent(QGraphicsSceneMouseEvent *e) override;
		void mousePressEvent(QGraphicsSceneMouseEvent *e) override;
		void mouseReleaseEvent(QGraphicsSceneMouseEvent *e) override;

		/*!
		 * \brief shape
		 * \return
		 */
//		QPainterPath shape() const override;

		/*!
		 * \see QGraphicsItem::paint
		 */
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

		/*!
		 * \see QGraphicsItem::hoverMoveEvent
		 */
		void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;

		/*!
		 * \brief Determines if the cursor is near to \p reference port.
		 *
		 * \param reference The referenced port.
		 *
		 * \return True in case the cursor is near.
		 */
		bool nearPort(Port reference) const;

		/*!
		 * \brief Determines if \p pos is near to \p reference port.
		 *
		 * \param pos The pos to be evaluated.
		 * \param reference The referenced port.
		 *
		 * \return True in case \p pos is near to \p reference port.
		 */
		bool nearPort(const QPointF &pos, Port reference) const;

	protected slots:

		/*!
		 * \see Clipboard::copyClick
		 */
		virtual void copyClick(){}

		/*!
		 * \see Clipboard::cutClick
		 */
		virtual void cutClick(){}

		/*!
		 * \see Clipboard::pasteClick
		 */
		virtual void pasteClick(){}

		/*!
		 * \brief Called when an user performs clicks over properties context menu action.
		 */
		virtual void propertyClick(){}

		/*!
		 * \brief Called when user clicks over "Remove" action on the context menu.
		 */
		virtual void removeClick();

		/*!
		 * \brief Called when user clicks over "Save" action on the context menu.
		 */
		virtual void saveClick(){}

		/*!
		 * \brief Thrown when user clicks on "Open on windows" context menu item. It's important to know
		 * this emits openOnWindowRequest signal which allow this object to request parent to open a new window
		 * with a GraphicObject inside.
		 *
		 * \warning Reimplementing this function requires to recall this parent method, other case it couldn't open a new window.
		 */
		virtual void openOnWindowClick();

	private slots:

		/*!
		 * \brief onLockObjectClicked This slot is used for private purpouses only, it's called when user triggered
		 * lock action on context menu. At the same time this throw lockObjectClick(bool) signal, which indicates if
		 * object is locked or not (current status of the action)
		 */
//		void onLockObjectTriggered();

	private:

		Q_OBJECT


		Simulation *simulation;

		//Current border of this object.
		QPen border;

		double
		resizeRectSize,
		portSensitivity;

		int
		inputsSize; //Contiene el numero de entradas que tendra este objeto en caso de que no este conectado a ningun objeto en su entrada


		QRectF
		containerRect, /**< Rectangulo que contiene las dimensiones de este objeto grafico */
		topLeftResizeRect,
		topCenterResizeRect,
		topRightResizeRect,
		bottomLeftResizeRect,
		bottomCenterResizeRect,
		bottomRightResizeRect,
		leftCenterResizeRect,
		rightCenterResizeRect;

		bool
		objectLocked,
		dragging;

		/*!
		 * \brief Initializes all graphic interface.
		 * \param rect The rectangle which represents the valid region of this object.
		 * \param borderwidth The border width.
		 */
		void init(const QRectF &rect, int borderwidth);

};
}
#endif // GRAPHICELEMENT_H
