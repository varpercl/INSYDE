#ifndef CLIPBOARD_H
#define CLIPBOARD_H

#include <QtGui>

#include "share_core_lib.h"

namespace core
{
/*!
 * \brief Contiene los metodos basicos para aquellos objetos que trabajen directamente con el portapapeles.
 * Estas funciones minimas deben ser implementadas si se quiere usar el portapapeles.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 14/02/2015
 */
class Q_DECL_EXPORT Clipboard {
	public:

		/*!
		 * \brief Set a new "copy" QAction to this dialog. If dialog already
		 * had an assigned QAction then user is responsible to free the data associated
		 * to the pointer.
		 *
		 * \param[in] action The new copy action to be assigned.
		 *
		 * TODO: implement validations
		 */
		virtual inline void setCopyAction(QAction *action){copyAction = action;}

		/*!
		 * \brief Obtains a pointer to the current "copy" action.
		 *
		 * \return A QAction pointer to the current "copy" action.
		 */
		inline QAction *getCopyAction() const {return copyAction;}

		/*!
		 * \brief Set a new "cut" QAction to this dialog. If dialog already
		 * had an assigned QAction then user is responsible to free the data associated
		 * to the pointer.
		 *
		 * \param[in] action The new "cut" action to be assigned.
		 *
		 * TODO: implement validations
		 */
		virtual inline void setCutAction(QAction *action){cutAction = action;}

		/*!
		 * \brief Obtains a pointer to the current "cut" action.
		 *
		 * \return A QAction pointer to the current "cut" action.
		 */
		inline QAction *getCutAction() const {return cutAction;}

		/*!
		 * \brief Set a new "paste" QAction to this dialog. If dialog already
		 * had an assigned QAction then user is responsible to free the data associated
		 * to the pointer.
		 *
		 * \param[in] action The new "paste" action to be assigned.
		 *
		 * TODO: implement validations
		 */
		virtual inline void setPasteAction(QAction *action){pasteAction = action;}

		/*!
		 * \brief Obtains a pointer to the current "cut" action.
		 *
		 * \return A QAction pointer to the current "cut" action.
		 */
		inline QAction *getPasteAction() const {return pasteAction;}

		/*!
		 * \brief Performs a copy action to the clipboard, this function is pure virtual
		 * and user must implement the right routines copy the right content.
		 *
		 */
		virtual void copyClick() = 0;

		/*!
		 * \brief Performs a cut action to the clipboard, this function is pure virtual
		 * and user must implement the right routines cut the right content.
		 *
		 */
		virtual void cutClick() = 0;

		/*!
		 * \brief Performs a paste action from the clipboard to this dialog, this
		 * function is pure virtual and user must implement the right routines
		 * paste the right content.
		 *
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
