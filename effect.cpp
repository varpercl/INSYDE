#include "effect.h"

Effect::Effect()
{
}

Effect::Effect(const QImage &img)
{
	setImage(img);
}

void Effect::setImage(const QImage &img)
{
	image = img;
}

QImage Effect::getImage()
{
	return image;
}
