#ifndef RESIZABLE
#define RESIZABLE

#include <QtGui>

#include "share_core_lib.h"

namespace core
{
/*!
 * \brief The Undo class involves all graphic interface needed to perform Undo/Redo actions.
 * Every class that need to perform such actions should inherit from this class.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 14/02/2015
 */
class Q_DECL_EXPORT Undo{
	public:

		/*!
		 * \brief Sets the action who will perform the Undo.
		 *
		 * \note User is responsible for managing hangling pointers.
		 *
		 * \param[in] action A QAction related to the undo.
		 */
		virtual inline void setUndoAction(QAction *action){undoAction = action;}

		/*!
		 * \brief Returns the action related to the undo.
		 *
		 * \return A pointer to the QAction object related to the undo.
		 */
		inline QAction *getUndoAction() const {return undoAction;}

		/*!
		 * \brief Sets the redo action.
		 *
		 * \note User is responsible for managing hangling pointers.
		 *
		 * \param[in] action A pointer to the new action related to the redo action.
		 */
		virtual inline void setRedoAction(QAction *action){redoAction = action;}

		/*!
		 * \brief Gets the pointer to the redo action.
		 * \return A pointer to the redo QAction.
		 */
		inline QAction *getRedoAction() const {return redoAction;}

		/*!
		 * \brief Thrown when click on undo.
		 */
		virtual void undoClick() = 0;

		/*!
		 * \brief Thrown when click on redo.
		 */
		virtual void redoClick() = 0;

	private:

		QAction
		*undoAction,
		*redoAction;
};
}
#endif // RESIZABLE

