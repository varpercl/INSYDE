#ifndef GRAPHICELEMENT_H
#define GRAPHICELEMENT_H

#include <QtWidgets>

#include "share_core_lib.h"
#include "interfaces.h"
#include "common.h"
#include "definitions.h"
#include "simulation.h"
#include "imath.h"


namespace core{

class Simulation;

/*!
 * \class GraphicObject esta clase es la base para todos los objetos que necesitan ser representado en un sistema.
 *
 * Se encarga de dibujar un marco con los contactos necesarios para conectar dos o mas Objetos.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT GraphicObject : public QGraphicsObject, public ClipboardInterface, public ResizableF
{
	public:
		enum GraphicObjectTypes{
			gotGraphicObject,
			gotADALINE,
			gotMLP,
			gotHopfield,
			gotKohonen,
			gotImage,
			gotImageEffect,
			gotDotMatrix,
			gotRegion,
			gotAgent,
			gotGraphicPointer,
			gotConnector
		};

		enum Port{
			portNone,
			portTop,
			portBottom,
			portLeft,
			portRight
		};

		/*!
		 * Construye un objeto GraphicElement con un tamaño de 50x50 pixeles y un borde de dos pixeles
		 */
		explicit GraphicObject();

		/**
		  Construye un objeto con las dimensiones especificadas por @code{rect}

		  @param const QRectF &rect - Rectangulo que contiene las dimensiones del objeto grafico
		  @param int borde - Ancho del borde
		  */
		explicit GraphicObject(const QRectF &rect, int border = 2);

		/**
		  Destructor de la clase
		  */
		~GraphicObject();

		/*!
		 * \brief setContainerRect Stablish current dimension of an graphic object.
		 * Notice that this is the current area where an object is drawed, this doesn't encloses all QGraphicObject rect.
		 *
		 * This method must be called explicitly when graphic object dimension has changed
		 *
		 * \brief setRectangle Establece la dimension del objeto grafico
		 * \param rect Rectangulo con la dimension del objeto grafico
		 */
		virtual void setContainerRect(const QRectF &rect);

		/*!
		 * \brief getContainerRect Return current graphic object dimension
		 * \param rect Rectangulo con la dimension del objeto grafico
		 */
		virtual void setContainerRect(const QRect &rect);

		/*!
		 * \brief getRectangle Devuelve la dimension del objeto grafico
		 * \return Rectangulo que contiene la dimension del objeto grafico
		 */
		virtual QRectF getContainerRect() const;

		/*!
		 * \brief setInputs
		 * \param vec
		 */
		virtual void setInputs(const vector<double> &vec);

		/*!
		 * \brief getInputs
		 * \return
		 */
		vector<double> getInputs() const;

		/*!
		 * \brief getInputsSize
		 * \return
		 */
		int getInputsSize() const;

		/*!
		 * \brief setInputElement Asigna el elemento que proporcionara el valor de entrada para este objeto grafico.
		 * Esta funcion es virtual pura ya que depende del comportamiento de cada uno de los objetos que hereden de
		 * esta clase base.
		 *
		 * \param ge
		 */
		virtual void setInputElement(GraphicObject *ge);

		/*!
		 * \brief getInputElement Obtiene el elemento actual al que esta conectado en la entrada.
		 * En caso de que este elemento no tenga ningun otro elemento conectado a el en su entrada devolvera \code{NULL}
		 *
		 * \return Puntero al elemento conectado actualmente en la entrada.
		 */
		virtual GraphicObject* getInputElement() const;

		/**
		 * @brief setOutputElement Conecta este elemento grafico con un elemento al cual se le asignara la salida de este.
		 * @param ge Elemento grafico al cual sera conectado
		 */
		virtual void setOutputElement(GraphicObject *ge);

		/*!
		 * \brief getOutputElement Obtiene el elemento actual al que esta conectado en la salida.
		 * En caso de que este elemento no tenga ningun otro elemento conectado a el en su salida devolvera \code{NULL}
		 *
		 * \return Puntero al elemento conectado actualmente en la salida.
		 */
		virtual GraphicObject* getOutputElement() const;

