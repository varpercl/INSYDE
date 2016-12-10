#ifndef SIMULATION_H
#define SIMULATION_H

#include <QtCore>

#include "share_core_lib.h"
#include "graphicobject.h"

class GraphicObject;

class CORE_LIB_IMPORT_EXPORT Simulation : public QThread
{
	public:

		/*!
		 * \brief Simulation
		 */
		explicit Simulation();

		/*!
		 * \brief add
		 * \param obj
		 */
		void add(GraphicObject *obj);

		/*!
		 * \brief remove
		 * \param obj
		 */
		void remove(GraphicObject *obj);

	protected:

		/*!
		 * \brief run
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
		 * \brief init
		 */
		void init();

		QString getNamePrivateHelper(const QString &suffix) const;
};

#endif // SIMULATION_H
