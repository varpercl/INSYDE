#ifndef TRAININGSETSQL_H
#define TRAININGSETSQL_H

#include <QtCore>
#include <QtSql>

#include "share_ann_base_lib.h"

namespace ann_base{

/*!
 * \brief The TrainingSetSQL class
 */
class ANN_BASE_LIB_IMPORT_EXPORT TrainingSetSQL : public QSqlTableModel
{
	public:

		explicit TrainingSetSQL();
		/*!
		 * \brief TrainingSetSQL
		 */
		explicit TrainingSetSQL(const QString &table, const QMap<QString, QString> &mappedColumns, const QSqlDatabase &db);

};

}


#endif // TRAININGSETSQL_H
