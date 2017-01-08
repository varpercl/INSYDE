#include "effect.h"

core::Effect::Effect()
{
}

core::Effect::Effect(const QImage &img)
{
	setImage(img);
}

void core::Effect::setImage(const QImage &img)
{
	image = img;
}

QImage core::Effect::getImage()
{
	return image;
}
