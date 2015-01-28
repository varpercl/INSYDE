#ifndef TRAININGSETFILE_H
#define TRAININGSETFILE_H

#include "trainingset.h"
#include "ANNglobal.h"

#include <QStringList>
#include <QFile>
#include <QXmlStreamWriter>

class ANNFRAMEWORK_EXPORT TrainingSetFile : public QFile
{
	public:

		//TODO: ampliar los tipos de errores que se pueden presentar
		struct Error{
				bool sucess;
				QXmlStreamReader::Error errnum;
				QString errormsg;
				qint64 line;
		};

		explicit TrainingSetFile();
		explicit TrainingSetFile(const QString &path);
		explicit TrainingSetFile(TrainingSet *ts, const QString &path);
		TrainingSetFile(const TrainingSetFile &tsf);

//		void save(const QString &path);
		/*!
		 * \brief flush Descarga toda la informacion del conjunto de entrenamiento en un archivo.
		 * \return
		 */
		bool flush();

		/*!
		 * \brief load Carga toda la informacion en el objeto \code{TrainingSetFile} proveniente de un archivo.
		 * \return
		 */
		Error load();

		void setTrainingSet(TrainingSet *ts);
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
		 * \brief fromFile Crea un par de objetos que contiene un Conjunto de entrenamiento (\code{TrainingSet}) y un objeto \code{Error}
		 * que indica si ocurrio algun error al cargar el archivo.
		 *
		 *
		 * \param path Indica la ruta donde esta almacenado el archivo
		 * \return Un objeto \code{QPair} que almacena a su vez dos objetos \code{TrainingSet} y \code{Error}
		 */
		static QPair<TrainingSet *, Error> fromFile(const QString &path);

		/*!
		 * \brief fromFile
		 * \param file
		 * \return
		 */
		static QPair<TrainingSet*, Error> fromFile(QFile &file);

		/*!
		 * \brief setInputsWidth
		 * \param inputswidth
		 */
		void setInputsWidth(int inputswidth);

		/*!
		 * \brief getInputsWidth
		 * \return
		 */
		int getInputsWidth() const;

		/*!
		 * \brief setInputsHeight
		 * \param inputsheight
		 */
		void setInputsHeight(int inputsheight);

		/*!
		 * \brief getInputsHeight
		 * \return
		 */
		int getInputsHeight() const;

		void setInputsDataRepresentation(const QString &rep);

		QString getInputsDataRepresentation() const;

		/*!
		 * \brief setTargetsWidth
		 * \param width
		 */
		void setTargetsWidth(int width);

		/*!
		 * \brief getTargetsWidth
		 * \return
		 */
		int getTargetsWidth() const;

		/*!
		 * \brief setTargetsHeight
		 * \param height
		 */
		void setTargetsHeight(int height);

		/*!
		 * \brief getTargetsHeight
		 * \return
		 */
		int getTargetsHeight() const;

		void setTargetsDataRepresentation(const QString &rep);

		QString getTargetsDataRepresentation() const;

	private:
		Q_OBJECT

		static const QString STR_TAG_TRAINING_SET;
		static const QString STR_TAG_PROPERTIES;
		static const QString STR_TAG_INPUTS_DATA_REPRESENTATION;
		static const QString STR_TAG_TARGETS_DATA_REPRESENTATION;
		static const QString STR_TAG_VERSION;
		static const QString STR_TAG_INPUTS_NORMALIZATION;
		static const QString STR_TAG_TARGETS_NORMALIZATION;
		static const QString STR_TAG_PATTERN;
		static const QString STR_TAG_INPUTS;
		static const QString STR_TAG_TARGETS;
		static const QString STR_ATTR_NAME;
		static const QString STR_ATTR_WIDTH;
		static const QString STR_ATTR_HEIGHT;
		static const QString STR_ATTR_INPUTS_SIZE;
		static const QString STR_ATTR_TARGETS_SIZE;
		static const QString STR_ATTR_PATTERN_SIZE;
		static const QString STR_ATTR_VERSION;
		static const QString STR_ATTR_TYPE;
		static const QString STR_ATTR_MAX_VALUE;
		static const QString STR_ATTR_MIN_VALUE;
		static const QString STR_ATTR_THRESHOLD;
		static const QString STR_ATTR_AMPLITUDE;
		static const QString STR_ATTR_ELONGATION;
		static const QString STR_ATTR_INDEX;
		static const QString STR_SEPARATOR;

		QString

		version,
		inputsdatarepresentation,
		targetsdatarepresentation;

		int
		//Describe el numero de decimales que se almacenaran
		decimals,

		//En el caso de tener una representacion grafica de los datos estas variables indicaran el ancho y lo alto.
		inputswidth,
		inputsheight,
		targetswidth,
		targetsheight;

		//Describe en que formato se almacenaran los numeros con decimales
		char decimalformat;


		TrainingSet *ts;
		QXmlStreamWriter tsWriteXML;
		QXmlStreamReader tsReadXML;

		void init(TrainingSet *ts);

		static Normalization::Type fromStringToInt(const QString &str);
};

#endif // TRAININGSETFILE_H
