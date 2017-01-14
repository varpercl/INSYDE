#ifndef IRESIZABLEF_H
#define IRESIZABLEF_H

#include <QtCore>

#include "share_core_lib.h"

namespace core{

/*!
 * \interface
 *
 * \brief La interfaz Resizable define todos aquellos objetos que tienen medidas de ancho y de alto y que
 * como minimo tienen que tener los metodos de redimensionamiento
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 11/02/2015
 */
class CORE_LIB_IMPORT_EXPORT IResizableF{
	public:

		/*!
		 * \brief setSize
		 * \param size
		 */
		virtual void setSize(const QSizeF &size) = 0;

		/*!
		 * \brief getSize
		 * \return
		 */
		virtual QSizeF getSize() const = 0;

		/*!
		 * \brief setWidth
		 * \param w
		 */
		virtual void setWidth(double w) = 0;

		/*!
		 * \brief getWidth
		 * \return
		 */
		virtual double getWidth() const = 0;

		/*!
		 * \brief setHeight
		 * \param h
		 */
		virtual void setHeight(double h) = 0;

		/*!
		 * \brief getHeight
		 * \return
		 */
		virtual double getHeight() const = 0;
};
}
#endif // IRESIZABLEF_H
