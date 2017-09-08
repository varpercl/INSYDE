#ifndef BASICDIALOG_H
#define BASICDIALOG_H

#include <QtWidgets>

#include "share_core_lib.h"
#include "undo.h"
#include "definitions.h"
#include "clipboard.h"

/*!
 * \brief The core namespace stores a lot of classes and helper function to perform
 * from graphical functionalities to math calculations. Also stores some GUI classes
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 14/01/17
 */
namespace core{

/*!
 * \brief The BasicDialog class represents an improved and with-basic-functionalities dialog. With this dialog
 * you can perform actions like Undo and Redo, also it has a toolbar that has included some basic buttons like
 * New, Save, Open, Copy, Cut, Paste, Tools, Help and allow user to add its own buttons and hide what doesn't need.
 * This is a powerful dialog that is used by lots of specific dialogs in this project.
 *
 * By default it has four buttons Accept, Cancel, Apply, Help. This buttons can be hidden anytime the user wants.
 *
 * This BasicDialog combines the basic functionalities of QDialog and the powerful QMainWindow. The QMainWindow
 * is inside it and is the container for any control the user want to add later.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 07/02/2015
 */
class CORE_LIB_IMPORT_EXPORT BasicDialog
		:
		public QDialog,
		public Clipboard,
		public Undo
{
	public:

		/*!
		 * \brief Construct a basic dialog with no special characteristics, it is basicly an empty dialog.
		 *
		 * \param[in] parent The parent of this object.
		 */
		explicit BasicDialog(QWidget *parent = 0);

		~BasicDialog();

		/*!
		 * \brief Obtains a pointer to the QMainWindow object inside this BasicDialog.
		 *
		 * \return Return a QMainWindow pointer. This pointer is fully modifiable so user should act
		 * as careful as possible.
		 */
		QMainWindow *getMainWindow() const;

		/*!
		 * \brief The user can specify if wants to show the preference button in the toolbar which is represented
		 * by default by a gear.
		 *
		 * \param b True if wants to show the button.4
		 */
		void setEnablePreferences(bool b);

		/*!
		 * \brief Enables the New (project, file or whatever the user wants this button to mean) button. This allow the
		 * button to be visible.
		 *
		 * \param b Indicates if wants to enable this button.
		 */
		void setEnableNew(bool b);

		/*!
		 * \brief Enables the Export button. This allow
		 * the button to be visible.
		 *
		 * \param b Indicates if wants to enable this button.
		 */
		void setEnableExport(bool b);

		/*!
		 * \brief Enables the Import button. This allow
		 * the button to be visible.
		 *
		 * \param b Indicates if wants to enable this button.
		 */
		void setEnableImport(bool b);

		/*!
		 * \brief Enables the Save button. This allow
		 * the button to be visible.
		 *
		 * \param s Indicates if wants to enable this button.
		 */
		void setEnableSave(bool s);

		/*!
		 * \see setEnableSave
		 */
		void canSave(bool s);

		/*!
		 * \brief Enables the Save as button. This allow
		 * the button to be visible.
		 *
		 * \param sa Indicates if wants to enable this button.
		 */
		void setEnableSaveAs(bool sa);

		/*!
		 * \see setEnableSaveAs
		 */
		void canSaveAs(bool sa);
		/*!
		 * \brief Enables the Open as button. This allow
		 * the button to be visible.
		 *
		 * \param open Indicates if wants to enable this button.
		 */
		void setEnableOpen(bool open);

		/*!
		 * \see setEnableOpen
		 */
		void canOpenFile(bool open);

		/*!
		 * \brief Enables the UnDo framework which allow user to undo and redo actions on the
		 * main editor. This enables button and respective functionalities related to this function.
		 *
		 * \param undo Indicates if wants to enable this functionality.
		 */
		void setEnableUnDoFramework(bool undo);

		/*!
		 * \brief Allow user copy and paste any selected items or text to clipboard.
		 * This enables all clipboard functionalities and buttons.
		 *
		 * \param en Indicates if wants to enable this functionality.
		 */
		void setEnableClipboardFramework(bool en);

		/*!
		 * \brief Return the status of the Undo framework.
		 *
		 * \return True if Undo framework is enabled.
		 */
		bool isEnabledUnDoFramework() const;

		/*!
		 * \brief Return a pointer to the "New" action.
		 *
		 * \return A pointer to a QAction object related to the "New" action.
		 */
		QAction *getNewAction() const;

		/*!
		 * \brief Return a pointer to the "Open" action.
		 *
		 * \return A pointer to a QAction object related to the "Open" action.
		 */
		QAction *getOpenAction() const;

		/*!
		 * \brief Return a pointer to the "Save" action.
		 *
		 * \return A pointer to a QAction object related to the "Save" action.
		 */
		QAction *getSaveAction() const;

		/*!
		 * \brief Return a pointer to the "Save as" action.
		 *
		 * \return A pointer to a QAction object related to the "Save as" action.
		 */
		QAction *getSaveAsAction() const;

		/*!
		 * \brief Return a pointer to the "Close" action.
		 *
		 * \return A pointer to a QAction object related to the "Close" action.
		 */
		QAction *getCloseAction() const;

		/*!
		 * \brief Return a pointer to the "Import" action.
		 *
		 * \return A pointer to a QAction object related to the "Import" action.
		 */
		QAction *getImportAction() const;

		/*!
		 * \brief Return a pointer to the "Export" action.
		 *
		 * \return A pointer to a QAction object related to the "Export" action.
		 */
		QAction *getExportAction() const;

		/*!
		 * \brief Return a pointer to the "Preferences" action.
		 *
		 * \return A pointer to a QAction object related to the "Preferences" action.
		 */
		QAction *getPreferencesAction() const;

		/*!
		 * \brief Return a pointer to the "About" action.
		 *
		 * \return A pointer to a QAction object related to the "About" action.
		 */
		QAction *getAboutAction() const;

		/*!
		 * \brief Return a pointer to the "Help" action.
		 *
		 * \return A pointer to a QAction object related to the "Help" action.
		 */
		QAction *getHelpAction() const;

		/*!
		 * \brief Indicates wether "Accept" button will be visible or not.
		 *
		 * \param vis If \p vis is \c true then "Accept" button will be visible.
		 */
		void setAcceptButtonVisible(bool vis);

		/*!
		 * \brief Return a pointer to the "Accept" button.
		 *
		 * \return A QPushButton pointer to the "Accept" button.
		 */
		QPushButton *getAcceptButton() const;

		/*!
		 * \brief Indicates wether "Reject" button will be visible or not.
		 *
		 * \param vis If \p vis  is \c true then "Reject" button will be visible.
		 */
		void setRejectButtonVisible(bool vis);

		/*!
		 * \brief Return a pointer to the "Reject" button (or cancel).
		 *
		 * \return A QPushButton pointer to the "Reject" button.
		 */
		QPushButton *getRejectButton() const;

		/*!
		 * \brief Indicates wether Help button will be visible or not.
		 *
		 * \param vis If \p vis  is \c true then "Reject" button will be visible.
		 */
		void setHelpButtonVisible(bool vis);

		/*!
		 * \brief Return a pointer to the "Reject" button (or cancel).
		 *
		 * \return A QPushButton pointer to the "Reject" button.
		 */
		QPushButton *getHelptButton() const;

		/*!
		 * \brief Adds a customized button to the buttons table, just at the end of the array which can be
		 * generally below a basic dialog.
		 * This method add extra functionality to the basic dialog and allows users to set different commands.
		 *
		 * \param[in] btn A non-null pointer to the button the user wants to add.
		 *
		 * \see insertButton
		 */
		void addButton(QPushButton *btn);

		/*!
		 * \brief Similar to addButton, but this allows user to indicates the index where wants the buttom to be.
		 *
		 * \param index Indicates the position where the button will be placed. This index counts from 0
		 * (the first button generally "Accept" depending on layer).
		 *
		 * \param[in] btn A non-null pointer to the button the user wants to add.
		 *
		 * \see addButton
		 */
		void insertButton(int index, QPushButton* btn);

		/*!
		 * \param[in] btn A pointer to a QToolButton which represents the button to be inserted.
		 *
		 * \overload
		 */
		void insertButton(int index, QToolButton* btn);

		/*!
		 * \brief Gets the pointer to the "File" menu.
		 *
		 * \return A QFile pointer which represents the current "File" menu of this dialog.
		 */
		QMenu *getFileMenu() const;

		/*!
		 * \brief Gets the pointer to the "Edit" menu.
		 *
		 * \return A QFile pointer which represents the current "Edit" menu of this dialog.
		 */
		QMenu *getEditMenu() const;

		/*!
		 * \brief Gets the pointer to the "View" menu.
		 *
		 * \return A QFile pointer which represents the current "View" menu of this dialog.
		 */
		QMenu *getViewMenu() const;

		/*!
		 * \brief Gets the pointer to the "Tools" menu.
		 *
		 * \return A QFile pointer which represents the current "Tools" menu of this dialog.
		 */
		QMenu *getToolsMenu() const;

		/*!
		 * \brief Gets the pointer to the "Help" menu.
		 *
		 * \return A QFile pointer which represents the current "Help" menu of this dialog.
		 */
		QMenu *getHelpMenu() const;

		/*!
		 * \brief Adds a menu to the end of the menu bar.
		 *
		 * \param[in] menu A non-null QMenu pointer to the menu the user will add.
		 */
		void addMenu(QMenu *menu);

		/*!
		 * \brief Establish if "File" menu will be visible.
		 * \param vis A \c true value will make the "File" menu to be visible.
		 */
		void setFileMenuVisible(bool vis);

		/*!
		 * \brief Establish if "Edit" menu will be visible.
		 * \param vis A \c true value will make the "Edit" menu to be visible.
		 */
		void setEditMenuVisible(bool vis);

		/*!
		 * \brief Establish if "View" menu will be visible.
		 * \param vis A \c true value will make the "View" menu to be visible.
		 */
		void setViewMenuVisible(bool vis);

		/*!
		 * \brief Establish if "Tools" menu will be visible.
		 * \param vis A \c true value will make the "Tools" menu to be visible.
		 */
		void setToolsMenuVisible(bool vis);

		/*!
		 * \brief Establish if "Help" menu will be visible.
		 * \param vis A \c true value will make the "Help" menu to be visible.
		 */
		void setHelpMenuVisible(bool vis);

		/*!
		 * \brief Establish if "Apply" button will be visible.
		 * \param vis A \c true value will make the "Apply" button to be visible.
		 */
		void setApplyButtonVisible(bool en);

		/*!
		 * \brief Determines if the "Apply" button is actually visible or not.
		 * \param vis A \c true value if the "Apply" button is visible.
		 */
		bool isApplyButtonVisible() const;

		/*!
		 * \brief Gets the pointer to the "Main" toolbar.
		 *
		 * \return A QToolBar pointer which represents the current "Main" toolbar of this dialog.
		 */
		QToolBar *getMainToolbar() const;


	public slots:

		/*!
		 * \brief Creates a new project, document, image, or whatever the user want to create.
		 * This function is virtual and should be defined by the final user of this dialog
		 * depending on its needs.
		 *
		 * This function is thrown natively and automatically when user clicks over "New" button.
		 */
		virtual void newClick();

		/*!
		 * \brief Open the "Open file" dialog which allows users to open any document, project
		 * object and whatever the user needs.
		 *
		 * This function is thrown natively and automatically when user clicks over "Open" button.
		 */
		virtual void openClick();

		/*!
		 * \brief Start saving this current instance of any opened document, project, file or whatever
		 * the user has opened and wants to save changes.
		 *
		 * This function is thrown natively and automatically when user clicks over "Save" button.
		 *
		 * \see saveAsClick
		 */
		virtual void saveClick();

		/*!
		 * \brief Allows user to save a copy of the current instance of any opened document, project, file
		 * or whatever the user has opened and wants to save a copy of the changes.
		 *
		 * This function is thrown natively and automatically when user clicks over "Save as" button.
		 */
		virtual void saveAsClick();

		/*!
		 * \brief Similar to openClick, but in this case user is responsible to make this function to do
		 * the correct operations to import any file, document, image, project, etc.
		 *
		 * This function is thrown natively and automatically when user clicks over "Import" button.
		 *
		 * \see exportClick, openClick
		 */
		virtual void importClick();

		/*!
		 * \brief Similar to saveClick, but in this case user is responsible to make this function to do
		 * the correct operations to import any file, document, image, project, etc.
		 *
		 * This function is thrown natively and automatically when user clicks over "Export" button.
		 *
		 * \see importClick, saveClick
		 */
		virtual void exportClick();

		/*!
		 * \brief Opens the preferences dialog, which allows user to configure different properties of the
		 * current application.
		 *
		 * \note User is responsible to make the correct preferences dialog in the final
		 * implementation.
		 *
		 * This function is thrown natively and automatically when user clicks over "Preferences" button.
		 */
		virtual void preferencesClick();

		/*!
		 * \brief Opens the about dialog, which shows any information about the current application.
		 * Information like version, logo, enterprise, application name, emails, phones, website and much more
		 * should be shown by this dialog.
		 *
		 * \note User is responsible to show the correct information in the final
		 * implementation.
		 *
		 * This function is thrown natively and automatically when user clicks over "About" button.
		 */
		virtual void aboutClick();

		/*!
		 * \brief Opens a help dialog, which generally contains information about how the applications works.
		 *
		 * This function is thrown natively and automatically when user clicks over "Help" button.
		 */
		virtual void helpClick();

		/*!
		 * \brief Thrown when user clicks the undo button.
		 *
		 * \note In the final implementation, the user should make its own undo routines.
		 *
		 * This function is thrown natively and automatically when user clicks over "Undo" button.
		 */
		virtual void undoClick();

		/*!
		 * \brief Thrown when user clicks the redo button.
		 *
		 * \note In the final implementation, the user should make its own redo routines.
		 *
		 * This function is thrown natively and automatically when user clicks over "Redo" button.
		 */
		virtual void redoClick();

		/*!
		 * \brief Performs a copy action to the clipboard.
		 *
		 * \note The user is responsible of implement the correct routines to copy information on
		 * the clipboard.
		 *
		 * This function is thrown natively and automatically when user clicks over "Copy" button.
		 */
		virtual void copyClick();

		/*!
		 * \brief Cut the selected content to the clipboard.
		 *
		 * \note The user is responsible for implementation of the corret routines to cut the correct
		 * information on the clipboard.
		 *
		 * This function is thrown natively and automatically when user clicks over "Cut" button.
		 */
		virtual void cutClick();

		/*!
		 * \brief Paste a content from the clipboard to this dialog.
		 *
		 * \note The user is responsible for implementation of the current routines to paste the
		 * correct information in this dialog.
		 *
		 * This function is thrown natively and automatically when user clicks over "Paste" button.
		 */
		virtual void pasteClick();

		/*!
		 * \brief Thrown when user enables "Always on top" feature of this dialog.
		 *
		 * \param checked True and this dialog will be always on top.
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
		 * \brief Initializes all controls and variables in this dialog.
		 */
		void init();

		/*!
		 * \brief Performs an update of every action when user sets a particular
		 * action to be visible or not. This allows the respective separators and
		 * neighbor actions to be reallocated.
		 */
		void updateActionsVisibility();

};
}
#endif // BASICDIALOG_H
