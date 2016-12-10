#ifndef TSMODELWRAPPER_H
#define TSMODELWRAPPER_H

#include <QtWidgets>

#include "share_ann_gui_lib.h"
#include "../ann_base/trainingset.h"

namespace ann_gui{

class TrainingSet;

class ANN_GUI_LIB_IMPORT_EXPORT TSModelWrapper : public QAbstractTableModel
{
	public:
		explicit TSModelWrapper(TrainingSet *ts);

		~TSModelWrapper();

	private:

		Q_OBJECT

		void init(TrainingSet *ts);
};

}
#endif // TSMODELWRAPPER_H
