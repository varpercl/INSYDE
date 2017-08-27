#ifndef SIMULATION_H
#define SIMULATION_H

#include <QtCore>

#include "share_core_lib.h"
#include "graphicobject.h"

namespace core{

class GraphicObject;

/*!
 * \brief The Simulation class takes every single object in the enviroment and
 * performs a step-by-step simulation.
 *
 * TODO: This class is not implemented yet.
 */
class CORE_LIB_IMPORT_EXPORT Simulation : public QThread
{
	public:

		/*!
		 * \brief A empty simulation.
		 */
		explicit Simulation();

		/*!
		 * \brief Adds an object to this simulation.
		 * \param obj The object.
		 */
		void add(GraphicObject *obj);

		/*!
		 * \brief Removes a determined object \p obj.
		 * \param obj The object to be removed.
		 */
		void remove(GraphicObject *obj);

	protected:

		/*!
		 * \brief Runs the current simulation taking in acount all objects and connections.
		 */
		void run();

		virtual void setAutomaticObjectName(GraphicObject *obj);

	private:
		Q_OBJECT

		const QString
		SUFFIX_GRAPHICOBJECT = "GraphicObject",
		SUFFIX_ADALINE = "Adaline",
		SUFFIX_MLP = "MLP",
		SUFFIX_HOPFIELD = "Hopfield",
		SUFFIX_KOHONEN = "Kohonen",
		SUFFIX_IMAGE = "Image",
		SUFFIX_IMAGEEFFECT = "ImageFx",
		SUFFIX_DOTMATRIX = "DotMatrix",
		SUFFIX_REGION = "Region",
		SUFFIX_AGENT = "Agent",
		SUFFIX_GRAPHICPOINTER = "GraphicPointer",
		SUFFIX_CONNECTOR = "Connector";

		QVector<GraphicObject*> objects;

		/*!
		 * \brief Initializes everyting
		 */
		void init();

		/*!
		 * \brief getNamePrivateHelper
		 * \param suffix
		 * \return
		 */
		QString getNamePrivateHelper(const QString &suffix) const;
};
}
#endif // SIMULATION_H
