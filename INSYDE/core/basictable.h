#ifndef BASICTABLE_H
#define BASICTABLE_H

#include <QtCore>
#include <QtWidgets>

#include "share_core_lib.h"
#include "undo.h"
#include "definitions.h"
#include "clipboard.h"

namespace core{

/*!
 * \brief The BasicTable class encloses an extended QTableView table which includes
 * extended menus and clipboard functionalities.
 *
 * It keep the MVC arquitecture which is the more suitable to build complex views.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 10/02/2015
 */
class CORE_LIB_IMPORT_EXPORT BasicTable : public QTableView, public Clipboard
{
	public:

		/*!
		 * \brief Construct a table with no parameters, the default built is
		 * a table with one cell.
		 *
		 * \param[in] parent Indicates the parent of this table.
		 */
		explicit BasicTable(QWidget *parent = 0);

		~BasicTable();

	signals:

		/*!
		 * \brief Thrown when the amount of cells or even the way they are selected are changed.
		 *
		 * \param[in] selected Indicates the selected items model.
		 * \param[in] deselected Indicates the deselected items model.
		 */
		void selectedItemsChanged(const QItemSelection &selected, const QItemSelection &deselected);

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

		/*!
		 * \brief Initialize all controlls of this dialog. Sets the dimentions and scales of them.
		 */
		void init();
};
}
#endif // BASICTABLE_H