		/*!
		 * \brief type
		 *
		 * \return
		 *
		 * \reimp
		 *
		 * \see QAbstractItem::type()
		 */
		int type() const;

		/*!
		 * \brief getBorder
		 * \return
		 */
		QPen getBorder() const;

		/*!
		 * \brief setBorder
		 * \param pen
		 */
		void setBorder(const QPen &pen);

		/*!
		 * \brief boundingRect
		 * \return Rectangulo del objeto grafico
		 *
		 * \reimp
		 */
		QRectF boundingRect() const;

		/*!
		 * \brief getOpenAction
		 * \return
		 */
		QAction *getOpenAction() const;

		/*!
		 * \brief getSaveAction
		 * \return
		 */
		QAction *getSaveAction() const;

		/*!
		 * \brief getRemoveAction
		 * \return
		 */
		QAction *getRemoveAction() const;

		/*!
		 * \brief getPropertiesAction
		 * \return
		 */
		QAction *getPropertiesAction() const;

		/*!
		 * \brief getXML Devuelve una transformacion de este objeto a un formato XML que es necesario para operaciones
		 * basicas como almacenarlo en el portapapeles o guardarlo en un disco duro.
		 *
		 * TODO: documentar bien el formato
		 *
		 * \return
		 */
		virtual QString getXML() const = 0;

		/*!
		 * \brief getObjectLocked
		 * \return
		 */
		bool getObjectLocked() const;

		/*!
		 * \brief setSimulation
		 * \param sim
		 */
		void setSimulation(Simulation *sim);

		/*!
		 * \brief getSimulation
		 * \return
		 */
		Simulation *getSimulation() const;

		/*!
		 * \brief getLockAction
		 * \return
		 */
		QAction *getLockAction() const;

		/*!
		 * \brief getCurrentPort Returns current port depending on current mouse position, if no port is hovered it will
		 * return \code{portNone}
		 * \return
		 */
		Port getCurrentPort();

		/*!
		 * \brief getCurrentPort
		 * \param pos A position which you want to check if inside a port. This position is in scene coordinates.
		 * \return
		 */
		Port getCurrentPort(const QPoint &pos);

		/*!
		 * \brief getCurrentPort
		 * \param pos
		 * \return
		 */
		Port getCurrentPort(const QPointF &pos);

		/*!
		 * \brief getCurrentPortRect Returns current port point depending on current mouse position, if no port is
		 * hovered it will return center of the container rectangle which it could be considered an invalid port point.
		 *
		 * \return
		 */
		QPointF getCurrentPortPos();

		/*!
		 * \brief getCurrentPortRect
		 * \param pos
		 * \return
		 */
		QPointF getCurrentPortPos(const QPointF &pos);

		/*!
		 * \brief getCurrentPortRect
		 * \param pos
		 * \return
		 */
		QPointF getCurrentPortPos(const QPoint &pos);

		/*!
		 * \brief setSize
		 * \param size
		 */
		void setSize(const QSizeF &size) override;

		/*!
		 * \brief getSize
		 * \return
		 */
		QSizeF getSize() const override;

		/*!
		 * \brief setWidth
		 * \param w
		 */
		void setWidth(double w) override;

		/*!
		 * \brief getWidth
		 * \return
		 */
		double getWidth() const override;

		/*!
		 * \brief setHeight
		 * \param h
		 */
		void setHeight(double h) override;

		/*!
		 * \brief getHeight
		 * \return
		 */
		double getHeight() const override;

		/*!
		 * \brief setResizeRectSize Sets the size of the resizing rectangles of this object
		 * \param size
		 */
		void setResizeRectSize(double size);

		/*!
		 * \brief setPortSensitivity
		 * \param sensitivity
		 */
		void setPortSensitivity(double sensitivity);

	public slots:

		/*!
		 * \brief setInputsSize
		 * \param size
		 */
		void setInputsSize(int size);

