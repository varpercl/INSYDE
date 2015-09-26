#ifndef GRAPHICELEMENT_H
#define GRAPHICELEMENT_H

#include <QtWidgets>

#include "interfaces.h"
#include "common.h"
#include "icons.h"

/*!
 * \class GraphicElement esta clase es la base para todos los objetos que necesitan ser representado en un sistema.
 *
 * Se encarga de dibujar un marco con los contactos necesarios para conectar dos o mas Objetos.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT GraphicObject : public QGraphicsObject, public ClipboardInterface
{
	public:

		/*!
		 * Tipo de elemento grafico
		 */
		enum {GraphicElementType = UserType + 1};

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
		 * \brief setRectangle Establece la dimension del objeto grafico
		 * \param rect Rectangulo con la dimension del objeto grafico
		 */
		virtual void setContainerRect(const QRectF &rect);

		/*!
		 * \brief setRectangle Establece la dimension del objeto grafico
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
		 * \brief setInputsSize
		 * \param size
		 */
		void setInputsSize(int size);

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
		virtual void setInputElement(GraphicObject *ge) = 0;

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

	protected:

		//Elemento de entrada
		GraphicObject
		*inputElement,

		//Elemento de salida
		*outputElement;

		//Lista de acciones
		QAction
		*openAction,
		*saveAction,
		*removeAction,
		*propertiesAction;

		//Menu contextual
		QMenu contextMenu;

		/*!
		 * \brief contextMenuEvent
		 * \param event
		 */
		void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

		//Funciones heredadas
		QPainterPath shape() const;

		/*!
		 * \brief paint Dibuja un marco que representa un objeto vacio dentro de un sistema.
		 * Este metodo es base para todo objeto que implemente esta clase (debe llamarse \code{GraphicElement::paint()})
		 *
		 * \param painter Objeto para dibujar los graficos
		 * \param option Condiciones actuales del objeto que se pintara
		 * \param widget
		 */
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	protected slots:

		virtual void copyClick() = 0;
		virtual void cutClick() = 0;
		virtual void pasteClick() = 0;

		/*!
		 * \fn
		 *
		 * \brief propertyClick es llamada cuando se hace click en el elemento "Propiedades" del menu contextual
		 */
		virtual void propertyClick() = 0;

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
		virtual void saveClick() = 0;

		/*!
		 * \fn
		 *
		 * \brief onOpenClick Es llamado cuando se hace click en el elemento abrir del menu contextual
		 */
		virtual void openClick();

	protected:

		//Entrada actual del objeto para cualquier representacion grafica
		vector<double> inputs;

	private:

		Q_OBJECT

		//Ancho de borde del objeto
		QPen border;

		int
		//Ancho del marco
		sep,

		//Contiene el numero de entradas que tendra este objeto en caso de que no este conectado a ningun objeto en su entrada
		inputsSize;

		//Rectangulo que contiene las dimensiones de este objeto grafico
		QRectF rectangle;

		//Rectangulo interno
		QRectF intRectangle;

		/*!
		 * \brief init Inicializa el objeto constructor con una dimension @code{rect} y un ancho de borde @code{border}
		 * \param rect Rectangulo que contiene las dimensiones del objeto grafico
		 * \param border Ancho del borde de este objeto grafico
		 */
		void init(const QRectF &rect, int border);
};

#endif // GRAPHICELEMENT_H
