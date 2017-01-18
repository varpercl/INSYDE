#ifndef BASICTREE_H
#define BASICTREE_H

#include <QtWidgets>

#include "share_core_lib.h"
#include "undo.h"
#include "definitions.h"
#include "clipboard.h"

namespace core{

/*!
 * \brief The BasicTree class provides all basic functionalities of a tree view.
 * This basic tree has functionalities like, clipboard and customizable contextual menu.
 *
 * \author Edixon V
 */
class CORE_LIB_IMPORT_EXPORT BasicTree : public QTreeView, public Clipboard
{
	public:

		/*!
		 * \brief Builds a basic empty tree view. Initialy, this is not bound to
		 * any model.
		 *
		 * \param[in] parent The parent widget of this tree view.
		 */
		explicit BasicTree(QWidget *parent = 0);

		~BasicTree();

	public slots:

		/*!
		 * \brief Performs a copy action to the clipboard, this function is pure virtual
		 * and user must implement the right routines copy the right content.
		 *
		 */
		void copyClick();

		/*!
		 * \brief Performs a cut action to the clipboard, this function is pure virtual
		 * and user must implement the right routines cut the right content.
		 *
		 */
		void cutClick();

		/*!
		 * \brief Performs a paste action from the clipboard to this dialog, this
		 * function is pure virtual and user must implement the right routines
		 * paste the right content.
		 *
		 */
		void pasteClick();

	protected:

		void contextMenuEvent(QContextMenuEvent *event);

	private:
		Q_OBJECT

		/*!
		 * \brief Initialize all controlls of this dialog. Sets the dimentions and scales of them.
		 */
		void init();

};
}
#endif // BASICTREE_H
