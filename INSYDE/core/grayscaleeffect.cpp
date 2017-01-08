#include "grayscaleeffect.h"

core::GrayScaleEffect::GrayScaleEffect()
{
	init(QImage());
}

core::GrayScaleEffect::GrayScaleEffect(const QImage &img)
{
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
