#ifndef CORE_GUI_DEFINITIONS_H
#define CORE_GUI_DEFINITIONS_H

#include <QtCore>

#include "share_core_lib.h"

CORE_LIB_IMPORT_EXPORT void initCoreResources();

#ifndef DIR_SAMPLES
#define DIR_SAMPLES "/media/windows7/Documents and Settings/Edixon/Google Drive/Programacion/C++/Qt/INSYDE/samples"
#endif


#ifndef ICON_ERASER
#define ICON_ERASER QIcon(":/icons/media/eraser-icon-30208.png")
#endif
#ifndef ICON_FREEHAND
#define ICON_FREEHAND QIcon(":/icons/media/LineFreehand.png")
#endif
#ifndef ICON_FILL
#define ICON_FILL QIcon(":/icons/media/fill.png")
#endif
#ifndef ICON_NOIMAGE
#define ICON_NOIMAGE QIcon(":/icons/media/icon_image.svg")
#endif
#ifndef ICON_PADLOCK
#define ICON_PADLOCK QIcon(":/icons/media/padlock-xxl.png")
#endif
#ifndef ICON_APPLY
#define ICON_APPLY QIcon(":/icons/media/apply-icon.png")
#endif
#ifndef ICON_NEW
#define ICON_NEW QIcon(":/icons/media/Files-New-Window-icon.png")
#endif
#ifndef ICON_OPEN
#define ICON_OPEN QIcon(":/icons/media/folder-open-floder-icon.png")
#endif
#ifndef ICON_SAVE
#define ICON_SAVE QIcon(":/icons/media/Floppy-Small-icon.png")
#endif
#ifndef ICON_SAVEAS
#define ICON_SAVEAS QIcon(":/icons/media/saveas.png")
#endif
#ifndef ICON_IMPORT
#define ICON_IMPORT QIcon(":/icons/media/import-icon.png")
#endif
#ifndef ICON_EXPORT
#define ICON_EXPORT QIcon(":/icons/media/export-icon.png")
#endif
#ifndef ICON_PREFERENCES
#define ICON_PREFERENCES QIcon(":/icons/media/Gear-icon.png")
#endif
#ifndef ICON_ABOUT
#define ICON_ABOUT QIcon(":/icons/media/Actions-help-about-icon.png")
#endif
#ifndef ICON_HELP
#define ICON_HELP QIcon(":/icons/media/FAQ-icon.png")
#endif
#ifndef ICON_UNDO
#define ICON_UNDO QIcon(":/icons/media/Undo-icon.png")
#endif
#ifndef ICON_REDO
#define ICON_REDO QIcon(":/icons/media/Redo-icon.png")
#endif
#ifndef ICON_CLOSE
#define ICON_CLOSE QIcon(":/icons/media/Button-Close-icon.png")
#endif
#ifndef ICON_ZOOMIN
#define ICON_ZOOMIN QIcon(":/icons/media/Zoom in.png")
#endif
#ifndef ICON_ZOOMOUT
#define ICON_ZOOMOUT QIcon(":/icons/media/Zoom out.png")
#endif
#ifndef ICON_PLUS
#define ICON_PLUS QIcon(":/icons/media/plus_icon.png")
#endif
#ifndef ICON_MINUS
#define ICON_MINUS QIcon(":/icons/media/minus_icon.png")
#endif
#ifndef ICON_OK
#define ICON_OK QIcon(":/icons/media/symbol-check-icon.png")
#endif
#ifndef ICON_COPY
#define ICON_COPY QIcon(":/icons/media/copy-icon.png")
#endif
#ifndef ICON_CUT
#define ICON_CUT QIcon(":/icons/media/cut-icon.png")
#endif
#ifndef ICON_PASTE
#define ICON_PASTE QIcon(":/icons/media/paste-icon.png")
#endif
#ifndef ICON_REPORT
#define ICON_REPORT QIcon(":/icons/media/SEO-icon.png")
#endif
#ifndef ICON_OPEN_WINDOW
#define ICON_OPEN_WINDOWT QIcon(":/icons/media/Files-New-Window-icon.png")
#endif
#ifndef ICON_PROPERTIES
#define ICON_PROPERTIES QIcon(":/icons/media/ModernXP-70-Window-Settings-icon.png")
#endif
#ifndef ICON_DELETE
#define ICON_DELETE QIcon(":/icons/media/Actions-edit-delete-icon.png")
#endif
#ifndef ICON_TRAINING
#define ICON_TRAINING QIcon(":/icons/media/brain_working.png")
#endif
#ifndef ICON_STOP
#define ICON_STOP QIcon(":/icons/media/stop-red-icon.png")
#endif
#ifndef ICON_PAUSE
#define ICON_PAUSE QIcon(":/icons/media/Pause-icon.png")
#endif
#ifndef ICON_WAITING
#define ICON_WAITING QIcon(":/icons/media/Hourglass.png")
#endif
#ifndef ICON_MULTIPLE_TRAINING
#define ICON_MULTIPLE_TRAINING QIcon(":/icons/media/Utilities-tasks-icon.png")
#endif
#ifndef ICON_CLEAR
#define ICON_CLEAR QIcon(":/icons/media/clear.png")
#endif
#ifndef ICON_DICE
#define ICON_DICE QIcon(":/icons/media/Dice-icon.png")
#endif
#ifndef ICON_EDIT
#define ICON_EDIT QIcon(":/icons/media/edit-icon.png")
#endif
#ifndef ICON_UPDATE
#define ICON_UPDATE QIcon(":/icons/media/update_icon.png")
#endif
#ifndef ICON_INSERT_ROW
#define ICON_INSERT_ROW QIcon(":/icons/media/icon_insert_row.jpg")
#endif
#ifndef ICON_INSERT_COLUMN
#define ICON_INSERT_COLUMN QIcon(":/icons/media/icon_insert_column.jpg")
#endif
#ifndef ICON_TEST
#define ICON_TEST QIcon(":/icons/media/checklist-512.png")
#endif
#ifndef ICON_INFORMATION
#define ICON_INFORMATION QIcon(":/icons/media/Sign-Info-icon.png")
#endif

enum Position
{
	Top,
	Bottom,
	Left,
	Right
};

//TODO: 16/4/15 should add volume, time units.
enum Units{
	Nothing,
	Pixels,
	Dots,
	Points,
	Milimeters,
	Centimeters,
	Kilometers,
	Meters,
	Inches,
	Feets,
	Miles,
	Percentaje
};

#endif // ICONS_H

