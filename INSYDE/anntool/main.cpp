
#include <QtCore>
#include <QtWidgets>

#include "../ann_gui/anntrainingdialog.h"

using namespace core;
using namespace ann_gui;

int main(int argc, char *argv[])
{
	//	Q_INIT_RESOURCE(core_media);
	//	Q_INIT_RESOURCE(ann_gui_media);

	QApplication app(argc, argv);

	app.setApplicationName("anntool");
	app.setApplicationVersion("1.0.0");
	app.setApplicationDisplayName("anntool");

	QCommandLineParser *cmdParser = new QCommandLineParser();
	cmdParser->setApplicationDescription("Toolset used to train Artificial Neural Networks");
	cmdParser->addHelpOption();
	cmdParser->addVersionOption();

	QCommandLineOption
			argNonGui("non-gui", QApplication::translate("main", "If passed, the application will run with no graphics.")),
			argTS = QCommandLineOption(QStringList() << "ts" << "training-set",
									   QApplication::translate("main", "The training set to be automatically loaded."),
									   "training-set-file",
									   QApplication::translate("main", "The file path."));


	cmdParser->addOption(argNonGui);
	cmdParser->addOption(argTS);

	cmdParser->process(app);

	QStringList argList = cmdParser->optionNames();

	if(cmdParser->isSet(argNonGui))
	{



	}
	else
	{
		vector<int> capas = {100};
		MultilayerPerceptron *mlp = new MultilayerPerceptron(403, 36, capas);

		ANNTrainingDialog *annd = new ANNTrainingDialog(mlp, new TrainingSet(mlp));
		annd->canSave(true);
		annd->canSaveAs(true);
		annd->canOpenFile(true);

		annd->showMaximized();
		return app.exec();
	}

	return -1;
}