		/*!
		 * \brief setObjectLocked
		 * \param locked
		 */
		void setObjectLocked(bool locked);

	signals:

		/*!
		 * \brief openOnWindowRequest
		 * \param obj
		 */
		void openOnWindowRequest(GraphicObject *obj);

		/*!
		 * \brief objectRemoved
		 * \param obj
		 */
		void objectRemoved(GraphicObject *obj);

		/*!
		  * \brief inputsSizeChanged
		  * \param size
		  */
		void inputsSizeChanged(int size);

	protected:

		QPointF currentMousePos;

		//Elemento de entrada
		GraphicObject
		*inputElement,

		//Elemento de salida
		*outputElement;

		//Entrada actual del objeto para cualquier representacion grafica
		vector<double> inputs;

		//Lista de acciones
		QAction
		*openAction,
		*saveAction,
		*lockAction,
		*removeAction,
		*propertiesAction;

		//Menu contextual
		QMenu contextMenu;

		/*!
		 * \brief contextMenuEvent
		 * \param event
		 */
		void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

		/*!
		 * \brief shape
		 * \return
		 */
//		QPainterPath shape() const override;

		/*!
		 * \brief paint Dibuja un marco que representa un objeto vacio dentro de un sistema.
		 * Este metodo es base para todo objeto que implemente esta clase (debe llamarse \code{GraphicElement::paint()})
		 *
		 * \param painter Objeto para dibujar los graficos
		 * \param option Condiciones actuales del objeto que se pintara
		 * \param widget
		 */
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

		/*!
		 * \brief hoverMoveEvent
		 * \param event
		 */
		void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;

		/*!
		 * \brief nearPort
		 * \param sensitivity
		 * \return
		 */
		bool nearPort(Port reference) const;

		bool nearPort(const QPointF &pos, Port reference) const;

	protected slots:

		/*!
		 * \brief copyClick
		 */
		virtual void copyClick(){}

		/*!
		 * \brief cutClick
		 */
		virtual void cutClick(){}

		/*!
		 * \brief pasteClick
		 */
		virtual void pasteClick(){}

		/*!
		 * \fn
		 *
		 * \brief propertyClick es llamada cuando se hace click en el elemento "Propiedades" del menu contextual
		 */
		virtual void propertyClick(){}

		/*!
		 * \fn
		 *
		 * \brief deleteClickes llamada cuando se hace click en el elemento "Eliminar" del menu contextual
		 */
		virtual void removeClick();

		/*!
		 * \fn
		 *
		 * \brief saveClick Determina el comportamiento del objeto cuando el usuario hace click en el elemento de menu
		 * Guardar...
		 *
		 */
		virtual void saveClick(){}

		/*!
		 * \brief openOnWindowClick Throwed when user clicks on "Open on new windows" context menu item. It's important to know
		 * this emits \code{openOnWindowRequest()} signal which allow this object to request parent to open a new window
		 * with a \code{GraphicObject} inside.
		 *
		 * Reimplementing this function requires to recall this parent method, other case it couldn't open a new window
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

		//Ancho de borde del objeto
		QPen border;

		double
		resizeRectSize,
		portSensitivity;

		int
		inputsSize; //Contiene el numero de entradas que tendra este objeto en caso de que no este conectado a ningun objeto en su entrada

		//Rectangulo que contiene las dimensiones de este objeto grafico
		QRectF
		containerRect,
		topLeftResizeRect,
		topCenterResizeRect,
		topRightResizeRect,
		bottomLeftResizeRect,
		bottomCenterResizeRect,
		bottomRightResizeRect,
		leftCenterResizeRect,
		rightCenterResizeRect;

		bool
		objectLocked;

		/*!
		 * \brief init Inicializa el objeto constructor con una dimension @code{rect} y un ancho de borde @code{border}
		 * \param rect Rectangulo que contiene las dimensiones del objeto grafico
		 * \param border Ancho del borde de este objeto grafico
		 */
		void init(const QRectF &rect, int border);

};
}
#endif // GRAPHICELEMENT_H
