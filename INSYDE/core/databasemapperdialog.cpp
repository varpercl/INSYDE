#include "databasemapperdialog.h"

core::DatabaseMapperDialog::DatabaseMapperDialog(const QSqlDatabase &db, QWidget *parent) :
	BasicDialog(parent)
{
	init(db);
}

QMap<QString, QString> core::DatabaseMapperDialog::getMap()
{
	QMap<QString, QString> res;

	if(exec() == QDialog::Accepted)
	{
		qint16 rows = tblMapView->rowCount();

		bool fieldEnabled = false;

		for(qint16 i = 0; i < rows; i++){

//			fieldEnabled = tblMapView->item(i, 2);
//			if(tblMapView->)
		}
	}
	return res;
}

void core::DatabaseMapperDialog::updateConnection()
{

}

void core::DatabaseMapperDialog::init(const QSqlDatabase &db)
{

	_loMain = new QVBoxLayout();

	_lcbTables = new LabeledComboBox(tr("Tables"));

	tblMapView = new QTableWidget(1, 4);

	tblMapView->verticalHeader()->setVisible(false);


	if(db.isOpen()){
		_lcbTables->getComboBox()->addItems(db.tables(QSql::Tables));
		_lcbTables->getComboBox()->addItems(db.tables(QSql::Views));
	}

	_loMain->addWidget(_lcbTables);
	_loMain->addWidget(tblMapView);

	getMainToolbar()->addAction(ICON_UPDATE, tr("Update"), this, SLOT(updateConnection()));

	getMainMenuBar()->setVisible(false);
	setApplyButtonVisible(false);

	getMainWindow()->centralWidget()->setLayout(_loMain);

	_db = db;

	connect(_lcbTables->getComboBox(), &QComboBox::currentTextChanged, [=](const QString &text){
		fillTable(text);
	});

	fillTable(_lcbTables->getComboBox()->currentText());
}

void core::DatabaseMapperDialog::fillTable(const QString &sqlTableName)
{
	if(!_db.isOpen()) _db.open();

	QString strQuery = "show columns from " + sqlTableName;

	QSqlQuery query(strQuery, _db);

	tblMapView->clear();

	tblMapView->setHorizontalHeaderLabels(QStringList()
										  << tr("Source columns")
										  << tr("Map to")
										  << tr("Field type")
										  << tr("Enabled"));
	while(query.next())
	{
		tblMapView->setItem(tblMapView->rowCount() - 1, 0, new QTableWidgetItem(query.value("Field").toString()));
		tblMapView->setItem(tblMapView->rowCount() - 1, 1, new QTableWidgetItem(tr("in")));

		QComboBox *cb = new QComboBox();
		cb->addItems(QStringList()
					 << tr("Input")
					 << tr("Target"));
		tblMapView->setCellWidget(tblMapView->rowCount() - 1, 2, cb);

		QCheckBox *tbw = new QCheckBox();
		tbw->setCheckState(Qt::Checked);
		tblMapView->setItem(tblMapView->rowCount() - 1, 3, new QTableWidgetItem());
		tblMapView->setCellWidget(tblMapView->rowCount() - 1, 3, tbw);
		tblMapView->item(tblMapView->rowCount() - 1, 3)->setTextAlignment(Qt::AlignLeft);

		tblMapView->insertRow(tblMapView->rowCount());
	}
}
