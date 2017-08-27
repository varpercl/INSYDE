#include "tsmodelwrapper.h"
namespace ann_gui{

ann_gui::TSModelWrapper::TSModelWrapper(TrainingSet *ts)
{
    Q_INIT_RESOURCE(ann_gui_media);

	init(ts);
}

ann_gui::TSModelWrapper::~TSModelWrapper()
{

}

void ann_gui::TSModelWrapper::init(TrainingSet *ts)
{
	(void)ts;

	//TODO: 25/4/16 init implement
}

}
