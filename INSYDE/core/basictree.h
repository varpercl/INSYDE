#ifndef BASICTREE_H
#define BASICTREE_H

#include <QtWidgets>

#include "interfaces.h"
#include "icons.h"

class BasicTree : public QTreeView, public ClipboardInterface
{
	public:

		/*!
		 * \brief BasicTree
		 * \param parent
		 */
		explicit BasicTree(QWidget *parent = 0);

		~BasicTree();

		void copyClick();
		void cutClick();
		void pasteClick();

	protected:

		void contextMenuEvent(QContextMenuEvent *event);
	private:
		Q_OBJECT

		void init();

};

#endif // BASICTREE_H
