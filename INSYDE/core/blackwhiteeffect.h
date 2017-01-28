#ifndef BLACKWHITEEFFECT_H
#define BLACKWHITEEFFECT_H

#include <QImage>
#include <QColor>

#include <math.h>

#include "share_core_lib.h"
#include "effect.h"

namespace core{

/*!
 * \brief The BlackWhiteEffect class provides a wide abstraction of a black and white effect.
 * This holds all properties of a basic black and white effect applied over any image.
 * Effects are used when we want to modify image properties and see its changes.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT BlackWhiteEffect : public Effect
{
	public:

		/*!
		 * \brief The EffectType enum indicates who is this effect.
		 * Each effect has its respective identifier, and new effects should be well identified too.
		 */
		enum EffectType
		{
			BNEffectType = Nothing + 1 /**!< >*/
		};

		/*!
		 * \brief The ConvertionFormat enum indicates the way this algorithm generates the new image.
		 */
		enum ConvertionFormat{
			Threshold, /**!< If each pixel after being converted to gray exceed the threshold, this one will be black, if not then white >*/
			Mono /**!< \see QImage::Format_Mono >*/
		};

		/*!
		 * \brief Builds a basic BN effect that could be initialized later.
		 *
		 */
		explicit BlackWhiteEffect();

		/*!
		 * \brief Build a BN effect with an specified image \p img associated and a sensibility.
		 * This also specifies the convertion algorithm.
		 *
		 * \param[in] img The input image to this effect
		 * \param cf The convertion format to be used.
		 * \param threshold Sensibility of the algorithm.
		 */
		explicit BlackWhiteEffect(const QImage &img, ConvertionFormat cf = Threshold, double threshold = 0.5);

		~BlackWhiteEffect();

		/*!
		 * \brief Sets the current convertion format of this BN effect.
		 * \param fc The format to be used.
		 */
		void setConvertionFormat(ConvertionFormat fc);

		/*!
		 * \brief Specifies the image to be assigned as input of this effect.
		 * \param[in] img The image to be assigned.
		 */
		void setImage(const QImage &img);

		/*!
		 * \brief Returns the resulting image when applying this effect. This image
		 * is a new object and is not pointing to the input image.
		 * \return A QImage object.
		 */
		QImage getImage();

		/*!
		 * \brief Establish the sensibility of the conversion algorithm.
		 * \param ts A threshold value to be established.
		 */
		void setThreshold(double ts);

		/*!
		 * \brief Returns the current threshold of this effect.
		 * \return A double value that represents the threshold.
		 */
		double getThreshold();

		/*!
		 * \brief Deliver the tipe of current effect. This is used to differenciate of other effects.
		 * \return A int value that represent the type of this effect.
		 */
		int getType();
	private:

		ConvertionFormat cf;
		double threshold;

		/*!
		 * \brief Initialize all controlls of this dialog. Sets the dimentions and scales of them.
		 * \param img The associated image of this effect.
		 * \param fc The conversion format of this effect.
		 * \param threshold The current sensibility of this effect
		 *
		 * \see ConvertionFormat
		 */
		void init(const QImage &img, ConvertionFormat fc = Threshold, double threshold = 0.5);
};
}
#endif // BLACKWHITEEFFECT_H
