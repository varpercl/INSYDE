#ifndef DATABASECONNECTIONDIALOG_H
#define DATABASECONNECTIONDIALOG_H

#include <QtWidgets>
#include <QtSql>

#include "definitions.h"
#include "extendedlineedit.h"
#include "basicdialog.h"
#include "labeledcombobox.h"

namespace core {

class CORE_LIB_IMPORT_EXPORT DatabaseConnectionDialog : public BasicDialog
{
	public:

		explicit DatabaseConnectionDialog(QWidget *parent = Q_NULLPTR);


		QSqlDatabase getDatabase();

		QString getDatabaseName() const;
		QString getHost() const;
		QString getUser() const;
		QString getPassword() const;

		QString getDatabaseType() const;
	public slots:
		/*!
		 * \brief Test the current connection with the given paramters.
		 * \showMessageDialog Determines if should show a dialog when test has finished.
		 * \return True in case of succesfully connection
		 */
		bool testConnection(bool showMessageDialog = true);

		bool connectDb();
	private:
		Q_OBJECT

		QVBoxLayout *mainLayout;
		QHBoxLayout *bottomLayout;

		ExtendedLineEdit
		*eleConnName,
		*eleDB,
		*eleHost,
		*elePassword,
		*eleUser;

		LabeledComboBox *lcbDBType;

		QPushButton
		*btnTest;

		QSqlDatabase db;

		void init();


};

}

#endif // DATABASECONNECTIONDIALOG_H
