#ifndef NEWMAINWINDOW_H
#define NEWMAINWINDOW_H

#include "../core/definitions.h"
#include "../core/basicdialog.h"
#include "../core/adddotmatrixdialog.h"
#include "../core/simulation.h"
#include "../core/definitions.h"
#include "../core/connector.h"

#include "../ann_gui/definitions.h"
#include "../ann_gui/addnewmlpdialog.h"

#include "icons.h"
#include "view.h"

using namespace core;
using namespace ann_gui;

class MainWindow : public BasicDialog
{
	public:
		/*!
		 * \brief NewMainWindow
		 */
		explicit MainWindow();

		~MainWindow();

	private slots:
		/*!
		 * \brief onCloseTabsToRight
		 */
		void onCloseTabsToRight();

		/*!
		 * \brief onCloseTabsToLeft
		 */
		void onCloseTabsToLeft();

		/*!
		 * \brief onCloseOtherTabs
		 */
		void onCloseOtherTabs();

		/*!
		 * \brief onCloseAllTabs
		 */
		void onCloseAllTabs();

		/*!
		 * \brief on10pxTriggered
		 */
		void on10pxTriggered();

		/*!
		 * \brief on20pxTriggered
		 */
		void on20pxTriggered();

		/*!
		 * \brief on50pxTriggered
		 */
		void on50pxTriggered();

		/*!
		 * \brief onCustomizeGrid
		 */
		void onCustomizeGrid();

		/*!
		 * \brief onNativeTriggered
		 */
		void onNativeTriggered();

		/*!
		 * \brief onOpenGLTriggered
		 */
		void onOpenGLTriggered();

		/*!
		 * \brief onAddAdalineClicked
		 */
		void onAddAdalineClicked();

		/*!
		 * \brief onAddAgentClicked
		 */
		void onAddAgentClicked();

		/*!
		 * \brief onAddDotMatrixClicked
		 */
		void onAddDotMatrixClicked();

		/*!
		 * \brief onAddHopfieldClicked
		 */
		void onAddHopfieldClicked();

		/*!
		 * \brief onAddImageClicked
		 */
		void onAddImageClicked();

		/*!
		 * \brief onAddMLPClicked
		 */
		void onAddMLPClicked();

		/*!
		 * \brief onAddSimplePerceptronClicked
		 */
		void onAddSimplePerceptronClicked();

		/*!
		 * \brief onAddRegionClicked
		 */
		void onAddRegionClicked();

		/*!
		 * \brief onAddEffectClicked
		 */
		void onAddEffectClicked();

		/*!
		 * \brief onGDVMousePressed Throwed when GraphicDetailedView clicked
		 * \param event
		 */
		void onGDVMousePressed(QMouseEvent *event);

		/*!
		 * \brief onOpenOnNewWindowRequest
		 * \param obj
		 */
		void onOpenOnNewWindowRequest(GraphicObject *obj);

		/*!
		 * \brief onObjectRemoved
		 */
		void onObjectRemoved(GraphicObject *obj);

		/*!
		 * \brief onTabCloseRequested
		 * \param index
		 */
		void onTabCloseRequested(int index);

		/*!
		 * \brief onTabContextMenu
		 * \param pos
		 */
		void onTabContextMenu(QPoint pos);

		/*!
		 * \brief newClick
		 */
		void newClick();

		/*!
		 * \brief openClick
		 */
		void openClick();

		/*!
		 * \brief saveClick
		 */
		void saveClick();

		/*!
		 * \brief saveAsClick
		 */
		void saveAsClick();

		/*!
		 * \brief importClick
		 */
		void importClick();

		/*!
		 * \brief exportClick
		 */
		void exportClick();

		/*!
		 * \brief undoClick
		 */
		void undoClick();

		/*!
		 * \brief redoClick
		 */
		void redoClick();

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

		/*!
		 * \brief preferencesClick
		 */
		void preferencesClick();

		/*!
		 * \brief helpClick
		 */
		void helpClick();

		/*!
		 * \brief aboutClick
		 */
		void aboutClick();

	private:
		Q_OBJECT

		GraphicObject
		*clickedObject,
		*beginObject,
		*endObject;

		Connector
		*connector;

//		const QString STR_ADALINE = "ADALINE";
//		const QString STR_AGENT = "AGENT";
//		const QString STR_DOTMATRIX = "DOTMATRIX";
//		const QString STR_HOPFIELD = "HOPFIELD";
//		const QString STR_IMAGE = "IMAGE";
//		const QString STR_MLP = "MLP";
//		const QString STR_SIMPLEPERCEPTRON = "SIMPLEPERCEPTRON";
//		const QString STR_REGION = "REGION";
//		const QString STR_EFFECT = "EFFECT";

		int
//		dmIndex,
//		mlpIndex,
//		imgIndex,
//		imgEffectIndex,
//		hopfieldIndex,
//		adalineIndex,
//		spIndex,
		currentTab;

		bool
		lastChecked,
		lookingForEndObject;

		View
		*systemView;

		QButtonGroup
		*generalBG;

		QActionGroup
		*graphicsGroup,
		*gridGroup;

		QToolButton
		*lastToolChoosed,
		*btnAddADALINE,
		*btnAddAgent,
		*btnAddDotMatrix,
		*btnAddHopfield,
		*btnAddImage,
		*btnAddMLP,
		*btnAddSimplePerceptron,
		*btnAddRegion,
		*btnAddEffect;

		QToolBox
		*mainToolBox;

		QDockWidget
		*dwToolBox;

		QWidget
		*systemWidget,
		*generalTBWidget,
		*annTBWidget,
		*ecTBWidget;

		QTabWidget
		*mainTab;

		QMenu
		*menuGrid,
		*menuGraphics,
		*menuTabs;

		QAction
		*actionNative,
		*actionOpenGL,
		*action10px,
		*action20px,
		*action50px,
		*actionCustomize,
		*actionCloseOtherTabs,
		*actionCloseTabsToRight,
		*actionCloseTabsToLeft,
		*actionCloseAllTabs;

		QVBoxLayout
		*vlyGeneralToolBox,
		*vlyANNToolBox,
		*vlyECToolBox;

		Simulation *simulation;

		void init();

		void setupUI();

		void uncheckToolButton();

		/*!
		 * \brief isOpenWindow Determines wether a determined \code{obj} has any detailed window already open.
		 * \param obj
		 * \return
		 */
		bool isOpenWindow(GraphicObject *obj);

		/*!
		 * \brief getTabIndex Returns the index of a determined \code{obj} if this has any detailed window already open
		 * \param obj Return integer value representing index of object. If no window is open it returns -1
		 * \return
		 */
		int getTabIndex(GraphicObject *obj);

		//Temporary
		QMessageBox underConstruction;
		void showUnderConstructionMessage();
};

#endif // NEWMAINWINDOW_H
