#ifndef TRAININGSETFILE_H
#define TRAININGSETFILE_H

#include <QtCore>

#include "share_ann_base_lib.h"
#include "globals.h"
#include "trainingset.h"

#include "../core/datarepresentation.h"
#include "../core/normalization.h"


class Normalization;

namespace ann_base{

	class TrainingSet;

	/*!
 * \class
 *
 * \brief Maneja archivos del tipo .tsf los cuales contienen conjuntos de entrenamiento estructurados.
 *
 * Es indispensable para almacenar y cargar la informacion hacia y desde el disco duro o cualquier otro medio de
 * almacenamiento de modo que esta pueda persistir en un archivo XML comprimido.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 023/02/2015
 */
class ANN_BASE_LIB_IMPORT_EXPORT TrainingSetFile : public QFile
{
	public:

		/*!
		 * \brief The TSFError enum Contiene una compilacion de los posibles errores generados cuando se manipulan
		 * archivos del tipo \code{TrainingSetFile}. Ya que este hereda de la clase \code{QFile} y hace uso de
		 * \code{QXmlStreamReader} y \code{QXmlStreamWriter} los cuales tienen sus propios errores.
		 */
		enum TSFError{
			NoError,
			ReadError,
			WriteError,
			FatalError,
			ResourceError,
			OpenError,
			AbortError,
			TimeOutError,
			UnspecifiedError,
			RemoveError,
			RenameError,
			PositionError,
			ResizeError,
			PermissionsError,
			CopyError,
			UnexpectedElementError,
			CustomError,
			NotWellFormedError,
			PrematureEndOfDocumentError,
		};

		/*!
		 * \brief The TSFResult struct contiene un resultado generado al abrir un archivo
		 */
		struct TSFResult{
			public:
				TrainingSetFile *file;
//				TrainingSet *ts;
				bool sucess;
				TSFError errnum;
				QString errormsg;
				qint64 line;
		};

		explicit TrainingSetFile();
		explicit TrainingSetFile(const QString &path);
		explicit TrainingSetFile(TrainingSet *ts, const QString &path);
		TrainingSetFile(const TrainingSetFile &tsf);

		/*!
		 * \brief flush Descarga toda la informacion del conjunto de entrenamiento en un archivo.
		 * \return
		 */
		bool flush();

		/*!
		 * \brief setTrainingSet
		 * \param ts
		 */
		void setTrainingSet(TrainingSet *ts);

		/*!
		 * \brief getTrainingSet
		 * \return
		 */
		TrainingSet *getTrainingSet() const;

		/*!
		 * \brief setFormat Establece el formato decimal con el cual se almacenar la informacion en el archivo
		 * \param f Indica el formato que se asignara
		 * Vease \code{QString::number()} para una descripcion detallada de los tipos de formatos definitos por Qt.
		 * \see getFormat
		 */
		void setFormat(char f);

		/*!
		 * \brief getFormat Devuelve el formato decimal que sera utilizado para almacenar la informacion en el archivo
		 * \return Devuelve un caracter que describe el formato
		 * Vease \code{QString::number()} para una descripcion detallada de los tipos de formatos definitos por Qt.
		 *
		 * \see setFormat
		 */
		char getFormat() const;

		/*!
		 * \brief setDecimals Establece el numero de decimales que tendran los formatos numericos.
		 *
		 * \param d Indica el numero de decimales.
		 *
		 * \see getDecimals
		 */
		void setDecimals(int d);

		/*!
		 * \brief getDecimals Devuelve el numero de decimales que tendran los formatos numericos
		 * \return Numero de decimales.
		 *
		 * \see setDecimals
		 */
		int getDecimals() const;

		/*!
		 * \brief setVersion Establece la version que tendra el archivo, Por defecto la version es 1.0.0
		 * \param ver Version del archivo que se creara
		 *
		 * \see getVersion
		 */
		void setVersion(const QString &ver = "1.0.0");

		/*!
		 * \brief getVersion Devuelve la version en la que se almacenara el archivo.
		 *
		 * \return Devuelve una cadena que representa la version del archivo
		 */
		QString getVersion() const;

		/*!
		 * \brief load Carga toda la informacion en el objeto \code{TrainingSetFile} proveniente de un archivo.
		 * \return
		 */
		TSFResult load();

		/*!
		 * \brief fromFile Crea un par de objetos que contiene un Conjunto de entrenamiento (\code{TrainingSet}) y un objeto \code{Error}
		 * que indica si ocurrio algun error al cargar el archivo.
		 *
		 *
		 * \param path Indica la ruta donde esta almacenado el archivo
		 * \return Un objeto \code{QPair} que almacena a su vez dos objetos \code{TrainingSet} y \code{Error}
		 */
		static TSFResult fromFile(const QString &path);

		/*!
		 * \brief fromFile
		 * \param file
		 * \return
		 */
		static TSFResult fromFile(QFile &file);

		//		TSFError error() const;

	protected:
		static TSFError toTSFError(const QFile::FileError &tsferr);
		static TSFError toTSFError(const QXmlStreamReader::Error &tsferr);

	private:
		Q_OBJECT

		static const QString STR_TRAININGSET;
		static const QString STR_PROPERTIES;
		static const QString STR_INPUTSDATAREPRESENTATION;
		static const QString STR_TARGETSDATAREPRESENTATION;
		static const QString STR_VERSION;
		static const QString STR_INPUTSNORMALIZATION;
		static const QString STR_TARGETSNORMALIZATION;
		static const QString STR_PATTERN;
		static const QString STR_INPUTS;
		static const QString STR_TARGETS;
		static const QString STR_NAME;
		static const QString STR_FORMAT;
		static const QString STR_WIDTH;
		static const QString STR_HEIGHT;
		static const QString STR_INPUTSSIZE;
		static const QString STR_TARGETSSIZE;
		static const QString STR_PATTERNSIZE;
		static const QString STR_TYPE;
		static const QString STR_MAXVALUE;
		static const QString STR_MINVALUE;
		static const QString STR_THRESHOLD;
		static const QString STR_AMPLITUDE;
		static const QString STR_ELONGATION;
		static const QString STR_INDEX;
		static const QString STR_SEPARATOR;

		QString	version;

		int decimals; /**< Describe el numero de decimales que se almacenaran */


		char decimalformat; /**< Describe en que formato se almacenaran los numeros con decimales */


		TrainingSet *ts;
		//		QXmlStreamWriter tsWriteXML;

		void init(TrainingSet *ts);

		static Normalization::Type normFromStrToInt(const QString &str);
		static DataRepresentation::Type drFromStrToInt(const QString &str);
		static QImage::Format fromStrToImgFormat(const QString &str);

};
}

#endif // TRAININGSETFILE_H
