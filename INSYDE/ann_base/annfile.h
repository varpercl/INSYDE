#ifndef ANNFILE_H
#define ANNFILE_H

#include <QtCore>

#include <vector>

//#include "artificialneuralnetwork.h"
#include "mlp.h"

namespace ann_base {

using namespace std;

/*!
 * \brief The ANNFile class
 */
class ANN_BASE_LIB_IMPORT_EXPORT ANNFile : public QFile
{
	public:

		enum Version
		{
			v1_0
		};

		explicit ANNFile();
		/*!
		 * \brief Creates a new instance based on any ann object.
		 * The type can be determined with ANN properties
		 * \param ann The artificial neural network
		 */
		explicit ANNFile(QString path, ArtificialNeuralNetwork *ann, Version version = v1_0);

		~ANNFile();

		/*!
		 * \brief Flush everything in a single file.
		 */
		bool flush();

		/*!
		 * \brief getVersion
		 * \return
		 */
		Version getVersion() const;

	public slots:

		/*!
		 * \brief Sets the ANN object to be processed and saved into a file.
		 * \param ann The ANN object.
		 */
		void setANN(ArtificialNeuralNetwork *ann);

		/*!
		 * \brief setVersion
		 * \param value
		 */
		void setVersion(const Version &value);


	private:

		Q_OBJECT

		//The ANN object to save
		ArtificialNeuralNetwork *ann;

		//The version of this file
		Version version;

		static const QString STR_ANN_DEFINITION;
		static const QString STR_VERSION;
		static const QString STR_ANN_TYPE;

		/*!
		 * \brief init Initializes everything
		 * \param ann
		 */
		void init(ArtificialNeuralNetwork *ann, Version version);

};

}

#endif // ANNFILE_H
