#ifndef GRAYSCALEEFFECT_H
#define GRAYSCALEEFFECT_H

#include "share_core_lib.h"
#include "effect.h"

namespace core{

/*!
 * \brief The GrayScaleEffect class is an specialized effect class which implements a GrayScale filter
 * to an image.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT GrayScaleEffect : public Effect
{
	public:

		/*!
		 * The type of the Effect.
		 */
		enum {GrayScaleType = Nothing + 2};

		/*!
		 * \brief An empty gray scale effect.
		 */
		explicit GrayScaleEffect();

		/*!
		 * \brief Builds a gray scale effect associated to a respective \p img.
		 * \param img
		 */
		explicit GrayScaleEffect(const QImage &img);

		/*!
		 * \brief The type of this effect.
		 * \return An integer that represents the type of this effect.
		 */
		int getType();

	private:
		QImage image;

		/*!
		 * \brief Initializes the attributes associated to the \p img parameter.
		 * \param img The associated image.
		 */
		void init(const QImage &img);
};
}
#endif // GRAYSCALEEFFECT_H
