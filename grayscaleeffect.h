#ifndef GRAYSCALEEFFECT_H
#define GRAYSCALEEFFECT_H

#include <effect.h>

class GrayScaleEffect : public Effect
{
	public:
		enum {GrayScaleType = Nothing + 2};

		explicit GrayScaleEffect(const QImage &img);

		int getType();
	private:
		QImage image;

		void initGSE(const QImage &img);
};

#endif // GRAYSCALEEFFECT_H
