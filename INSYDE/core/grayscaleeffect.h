#ifndef GRAYSCALEEFFECT_H
#define GRAYSCALEEFFECT_H

#include "share_core_lib.h"
#include "effect.h"

/*!
 * \brief The GrayScaleEffect class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT GrayScaleEffect : public Effect
{
	public:
		enum {GrayScaleType = Nothing + 2};

		explicit GrayScaleEffect();
		explicit GrayScaleEffect(const QImage &img);

		int getType();
	private:
		QImage image;

		void init(const QImage &img);
};

#endif // GRAYSCALEEFFECT_H
