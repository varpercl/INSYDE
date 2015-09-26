#include "basicdialog.h"

#include "icons.h"

BasicDialog::BasicDialog(QWidget *parent) :
	QDialog(parent)
{
	init();
}

BasicDialog::~BasicDialog()
{

}

QMainWindow *BasicDialog::getMainWindow() const
{
	return mw;
}

void BasicDialog::setEnableNew(bool b)
{
	if(enableNew != b){
		enableNew = b;

		newAction->setVisible(b);
		newAction->setEnabled(b);

		updateActionsVisibility();
	}
}

void BasicDialog::setEnableExport(bool b)
{
	if(enableExport != b){
		enableExport = b;

		exportAction->setVisible(b);
		exportAction->setEnabled(b);

		updateActionsVisibility();
	}
}

void BasicDialog::setEnableImport(bool b)
{
	if(enableImport != b){
		enableImport = b;

		importAction->setVisible(b);
		importAction->setEnabled(b);

		updateActionsVisibility();
	}
}

void BasicDialog::setEnableSave(bool save)
{
	if(enableSave != save){
		enableSave = save;

		saveAction->setVisible(save);
		saveAction->setEnabled(save);

		updateActionsVisibility();
	}
}

void BasicDialog::setEnableOpen(bool open)
{
	if(enableOpen != open){
		enableOpen = open;

		getOpenAction()->setVisible(open);
		getOpenAction()->setEnabled(open);

		updateActionsVisibility();
	}
}

void BasicDialog::setEnableUnDoFramework(bool undo)
{
	if(enableUndo != undo){
		enableUndo = undo;

		getUndoAction()->setVisible(undo);
		getUndoAction()->setEnabled(undo);

		getRedoAction()->setVisible(undo);
		getRedoAction()->setEnabled(undo);

		updateActionsVisibility();
	}
}

void BasicDialog::setEnableClipboardFramework(bool en)
{
	if(enableClipboard != en){
		enableClipboard = en;

		getCopyAction()->setVisible(en);
		getCopyAction()->setEnabled(en);

		getCutAction()->setVisible(en);
		getCutAction()->setEnabled(en);

		getPasteAction()->setVisible(en);
		getPasteAction()->setEnabled(en);

		updateActionsVisibility();
	}
}

bool BasicDialog::getEnableUnDo() const
{
	return enableUndo;
}

QAction *BasicDialog::getNewAction() const
{
	return newAction;
}

QAction *BasicDialog::getOpenAction() const
{
	return openAction;
}

QAction *BasicDialog::getSaveAction() const
{
	return saveAction;
}

QAction *BasicDialog::getCloseAction() const
{
	return closeAction;
}

QAction *BasicDialog::getImportAction() const
{
	return importAction;
}

QAction *BasicDialog::getExportAction() const
{
	return exportAction;
}

QAction *BasicDialog::getPreferencesAction() const
{
	return preferencesAction;
}

QAction *BasicDialog::getAboutAction() const
{
	return aboutAction;
}

QAction *BasicDialog::getHelpAction() const
{
	return helpAction;
}

void BasicDialog::setAcceptButtonVisible(bool vis)
{
	btnAccept->setVisible(vis);
}

QPushButton *BasicDialog::getAcceptButton() const
{
	return btnAccept;
}

void BasicDialog::setRejectButtonVisible(bool vis)
{
	btnReject->setVisible(vis);
}

QPushButton *BasicDialog::getRejectButton() const
{
	return btnReject;
}

void BasicDialog::setHelpButtonVisible(bool vis)
{
	btnHelp->setVisible(vis);
}

QPushButton *BasicDialog::getHelptButton() const
{
	return btnHelp;
}

void BasicDialog::addButton(QPushButton *btn)
{
	hlyButtons->addWidget(btn);
}

void BasicDialog::insertButton(int index, QPushButton *btn)
{
	hlyButtons->insertWidget(index, btn);
}

void BasicDialog::insertButton(int index, QToolButton *btn)
{
	hlyButtons->insertWidget(index, btn);
}

QMenu *BasicDialog::getFileMenu() const
{
	return fileMenu;
}

QMenu *BasicDialog::getEditMenu() const
{
	return editMenu;
}

QMenu *BasicDialog::getToolsMenu() const
{
	return toolsMenu;
}

QMenu *BasicDialog::getHelpMenu() const
{
	return helpMenu;
}

void BasicDialog::addMenu(QMenu *menu)
{
	mw->menuBar()->addMenu(menu);
}

void BasicDialog::setFileMenuVisible(bool vis)
{
	fileMenu->setVisible(vis);
}

void BasicDialog::setEditMenuVisible(bool vis)
{
	editMenu->setVisible(vis);
}

void BasicDialog::setToolsMenuVisible(bool vis)
{
	toolsMenu->setVisible(vis);
}

void BasicDialog::setHelpMenuVisible(bool vis)
{
	helpMenu->setVisible(vis);
}

void BasicDialog::newClick()
{

}

void BasicDialog::openClick()
{

}

void BasicDialog::saveClick()
{

}

void BasicDialog::importClick()
{

}

void BasicDialog::exportClick()
{

}

void BasicDialog::unDoClick()
{

}

void BasicDialog::reDoClick()
{

}

void BasicDialog::preferencesClick()
{

}

void BasicDialog::aboutClick()
{

}

