#ifndef BLACKWHITEEFFECT_H
#define BLACKWHITEEFFECT_H

#include <QImage>
#include <QColor>

#include <math.h>

#include "effect.h"

/*!
 * \brief The BlackWhiteEffect class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT BlackWhiteEffect : public Effect
{
	public:
		enum {BNEffectType = Nothing + 1};

		enum ConvertionFormat{
			Threshold,
			Mono
		};

		explicit BlackWhiteEffect();
		explicit BlackWhiteEffect(const QImage &img, ConvertionFormat cf = Threshold, double threshold = 0.5);

		~BlackWhiteEffect();

		void setConvertionFormat(ConvertionFormat fc);

//		void setImage(const QImage &img);
		QImage getImage();

		void setThreshold(double ts);
		double getThreshold();

		int getType();
	private:

		ConvertionFormat cf;
		double threshold;

		void initBWE(const QImage &img, ConvertionFormat fc = Threshold, double threshold = 0.5);
};

#endif // BLACKWHITEEFFECT_H
