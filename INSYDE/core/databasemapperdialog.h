#ifndef DBMAPPERDIALOG_H
#define DBMAPPERDIALOG_H

#include <QtCore>
#include <QtSql>

#include "basicdialog.h"
#include "labeledcombobox.h"

namespace core{


class CORE_LIB_IMPORT_EXPORT DatabaseMapperDialog : public BasicDialog
{
	public:
		explicit DatabaseMapperDialog(const QSqlDatabase &db, QWidget *parent = Q_NULLPTR);

		QMap<QString, QString> getMap();


	public slots:

		void updateConnection();

	private:
		Q_OBJECT

		QTableWidget *tblMapView;

		QVBoxLayout *_loMain;

		LabeledComboBox *_lcbTables;

		QSqlDatabase _db;

		void init(const QSqlDatabase &db);

		void fillTable(const QString &sqlTableName);
};

}
#endif // DBMAPPERDIALOG_H
