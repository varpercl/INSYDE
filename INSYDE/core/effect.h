#ifndef EFFECT_H
#define EFFECT_H

#include <QImage>

#include "share_core_lib.h"

namespace core{

/*!
 * \brief The Effect class represents all data needed to make a basic graphic effect.
 *
 * TODO: redesign this class. is it necessary to apply an effect to an image only?
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT Effect
{
	public:

		/*!
		 * \brief The EffectType enum has every type of available effects.
		 */
		enum EffectType
		{
			Nothing /**< No effect is applied. */
		};

		/*!
		 * \brief Build an empty effect. This is inputs equal to outputs.
		 */
		explicit Effect();

		/*!
		 * \brief An effect applied to an image.
		 * \param img The image where the effect is applied.
		 */
		explicit Effect(const QImage &img);

		/*!
		 * \brief Sets the image of this effect.
		 * \param img
		 */
		virtual void setImage(const QImage &img);

		/*!
		 * \brief Returns the image where the effect is applied.
		 * \return
		 */
		virtual QImage getImage();

		/*!
		 * \brief Gets an identifier that represents this effect.
		 * \return An integer which identifies this effect.
		 */
		virtual int getType() = 0;

	protected:
		QImage image;


};
}
#endif // EFFECT_H