void BasicDialog::helpClick()
{

}

void BasicDialog::copyClick()
{

}

void BasicDialog::cutClick()
{

}

void BasicDialog::pasteClick()
{

}

void BasicDialog::init()
{
	setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
	mainLayout = new QGridLayout();
	mainLayout->setMargin(0);

	mw = new QMainWindow();
	mw->setCentralWidget(new QWidget());

	menuBar = mw->menuBar();
	fileMenu = menuBar->addMenu("Archivo");
	newAction = fileMenu->addAction(ICON_NEW, "Nuevo", this, SLOT(newClick()));
	openAction = fileMenu->addAction(ICON_OPEN, "Abrir...", this, SLOT(openClick()));
	saveAction = fileMenu->addAction(ICON_SAVE, "Guardar...", this, SLOT(saveClick()));
	fileMenu->addSeparator();
	importAction = fileMenu->addAction(ICON_IMPORT, "Importar...", this, SLOT(importClick()));
	exportAction = fileMenu->addAction(ICON_EXPORT, "Exportar...", this, SLOT(exportClick()));
	fileMenu->addSeparator();
	closeAction = fileMenu->addAction(ICON_CLOSE, "Salir", this, SLOT(close()));

	editMenu = menuBar->addMenu(QIcon(), QString::fromLatin1("Edición"));
	setUndoAction(editMenu->addAction(ICON_UNDO, "Deshacer", this, SLOT(unDoClick())));
	setRedoAction(editMenu->addAction(ICON_REDO, "Rehacer", this, SLOT(reDoClick())));
	editMenu->addSeparator();
	setCopyAction(editMenu->addAction(ICON_COPY, "Copiar", this, SLOT(copyClick())));
	setCutAction(editMenu->addAction(ICON_CUT, "Cortar", this, SLOT(cutClick())));
	setPasteAction(editMenu->addAction(ICON_PASTE, "Pegar", this, SLOT(pasteClick())));

	toolsMenu = menuBar->addMenu(QIcon(), "Herramientas");
	preferencesAction = toolsMenu->addAction(ICON_PREFERENCES, "Preferencias", this, SLOT(preferencesClick()));

	helpMenu = menuBar->addMenu(QIcon(), QString::fromLatin1("Ayúda"));
	aboutAction = helpMenu->addAction(ICON_ABOUT, "Acerca de...", this, SLOT(aboutClick()));
	helpAction = helpMenu->addAction(ICON_HELP, QString::fromLatin1("Ayúda"), this, SLOT(helpClick()));

	mainToolbar = new QToolBar();
	mainToolbar->addAction(newAction);
	mainToolbar->addAction(openAction);
	mainToolbar->addAction(saveAction);
	mainToolbar->addSeparator();
	mainToolbar->addAction(getCopyAction());
	mainToolbar->addAction(getCutAction());
	mainToolbar->addAction(getPasteAction());
	mainToolbar->addSeparator();
	mainToolbar->addAction(getUndoAction());
	mainToolbar->addAction(getRedoAction());
	mainToolbar->addSeparator();
	mainToolbar->addAction(preferencesAction);
	mainToolbar->addSeparator();
	mainToolbar->addAction(helpAction);

	mw->addToolBar(mainToolbar);
	mw->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

	btnAccept = new QPushButton(ICON_OK, "Aceptar");
	btnReject = new QPushButton(ICON_CLOSE, "Cancelar");
	btnHelp = new QPushButton(ICON_HELP, "Ayuda");

	hlyButtons = new QHBoxLayout();
//	hlyButtons->setDirection(QBoxLayout::RightToLeft);
	hlyButtons->setMargin(6);
	hlyButtons->addStretch(10);
	hlyButtons->addWidget(btnAccept);
	hlyButtons->addWidget(btnReject);
	hlyButtons->addWidget(btnHelp);

	mainLayout->addWidget(mw, 1, 1);
	mainLayout->addLayout(hlyButtons, 2, 1);

	setLayout(mainLayout);

	enableNew = true;
	enableExport = true;
	enableImport = true;
	enableUndo = true;
	enableSave = true;
	enableOpen = true;
	enableClipboard = true;

	connect(btnAccept, SIGNAL(clicked()), SLOT(accept()));
	connect(btnReject, SIGNAL(clicked()), SLOT(close()));
	connect(btnHelp, SIGNAL(clicked()), SLOT(helpClick()));
}

void BasicDialog::updateActionsVisibility()
{
	//Set separator after CLIPBOARD visible or not
	mainToolbar->actions()[7]->setVisible(enableClipboard);

	//Set separator after NEW, SAVE, OPEN actions visible or not
	bool enSep3 = enableNew || enableOpen || enableSave;
	mainToolbar->actions()[3]->setVisible(enSep3);
	fileMenu->actions()[3]->setVisible(enSep3);

	//Set separator after UNDO visible or not
	mainToolbar->actions()[10]->setVisible(enableUndo);
	editMenu->actions()[2]->setVisible(enableUndo);

	//Set separator after EXPORT, IMPORT visible or not
	bool enSep6 = enableExport || enableImport;
	fileMenu->actions()[6]->setVisible(enSep6);

	fileMenu->menuAction()->setVisible(enSep3 || enSep6 || closeAction->isVisible());

	editMenu->menuAction()->setVisible(enableUndo || enableClipboard);
}

