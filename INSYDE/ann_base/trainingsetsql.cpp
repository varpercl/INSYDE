#include "trainingsetsql.h"

ann_base::TrainingSetSQL::TrainingSetSQL() :
	QSqlTableModel(Q_NULLPTR)
{

}

ann_base::TrainingSetSQL::TrainingSetSQL(const QString &table, const QMap<QString, QString> &mappedColumns, const QSqlDatabase &db) :
	QSqlTableModel(Q_NULLPTR, db)
{
	setTable(table);
	setEditStrategy(QSqlTableModel::OnManualSubmit);
	select();
//	if(!db->isOpen())
//	{
//		if(db->open())
//		{

//		}
//	}
}
