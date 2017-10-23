#ifndef DATAREPRESENTATION_H
#define DATAREPRESENTATION_H

#include <QtCore>

#include "share_core_lib.h"
#include "undo.h"
#include "iresizable.h"

namespace core{

/*!
 * \brief The DataRepresentation class controls the way the data will be interpreted and shown to the
 * user. Contains all the information of the representation the user wants to use
 * when data is imported from some data source. This class is not graphic, only contains data that
 * could help to get a graphical representation.
 *
 * Data could be represented in different ways like Images, matrix, sound, text, charts, or simply raw data.
 *
 * \note Data won't be changed when this class is instantiated, it just will make a representation of data itself.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class CORE_LIB_IMPORT_EXPORT DataRepresentation : public IResizable
{
	public:

		/*!
		 * \brief The Type enum has all constants to represent different types of data
		 */
		enum Type{
			Raw, /**< The data will be shown as pure numbers as it is. */
			Image, /**< Data will be represented and translated to a image. */
			DotMatrix, /**< Data will be represented as a dot matrix. */

			Chart,	/**< Data will be represented as a chart.
					TODO: should implement chart properties.
					*/
			Sound, /**< Data will be represented as a sound wave. */
			Text, /**< This represents data as simple text.
					WARNING: should be specified different character codifications.
					*/

		};
		/*!
		 * \brief A default no-parameters constructor. This means all data will be null and no information
		 * will have this class. This will construct a null data representation.
		 */
		explicit DataRepresentation();

		/*!
		 * \brief Construct a data representation taken \p type as \c Image value. Representing itself as an
		 * image.
		 * \param type The type of data representation this class will take. In this case should be \c Image.
		 * \param imgFormat The format of the image this data representation will shown.
		 * \param w Width of the image.
		 * \param h Height of the image.
		 *
		 * FIXME: this constructor should be deambiguated. It shouldn't take any \p type parameter because it's
		 * understood that this will construnct an Image. Additionally should add different constructor for
		 * different data representations.
		 */
		explicit DataRepresentation(const Type &type, const QImage::Format &imgFormat, int w, int h);

		/*!
		 * \brief A copy constructor that will take of data of \p dr and will copy to this object instance.
		 * \param dr The source object to be copied.
		 */
		DataRepresentation(const DataRepresentation &dr);

		~DataRepresentation();

		/*!
		 * \brief Gets the type of this data representation.
		 * \return An integer representing the type of this data representation.
		 *
		 * \see Type
		 */
		Type getType() const;

		/*!
		 * \brief Establish the type of this data representation.
		 *
		 * \param value The \c Type value this data representation will take.
		 *
		 * \see Type
		 */
		void setType(const Type &value);

		/*!
		 * \brief Gets the name of this data representation.
		 * \return A string that contains the name of this data representation.
		 *
		 * \note This function is usefull when users needs to get the type of this data representation
		 * in an string. Could save time.
		 */
		QString getName() const;

		/*!
		 * \brief In case of \c Image type this will return the width of itself.
		 * \return An integer that holds the width of the image.
		 */
		int getWidth() const override;

		/*!
		 * \brief Establish the width of the image in case of being \c Image type.
		 * \param value The width of the image.
		 */
		void setWidth(int value) override;

		/*!
		 * \brief In case this class being \c Image type. This will returns the height of the image.
		 * \return An integer that holds the height of the image.
		 */
		int getHeight() const override;

		/*!
		 * \brief Sets the height of the image in case this class being \c Image type.
		 * \param value The height to be established.
		 */
		void setHeight(int value) override;

		/*!
		 * \brief Sets the size of this Image. This, in case the class being \c Image type.
		 * \param size The size to be stablished.
		 */
		void setSize(const QSize &size) override;

		/*!
		 * \brief Gets the size of this image. In case this class being \c Image type.
		 * \return A QSize object that holds the size of the image.
		 */
		QSize getSize() const override;

		/*!
		 * \brief Returns the image format of this class. In case this is \c Image type.
		 * \return The format of image.
		 *
		 * \see QImage::Format enum for more information.
		 */
		QImage::Format getImageFormat() const;

		/*!
		 * \brief Establish the image format of this class in case of \c Image type.
		 * \param value An integer value defined in \c QImage::Format.
		 */
		void setImageFormat(const QImage::Format &value);

		/*!
		 * \brief Gets the image format in a string.
		 * Useful to print format information without implementing tedious routines.
		 * \return An string representing the format of the image.
		 * It basicly returns the name of each constant in the QImage::Format enum converted
		 * to string.
		 *
		 */
		QString getImageFormatName() const;

		DataRepresentation &operator=(const DataRepresentation &dr);
		bool operator==(const DataRepresentation &dr);
		bool operator!=(const DataRepresentation &dr);

	private:
		Q_GADGET
		Q_ENUM(Type)
		//		Format_Invalid,
		//        Format_Mono,
		//        Format_MonoLSB,
		//        Format_Indexed8,
		//        Format_RGB32,
		//        Format_ARGB32,
		//        Format_ARGB32_Premultiplied,
		//        Format_RGB16,
		//        Format_ARGB8565_Premultiplied,
		//        Format_RGB666,
		//        Format_ARGB6666_Premultiplied,
		//        Format_RGB555,
		//        Format_ARGB8555_Premultiplied,
		//        Format_RGB888,
		//        Format_RGB444,
		//        Format_ARGB4444_Premultiplied,
		//        Format_RGBX8888,
		//        Format_RGBA8888,
		//        Format_RGBA8888_Premultiplied,

		QImage::Format imageFormat;

		Type type;

		int
		width,
		height;

		/*!
		 * \brief Initializes all information about the data representation dependint on \p type.
		 * \param type The type of the data to be processed.
		 * \param imgFormat The format of the image in case \type being \c Image type.
		 * \param w The width of the image.
		 * \param h The height of the image.
		 */
		void init(const Type &type, const QImage::Format &imgFormat, int w, int h);
};
}
#endif // DATAREPRESENTATION_H
