#include "grayscaleeffect.h"

GrayScaleEffect::GrayScaleEffect()
{
	init(QImage());
}

GrayScaleEffect::GrayScaleEffect(const QImage &img)
{
	init(img);
}

int GrayScaleEffect::getType()
{
	return GrayScaleType;
}

void GrayScaleEffect::init(const QImage &img)
{
	(void)img;
}
