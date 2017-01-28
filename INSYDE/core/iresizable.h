#ifndef IRESIZABLE_H
#define IRESIZABLE_H

#include <QtCore>

#include "share_core_lib.h"

namespace core
{

/*!
 * \brief The IResizable interface
 * La interfaz Resizable define todos aquellos objetos que tienen medidas de ancho y de alto y que
 * como minimo tienen que tener los metodos de redimensionamiento
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 11/02/2015
 */
class CORE_LIB_IMPORT_EXPORT IResizable{
	public:

		/*!
		 * \brief setSize
		 * \param size
		 */
		virtual void setSize(const QSize &size) = 0;

		/*!
		 * \brief getSize
		 * \return
		 */
		virtual QSize getSize() const = 0;

		/*!
		 * \brief setWidth
		 * \param w
		 */
		virtual void setWidth(int w) = 0;

		/*!
		 * \brief getWidth
		 * \return
		 */
		virtual int getWidth() const = 0;

		/*!
		 * \brief setHeight
		 * \param h
		 */
		virtual void setHeight(int h) = 0;

		/*!
		 * \brief getHeight
		 * \return
		 */
		virtual int getHeight() const = 0;
};

}
#endif // IRESIZABLE_H
