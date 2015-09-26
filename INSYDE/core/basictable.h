#ifndef BASICTABLE_H
#define BASICTABLE_H

#include <QtWidgets>

#include "interfaces.h"
#include "icons.h"

/*!
 * \class BasicTable
 *
 * \brief BasicTable es una tabla basica que se puede usar a nivel general en diferentes widgets. Esta tabla tiene
 * funciones basicas como copiar, cortar y pegar. Cada uno de estos metodos estan ya definidos pero pueden ser
 * sobrescritos por las clases que hereden de esta.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 10/02/2015
 */
class Q_DECL_EXPORT BasicTable : public QTableView, public ClipboardInterface
{
	public:

		/*!
		 * \brief BasicTable
		 * \param parent
		 */
		explicit BasicTable(QWidget *parent = 0);

		~BasicTable();

	public slots:

		/*!
		 * \brief copyClick
		 */
		void copyClick();

		/*!
		 * \brief cutClick
		 */
		void cutClick();

		/*!
		 * \brief pasteClick
		 */
		void pasteClick();

	protected:

		/*!
		 * \brief contextMenuEvent Genera un menu contextual que en primera instancia instala las acciones para copiar,
		 * cortar y pegar.
		 * Cada una de ellas esta vinculada a su respectivo slot y es procesada de forma basica.
		 *
		 * \param event
		 *
		 * \see copyClick(), cutClick(), pasteClick()
		 */
		void contextMenuEvent(QContextMenuEvent *event);

	private:
		Q_OBJECT

		static const QString STR_TABLE;
		static const QString STR_ITEM;
		static const QString STR_ROW;
		static const QString STR_COL;
		static const QString STR_DATA;

		QMenu contextMenu;

		QClipboard *clipboard;

		void init();
};

#endif // BASICTABLE_H
