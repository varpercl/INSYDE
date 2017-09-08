#include "effect.h"

core::Effect::Effect()
{
//    Q_INIT_RESOURCE(core_media);
}

core::Effect::Effect(const QImage &img)
{
//    Q_INIT_RESOURCE(core_media);
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
