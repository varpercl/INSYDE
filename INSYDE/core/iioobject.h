#ifndef IIOOBJECT_H
#define IIOOBJECT_H

#include <QtCore>

#include "share_core_lib.h"

namespace core
{
/*!
 * \brief The IIOObject interface defines all objects that handles inputs and outputs.
 * For example, all graphics objects inherits from this interface.
 *
 * WARNING: in evaluation.
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
