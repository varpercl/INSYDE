#ifndef GRAYSCALEEFFECT_H
#define GRAYSCALEEFFECT_H

#include "effect.h"

/*!
 * \brief The GrayScaleEffect class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT GrayScaleEffect : public Effect
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
