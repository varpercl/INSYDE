#ifndef TRAININGSETSQL_H
#define TRAININGSETSQL_H

#include <QtSql>

namespace ann_base{

/*!
 * \brief The TrainingSetSQL class
 */
class TrainingSetSQL : public QSqlTableModel
{
	public:

		/*!
		 * \brief TrainingSetSQL
		 */
		explicit TrainingSetSQL(const QString &table, QSqlDatabase *db);
};

}


#endif // TRAININGSETSQL_H
