#include "trainingsetsql.h"

ann_base::TrainingSetSQL::TrainingSetSQL(const QString &table, QSqlDatabase *db) :
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
