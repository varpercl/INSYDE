#ifndef RESIZABLE
#define RESIZABLE

#include <QtGui>

#include "share_core_lib.h"

namespace core
{
/*!
 * \class
 * \brief The UnDoInterface class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 14/02/2015
 */
class Q_DECL_EXPORT Undo{
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
		virtual void undoClick() = 0;

		/*!
		 * \brief reDoClick
		 */
		virtual void redoClick() = 0;

	private:

		QAction
		*undoAction,
		*redoAction;
};
}
#endif // RESIZABLE

