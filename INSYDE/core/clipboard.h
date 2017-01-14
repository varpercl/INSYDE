#ifndef CLIPBOARD_H
#define CLIPBOARD_H

#include <QtCore>

#include "share_core_lib.h"

namespace core
{
/*!
 * \interface
 *
 * \brief Contiene los metodos basicos para aquellos objetos que trabajen directamente con el portapapeles.
 * Estas funciones minimas deben ser implementadas si se quiere usar el portapapeles.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 14/02/2015
 */
class Q_DECL_EXPORT Clipboard{
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
}
#endif // CLIPBOARD_H
