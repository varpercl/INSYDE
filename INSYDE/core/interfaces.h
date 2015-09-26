#ifndef RESIZABLE
#define RESIZABLE

#include <QtGui>
#include <QtCore>

#include <vector>

using namespace std;

/*!
 * \interface
 *
 * \brief La interfaz Resizable define todos aquellos objetos que tienen medidas de ancho y de alto y que
 * como minimo tienen que tener los metodos de redimensionamiento
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 11/02/2015
 */
class Q_DECL_EXPORT Resizable{
	public:

		/*!
		 * \brief setSize
		 * \param size
		 */
		virtual void setSize(const QSize &size) = 0;

		/*!
		 * \brief getSize
		 * \return
		 */
		virtual QSize getSize() const = 0;

		/*!
		 * \brief setWidth
		 * \param w
		 */
		virtual void setWidth(int w) = 0;

		/*!
		 * \brief getWidth
		 * \return
		 */
		virtual int getWidth() const = 0;

		/*!
		 * \brief setHeight
		 * \param h
		 */
		virtual void setHeight(int h) = 0;

		/*!
		 * \brief getHeight
		 * \return
		 */
		virtual int getHeight() const = 0;
};

/*!
 * \interface
 *
 * \brief La interfaz IOObject define todos aquellos objetos que poseen (obligatoriamente) entradas y salidas
 *
 * NOTE: no se ha implementado todavia, se esta evaluando si es factible aplicarla a las clases
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 11/02/2015
 */
class Q_DECL_EXPORT IOObject{
	public:
		virtual void setInputs(const vector<double> &inputs) = 0;
		virtual vector<double> getInputs() const = 0;

		virtual vector<double> getOutputs(const vector<double> &inputs) = 0;
		virtual vector<double> getOutputs() const = 0;

	protected:
		virtual void setOutputs(const vector<double> &outputs) = 0;

};

/*!
 * \interface
 *
 * \brief Contiene los metodos basicos para aquellos objetos que trabajen directamente con el portapapeles.
 * Estas funciones minimas deben ser implementadas si se quiere usar el portapapeles.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 14/02/2015
 */
class Q_DECL_EXPORT ClipboardInterface{
	public:

		/*!
		 * \brief setCopyAction
		 * \param action
		 */
		virtual inline void setCopyAction(QAction *action){copyAction = action;}

		/*!
		 * \brief getCopyAction
		 * \return
		 */
		inline QAction *getCopyAction() const {return copyAction;}

		/*!
		 * \brief setCutAction
		 * \param action
		 */
		virtual inline void setCutAction(QAction *action){cutAction = action;}

		/*!
		 * \brief getCutAction
		 * \return
		 */
		inline QAction *getCutAction() const {return cutAction;}

		/*!
		 * \brief setPasteAction
		 * \param action
		 */
		virtual inline void setPasteAction(QAction *action){pasteAction = action;}

		/*!
		 * \brief getPasteAction
		 * \return
		 */
		inline QAction *getPasteAction() const {return pasteAction;}

		/*!
		 * \brief copyClick
		 */
		virtual void copyClick() = 0;

		/*!
		 * \brief cutClick
		 */
		virtual void cutClick() = 0;

		/*!
		 * \brief pasteClick
		 */
		virtual void pasteClick() = 0;

	private:

		QAction
		*copyAction,
		*cutAction,
		*pasteAction;
};

/*!
 * \class
 * \brief The UnDoInterface class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 14/02/2015
 */
class Q_DECL_EXPORT UnDoInterface{
	public:

		/*!
		 * \brief setUndoAction
		 * \param action
		 */
		virtual inline void setUndoAction(QAction *action){undoAction = action;}

		/*!
		 * \brief getUndoAction
		 * \return
		 */
		inline QAction *getUndoAction() const {return undoAction;}

		/*!
		 * \brief setRedoAction
		 * \param action
		 */
		virtual inline void setRedoAction(QAction *action){redoAction = action;}

		/*!
		 * \brief getRedoAction
		 * \return
		 */
		inline QAction *getRedoAction() const {return redoAction;}

		/*!
		 * \brief unDoClick
		 */
		virtual void unDoClick() = 0;

		/*!
		 * \brief reDoClick
		 */
		virtual void reDoClick() = 0;

	private:

		QAction
		*undoAction,
		*redoAction;
};

#endif // RESIZABLE

