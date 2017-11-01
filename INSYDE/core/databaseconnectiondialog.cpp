#include "databaseconnectiondialog.h"


core::DatabaseConnectionDialog::DatabaseConnectionDialog(QWidget *parent) :
	BasicDialog(parent)
{
	init();
}

QSqlDatabase core::DatabaseConnectionDialog::getDatabase()
{
//	DatabaseConnectionDialog *dbcd = new DatabaseConnectionDialog();

//	QSqlDatabase *db = new QSqlDatabase();

OPEN_DIALOG_AGAIN:

	if(exec() == QDialog::Accepted)
	{
//		if(!db) db = new QSqlDatabase("QMYSQL");

		db = QSqlDatabase::addDatabase(getDatabaseType());
		db.setDatabaseName(getDatabaseName());
		db.setUserName(getUser());
		db.setPassword(getPassword());

		if(db.open())
		{
			accept();
			return db;
		}
		else
		{
			QMessageBox msg;
			msg.setText(tr("Could not connect to database!\r\n") + QString::number(db.lastError().number()) + ": " + db.lastError().text());

			msg.exec();

			goto OPEN_DIALOG_AGAIN;
		}
	}
	return QSqlDatabase();
}

QString core::DatabaseConnectionDialog::getDatabaseName() const
{
	return eleDB->getText();
}

QString core::DatabaseConnectionDialog::getHost() const
{
	return eleHost->getText();
}

QString core::DatabaseConnectionDialog::getUser() const
{
	return eleUser->getText();
}

QString core::DatabaseConnectionDialog::getPassword() const
{
	return elePassword->getText();
}

QString core::DatabaseConnectionDialog::getDatabaseType() const
{
	switch (lcbDBType->getComboBox()->currentIndex()) {
		case 0:
			return "QMYSQL";
		default:
			return "";
	}
}

bool core::DatabaseConnectionDialog::testConnection(bool showMessageDialog)
{
	if(connectDb())
	{
		if(showMessageDialog)
		{
//			QMessageBox *msg = new QMessageBox();
//			msg->setText(tr("Sucesfully connected!"));
			QMessageBox::information(this, tr("Test sucessfull"), tr("Sucesfully connected!"));
//			msg->setIcon(QMessageBox::Information);
//			msg->exec();
		}
		return true;
	}
	else
	{
		if(showMessageDialog)
		{
//			QMessageBox *msg = new QMessageBox();
//			msg->setText(tr("Could not connect to database ") + db->lastError().nativeErrorCode() + ": " + db->lastError().text());
			QSqlError err = db.lastError();
			QMessageBox::critical(this, tr("Could not connect"), tr("Could not connect to database.\r\n") + err.nativeErrorCode() + ": " + err.text());
//			msg->setIcon(QMessageBox::Critical);
//			msg->exec();
		}
		return false;
	}
	return false;
}

void core::DatabaseConnectionDialog::init()
{
//	db = Q_NULLPTR;

	eleDB = new ExtendedLineEdit(tr("Database name"), "crypto_predictions");
	eleConnName = new ExtendedLineEdit(tr("Connection name"));
	eleHost = new ExtendedLineEdit(tr("Host"), "localhost");
	eleUser = new ExtendedLineEdit(tr("User"), "crypto_dev");
	elePassword = new ExtendedLineEdit(tr("Password"), "edixon100986");

	btnTest = new QPushButton(ICON_TEST, "Test connection");

	lcbDBType = new LabeledComboBox(tr("Database type"),
									QStringList()
									<< "MySQL"
//									<< "Oracle"
//									<< "SQL Server"
//									<< "Postgre SQL"
									);

	mainLayout = new QVBoxLayout();
	bottomLayout = new QHBoxLayout();

	((QGridLayout*)lcbDBType->getLayout())->setColumnMinimumWidth(0, 100);
	((QGridLayout*)eleConnName->getLayout())->setColumnMinimumWidth(0, 100);
	((QGridLayout*)eleDB->getLayout())->setColumnMinimumWidth(0, 100);
	((QGridLayout*)eleHost->getLayout())->setColumnMinimumWidth(0, 100);
	((QGridLayout*)eleUser->getLayout())->setColumnMinimumWidth(0, 100);
	((QGridLayout*)elePassword->getLayout())->setColumnMinimumWidth(0, 100);

	elePassword->getLineEdit()->setEchoMode(QLineEdit::Password);
	getMainMenuBar()->setVisible(false);
	getMainToolbar()->setVisible(false);
	setApplyButtonVisible(false);
	insertButton(0, btnTest);

	mainLayout->addWidget(lcbDBType);
//	mainLayout->addWidget(eleConnName);
	mainLayout->addWidget(eleDB);
	mainLayout->addWidget(eleHost);
	mainLayout->addWidget(eleUser);
	mainLayout->addWidget(elePassword);

	connect(btnTest, &QPushButton::clicked, [=]{
		testConnection();
	});

	getMainWindow()->centralWidget()->setLayout(mainLayout);
}

bool core::DatabaseConnectionDialog::connectDb()
{
//	if(!db) db = &QSqlDatabase::addDatabase("QMYSQL");

	switch(lcbDBType->getComboBox()->currentIndex())
	{
		case 0:
			db = QSqlDatabase::addDatabase("QMYSQL");
			break;
		case 1:
		case 2:
		case 3:
		default:
			break;
	}
//	db->setConnectOptions();
	db.setDatabaseName(eleDB->getText());
	db.setHostName(eleHost->getText());
	db.setUserName(eleUser->getText());
	db.setPassword(elePassword->getText());

	return db.open();
}
