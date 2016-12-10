#ifndef BASICDIALOG_H
#define BASICDIALOG_H

#include <QtWidgets>

#include "share_core_lib.h"
#include "interfaces.h"
#include "definitions.h"


/*!
 * \class BasicDialog
 *
 * \brief Un cuadro de dialogo basico que contiene menus de edicion, gestion de propiedades y herramientas, ayuda,
 * importar/exportar archivos, entre otros.
 *
 * Es muy util cuando se quiere tener un cuadro de dialogo avanzado que incorpore todas estas funciones sin que el
 * programador se tenga que preocupar por crearlas paso a paso, lo cual, por supuesto ahorra mucho tiempo y permite
 * la reutilizacion de codigo.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 07/02/2015
 */
class CORE_LIB_IMPORT_EXPORT BasicDialog
		:
		public QDialog,
		public ClipboardInterface,
		public UnDoInterface
{
	public:

		/*!
		 * \brief BasicDialog
		 * \param parent
		 */
		explicit BasicDialog(QWidget *parent = 0);

		~BasicDialog();

		/*!
		 * \brief getMainWindow
		 * \return
		 */
		QMainWindow *getMainWindow() const;

		/*!
		 * \brief setEnableTools
		 * \param b
		 */
		void setEnablePreferences(bool b);

		/*!
		 * \brief setEnableNew
		 * \param b
		 */
		void setEnableNew(bool b);

		/*!
		 * \brief setEnableExport
		 * \param b
		 */
		void setEnableExport(bool b);

		/*!
		 * \brief setEnableImport
		 * \param b
		 */
		void setEnableImport(bool b);

		/*!
		 * \brief setEnableSave
		 * \param save
		 */
		void setEnableSave(bool save);

		/*!
		 * \brief setEnableSaveAs
		 * \param saveas
		 */
		void setEnableSaveAs(bool saveas);
		/*!
		 * \brief setEnableOpen
		 * \param open
		 */
		void setEnableOpen(bool open);

		/*!
		 * \brief setEnabledUnDo Set wether user can undo or redo any action inside this basic dialog
		 * \param undo
		 */
		void setEnableUnDoFramework(bool undo);

		/*!
		 * \brief setEnableClipboardFramework Allow user copy and paste any selected items or text to clipboard
		 * \param en
		 */
		void setEnableClipboardFramework(bool en);

		/*!
		 * \brief getEnabledUnDo
		 * \return
		 */
		bool getEnableUnDo() const;

		/*!
		 * \brief getNewAction
		 * \return
		 */
		QAction *getNewAction() const;

		/*!
		 * \brief getOpenAction
		 * \return
		 */
		QAction *getOpenAction() const;

		/*!
		 * \brief getSaveAction
		 * \return
		 */
		QAction *getSaveAction() const;

		/*!
		 * \brief getSaveAsAction
		 * \return
		 */
		QAction *getSaveAsAction() const;

		/*!
		 * \brief getCloseAction
		 * \return
		 */
		QAction *getCloseAction() const;

		/*!
		 * \brief getImportAction
		 * \return
		 */
		QAction *getImportAction() const;

		/*!
		 * \brief getExportAction
		 * \return
		 */
		QAction *getExportAction() const;

		/*!
		 * \brief getPreferencesAction
		 * \return
		 */
		QAction *getPreferencesAction() const;

		/*!
		 * \brief getAboutAction
		 * \return
		 */
		QAction *getAboutAction() const;

		/*!
		 * \brief getHelpAction
		 * \return
		 */
		QAction *getHelpAction() const;

		/*!
		 * \brief setOkButtonVisible Indicates wether Ok button will be visible or not.
		 * \param vis If \code{vis} is \code{true} then Ok button will be visible.
		 */
		void setAcceptButtonVisible(bool vis);

		/*!
		 * \brief getAcceptButton
		 * \return
		 */
		QPushButton *getAcceptButton() const;

		/*!
		 * \brief setCancelButtonVisible Indicates wether Cancel button will be visible or not.
		 * \param vis If \code{vis} is \code{true} then Cancel button will be visible.
		 */
		void setRejectButtonVisible(bool vis);

		/*!
		 * \brief getRejectButton
		 * \return
		 */
		QPushButton *getRejectButton() const;

		/*!
		 * \brief setHelpButtonVisible
		 * \param vis
		 */
		void setHelpButtonVisible(bool vis);

		/*!
		 * \brief getHelptButton
		 * \return
		 */
		QPushButton *getHelptButton() const;

		/*!
		 * \brief addButton
		 * \param btn
		 */
		void addButton(QPushButton *btn);

		/*!
		 * \brief insertButton
		 * \param index
		 * \param btn
		 */
		void insertButton(int index, QPushButton* btn);

		/*!
		 * \brief insertButton
		 * \param index
		 * \param btn
		 */
		void insertButton(int index, QToolButton* btn);

		/*!
		 * \brief getFileMenu
		 * \return
		 */
		QMenu *getFileMenu() const;

		/*!
		 * \brief getEditMenu
		 * \return
		 */
		QMenu *getEditMenu() const;

		/*!
		 * \brief getViewMenu
		 * \return
		 */
		QMenu *getViewMenu() const;

		/*!
		 * \brief getToolsMenu
		 * \return
		 */
		QMenu *getToolsMenu() const;

		/*!
		 * \brief getHelpMenu
		 * \return
		 */
		QMenu *getHelpMenu() const;

		/*!
		 * \brief addMenu
		 * \param menu
		 */
		void addMenu(QMenu *menu);

		/*!
		 * \brief setFileMenuVisible
		 * \param vis
		 */
		void setFileMenuVisible(bool vis);

		/*!
		 * \brief setEditMenuVisible
		 * \param vis
		 */
		void setEditMenuVisible(bool vis);

		/*!
		 * \brief setViewMenuVisible
		 * \param vis
		 */
		void setViewMenuVisible(bool vis);

		/*!
		 * \brief setToolsMenuVisible
		 * \param vis
		 */
		void setToolsMenuVisible(bool vis);

		/*!
		 * \brief setHelpMenuVisible
		 * \param vis
		 */
		void setHelpMenuVisible(bool vis);

		/*!
		 * \brief setEnableApplyButton
		 * \param en
		 */
		void setApplyButtonVisible(bool en);

		/*!
		 * \brief getEnableApplyButton
		 * \return
		 */
		bool getApplyButtonVisible() const;

		/*!
		 * \brief getMainToolbar
		 * \return
		 */
		QToolBar *getMainToolbar() const;


	public slots:

		/*!
		 * \brief Abre un nuevo proyecto o documento segun sea el caso
		 */
		virtual void newClick();

		/*!
		 * \brief openClick
		 */
		virtual void openClick();

		/*!
		 * \brief saveClick
		 */
		virtual void saveClick();

		/*!
		 * \brief saveAsClick
		 */
		virtual void saveAsClick();

		/*!
		 * \brief importClick
		 */
		virtual void importClick();

		/*!
		 * \brief exportClick
		 */
		virtual void exportClick();

		/*!
		 * \brief preferencesClick
		 */
		virtual void preferencesClick();

		/*!
		 * \brief aboutClick
		 */
		virtual void aboutClick();

		/*!
		 * \brief helpClick
		 */
		virtual void helpClick();

		/*!
		 * \brief unDoClick
		 */
		virtual void undoClick();

		/*!
		 * \brief reDoClick
		 */
		virtual void redoClick();

		/*!
		 * \brief copyClick
		 */
		virtual void copyClick();

		/*!
		 * \brief cutClick
		 */
		virtual void cutClick();

		/*!
		 * \brief pasteClick
		 */
		virtual void pasteClick();

		/*!
		 * \brief onAlwaysOnTopClicked
		 * \param checked
		 */
		virtual void onAlwaysOnTopClicked(bool checked);

		/*!
		 * \brief applyClicked
		 */
		virtual void onApplyClicked();


	private:
		Q_OBJECT

		bool
		enableNew,
		enableExport,
		enableImport,
		enableSave,
		enableSaveAs,
		enableOpen,
		enableUndo,
		enableClipboard,
		enablePreferences,
		visibleFileMenu,
		visibleEditMenu;

		QToolButton
		*saveButton;

		QPushButton
		*btnAccept,
		*btnReject,
		*btnApply,
		*btnHelp;

		QMenuBar *menuBar;

		QToolBar *mainToolbar;

		QAction
		*saveButtonAction,
		*newAction,
		*openAction,
		*saveAction,
		*saveAsAction,
		*closeAction,
		*importAction,
		*exportAction,
		*preferencesAction,
		*alwaysOnTopAction,
		*aboutAction,
		*helpAction;

		QMenu
		*fileMenu,
		*editMenu,
		*viewMenu,
		*toolsMenu,
		*helpMenu,
		*saveMenu;

		QHBoxLayout *hlyButtons;

		QGridLayout *mainLayout;

		QMainWindow *mw;

		/*!
		 * \brief init
		 */
		void init();

		/*!
		 * \brief updateActionsVisibility
		 */
		void updateActionsVisibility();

};

#endif // BASICDIALOG_H
