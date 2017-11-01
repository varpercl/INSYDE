#ifndef ANN_GUI_DEFINITIONS_H
#define ANN_GUI_DEFINITIONS_H

#include <QtCore>

#include "share_ann_gui_lib.h"

ANN_GUI_LIB_IMPORT_EXPORT void initAnnGuiResources();

#ifndef ICON_MLP
#define ICON_MLP QIcon(":/icons/media/Multi-Layer_Neural_Network-Vector.png")
#endif
#ifndef ICON_ADALINE
#define ICON_ADALINE QIcon(":/icons/media//adaline.gif")
#endif
#ifndef ICON_HOPFIELD
#define ICON_HOPFIELD QIcon(":/icons/media/hopfield.jpg")
#endif
#ifndef ICON_ANN
#define ICON_ANN QIcon(":/icons/media/artificial neural network.png")
#endif
#ifndef ICON_SIMPLEPERCEPTRON
#define ICON_SIMPLEPERCEPTRON QIcon(":/icons/media/perceptron2.png")
#endif
#ifndef ICON_IMPORT_DB
#define ICON_IMPORT_DB QIcon(":/icons/media/update--database-icon-33693.png")
#endif

#endif
