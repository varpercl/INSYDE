#ifndef DATABASECONNECTIONDIALOG_H
#define DATABASECONNECTIONDIALOG_H

#include "definitions.h"
#include "basicdialog.h"


namespace core {

class CORE_LIB_IMPORT_EXPORT DatabaseConnectionDialog : public BasicDialog
{
	public:
		explicit DatabaseConnectionDialog();


	private:
		Q_OBJECT

		void init();
};

}

#endif // DATABASECONNECTIONDIALOG_H
