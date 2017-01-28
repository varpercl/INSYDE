#ifndef IIOOBJECT_H
#define IIOOBJECT_H

#include <QtCore>

#include "share_core_lib.h"

namespace core
{
/*!
 * \brief The IIOObject interface
 *
 * La interfaz IOObject define todos aquellos objetos que poseen (obligatoriamente) entradas y salidas
 *
 * NOTE: no se ha implementado todavia, se esta evaluando si es factible aplicarla a las clases
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 11/02/2015
 */
class Q_DECL_EXPORT IIOObject{
	public:
		virtual void setInputs(const vector<double> &inputs) = 0;
		virtual vector<double> getInputs() const = 0;

		virtual vector<double> getOutputs(const vector<double> &inputs) = 0;
		virtual vector<double> getOutputs() const = 0;

	protected:
		virtual void setOutputs(const vector<double> &outputs) = 0;

};
}
#endif // IIOOBJECT_H
