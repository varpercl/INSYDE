#ifndef BASICDIALOG_H
#define BASICDIALOG_H

#include <QtWidgets>

#include "interfaces.h"
#include "icons.h"


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
class Q_DECL_EXPORT BasicDialog
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

		QAction *getNewAction() const;
		QAction *getOpenAction() const;
		QAction *getSaveAction() const;
		QAction *getCloseAction() const;
		QAction *getImportAction() const;
		QAction *getExportAction() const;
		QAction *getPreferencesAction() const;
		QAction *getAboutAction() const;
		QAction *getHelpAction() const;

		/*!
		 * \brief setOkButtonVisible Indicates wether Ok button will be visible or not.
		 * \param vis If \code{vis} is \code{true} then Ok button will be visible.
		 */
		void setAcceptButtonVisible(bool vis);
		QPushButton *getAcceptButton() const;

		/*!
		 * \brief setCancelButtonVisible Indicates wether Cancel button will be visible or not.
		 * \param vis If \code{vis} is \code{true} then Cancel button will be visible.
		 */
		void setRejectButtonVisible(bool vis);
		QPushButton *getRejectButton() const;

		void setHelpButtonVisible(bool vis);
		QPushButton *getHelptButton() const;

		void addButton(QPushButton *btn);
		void insertButton(int index, QPushButton* btn);
		void insertButton(int index, QToolButton* btn);

		QMenu *getFileMenu() const;
		QMenu *getEditMenu() const;
		QMenu *getToolsMenu() const;
		QMenu *getHelpMenu() const;

		void addMenu(QMenu *menu);

		void setFileMenuVisible(bool vis);
		void setEditMenuVisible(bool vis);
		void setToolsMenuVisible(bool vis);
		void setHelpMenuVisible(bool vis);

	public slots:

		/*!
		 * \brief Abre un nuevo proyecto o documento segun sea el caso
		 */
		virtual void newClick();
		virtual void openClick();
		virtual void saveClick();
		virtual void importClick();
		virtual void exportClick();
		virtual void preferencesClick();
		virtual void aboutClick();
		virtual void helpClick();

		virtual void unDoClick();
		virtual void reDoClick();

		virtual void copyClick();
		virtual void cutClick();
		virtual void pasteClick();

	private:
		Q_OBJECT

		bool
		enableNew,
		enableExport,
		enableImport,
		enableSave,
		enableOpen,
		enableUndo,
		enableClipboard;

//		QVector<QPushButton*> extraButtons;

		QPushButton
		*btnAccept,
		*btnReject,
		*btnHelp;

		QMenuBar *menuBar;

		QToolBar *mainToolbar;

		QAction
		*newAction,
		*openAction,
		*saveAction,
		*closeAction,
		*importAction,
		*exportAction,
		*preferencesAction,
		*aboutAction,
		*helpAction;

		QMenu
		*fileMenu,
		*editMenu,
		*toolsMenu,
		*helpMenu;

		QHBoxLayout *hlyButtons;

		QGridLayout *mainLayout;

		QMainWindow *mw;

		void init();

		void updateActionsVisibility();

};

#endif // BASICDIALOG_H
