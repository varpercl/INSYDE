#ifndef BASICTABLE_H
#define BASICTABLE_H

#include <QtWidgets>

#include "share_core_lib.h"
#include "interfaces.h"
#include "definitions.h"

namespace core{

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
class CORE_LIB_IMPORT_EXPORT BasicTable : public QTableView, public ClipboardInterface
{
	public:

		/*!
		 * \brief BasicTable
		 * \param parent
		 */
		explicit BasicTable(QWidget *parent = 0);

		~BasicTable();

	signals:

		void selectedItemsChanged(const QItemSelection &selected, const QItemSelection &deselected);

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

	protected slots:

		/*!
		 * \brief insertRightColumn Insert a column just right selected column. This increments by one the number of
		 * columns of the model assigned to this table.
		 *
		 * This affects directly the associated model of this table.
		 */
		virtual void onInsertRightColumnTriggered();

		/*!
		 * \brief insertLeftColumn Insert a column just left selected column. This increments by one the number of
		 * columns of the model assigned to this table.
		 *
		 * This affects directly the associated model of this table.
		 */
		virtual void onInsertLeftColumnTriggered();

		/*!
		 * \brief removeColumn Remove the current selected column, this reduces by one the number of columns in the model.
		 *
		 * This affects directly the associated model of this table.
		 */
		virtual void onRemoveColumnTriggered();

		/*!
		 * \brief insertUpRow Insert a row just up selected column. This increments by one the number of
		 * rows of the model assigned to this table.
		 *
		 * This affects directly the associated model of this table.
		 */
		virtual void onInsertUpRowTriggered();

		/*!
		 * \brief insertDownRow Insert a row just down selected column. This increments by one the number of
		 * rows of the model assigned to this table.
		 *
		 * This affects directly the associated model of this table.
		 */
		virtual void onInsertDownRowTriggered();

		/*!
		 * \brief removeRow Remove the current selected row, this reduces by one the number of rows in the model.
		 *
		 * This affects directly the associated model of this table.
		 */
		virtual void onRemoveRowTriggered();

	protected:

		QMenu
		*cellContextMenu,
		*horizontalHeaderContextMenu,
		*verticalHeaderContextMenu;

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

		void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

	private slots:

		/*!
		 * \brief onHorizontalHeaderContextMenu Called when a custom menu request
		 * \param pt
		 */
		void onHorizontalHeaderContextMenu(const QPoint pt);

		/*!
		 * \brief onVerticalHeaderContextMenu Called whent a custom menu request
		 * \param pt
		 */
		void onVerticalHeaderContextMenu(const QPoint pt);

	private:
		Q_OBJECT

		static const QString STR_TABLE;
		static const QString STR_ITEM;
		static const QString STR_ROW;
		static const QString STR_COL;
		static const QString STR_DATA;


		QClipboard *clipboard;

		void init();
};
}
#endif // BASICTABLE_H
