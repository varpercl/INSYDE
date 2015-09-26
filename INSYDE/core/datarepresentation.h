#ifndef DATAREPRESENTATION_H
#define DATAREPRESENTATION_H

#include <QtCore>

#include "interfaces.h"

namespace ann_base{
	/*!
 * \class
 *
 * \brief The DataRepresentation class contains all the information of the type of representation user wants to use
 * when data is imported from some data source. This class is not graphic, only contains data that could help to get a
 * graphical representation.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
	class Q_DECL_EXPORT DataRepresentation : public Resizable
	{
		public:

			enum Type{
				Raw,
				Image,
				DotMatrix,
				Sound,
				Text,
				Chart
			};

			/*!
			 * \brief DataRepresentation
			 */
			explicit DataRepresentation();

			/*!
			 * \brief DataRepresentation
			 * \param type
			 * \param imgFormat
			 * \param w
			 * \param h
			 */
			explicit DataRepresentation(const Type &type, const QImage::Format &imgFormat, int w, int h);

			/*!
			 * \brief DataRepresentation
			 * \param dr
			 */
			DataRepresentation(const DataRepresentation &dr);

			~DataRepresentation();

			/*!
			 * \brief getType
			 * \return
			 */
			Type getType() const;

			/*!
			 * \brief setType
			 * \param value
			 */
			void setType(const Type &value);

			/*!
			 * \brief getName
			 * \return
			 */
			QString getName() const;

			/*!
			 * \brief getWidth
			 * \return
			 */
			int getWidth() const;

			/*!
			 * \brief setWidth
			 * \param value
			 */
			void setWidth(int value);

			/*!
			 * \brief getHeight
			 * \return
			 */
			int getHeight() const;

			/*!
			 * \brief setHeight
			 * \param value
			 */
			void setHeight(int value);

			/*!
			 * \brief setSize
			 * \param size
			 */
			void setSize(const QSize &size);

			/*!
			 * \brief getSize
			 * \return
			 */
			QSize getSize() const;

			/*!
			 * \brief getImageFormat
			 * \return
			 */
			QImage::Format getImageFormat() const;

			/*!
			 * \brief setImageFormat
			 * \param value
			 */
			void setImageFormat(const QImage::Format &value);

			/*!
			 * \brief getImageFormatName
			 * \return
			 */
			QString getImageFormatName() const;

			DataRepresentation &operator=(const DataRepresentation &dr);
			bool operator==(const DataRepresentation &dr);
			bool operator!=(const DataRepresentation &dr);

		private:

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
			 * \brief init
			 * \param type
			 * \param imgFormat
			 * \param w
			 * \param h
			 */
			void init(const Type &type, const QImage::Format &imgFormat, int w, int h);
	};
}

#endif // DATAREPRESENTATION_H
