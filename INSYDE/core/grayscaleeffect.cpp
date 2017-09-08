#include "grayscaleeffect.h"

core::GrayScaleEffect::GrayScaleEffect()
{
//    Q_INIT_RESOURCE(core_media);
	init(QImage());
}

core::GrayScaleEffect::GrayScaleEffect(const QImage &img)
{
//    Q_INIT_RESOURCE(core_media);
	init(img);
}

int core::GrayScaleEffect::getType()
{
	return GrayScaleType;
}

void core::GrayScaleEffect::init(const QImage &img)
{
	(void)img;
}
