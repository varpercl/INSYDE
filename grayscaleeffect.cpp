#include "grayscaleeffect.h"

GrayScaleEffect::GrayScaleEffect(const QImage &img)
{
	initGSE(img);
}

int GrayScaleEffect::getType()
{
	return GrayScaleType;
}

void GrayScaleEffect::initGSE(const QImage &img)
{
	(void)img;
}
