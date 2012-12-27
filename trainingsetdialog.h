#ifndef TRAININGSETDIALOG_H
#define TRAININGSETDIALOG_H

#include <typeinfo>

#include <QDebug>
#include <InSyDeGui.h>
#include "ui_trainingsetdialog.h"


using namespace std;

class PerceptronTrainingPattern;

namespace Ui{
	class TrainingSetDialog;
}

class TrainingSetDialog : public QDialog
{
	public:

		enum TrainingSetType{
			OnlyInputs,
			MultipleInputsAndTargets,
			MultipleInputsOneTarget
		};

		explicit TrainingSetDialog(TrainingSetType type, QWidget *parent = 0);
		explicit TrainingSetDialog(int inputCount, int targetCount, QWidget *parent = 0);

		vector<vector<double> > getInputs();
		void setInputSize(int size);

		vector<vector<double> > getTargets();
		void setOutputSize(int size);

	signals:

	protected:
		Ui::TrainingSetDialog *ui;

	private slots:

		void on_addPatternButton_clicked();

		void on_delPatternButton_clicked();

	private:
		Q_OBJECT

		QMenuBar *menuBar;
		TrainingSetType tst;
		int inputCount, targetCount;

		vector<vector<double> > inputs, targets;

		void initDialog(int inputs, int outputs);
		void updateHeaders();
		void loadMLPData();

	private slots:
		void fromFile();
};

//template<class TrainingPattern>
//class TrainingSetDialog : public TrainingSetObject
//{
//    public:
//        explicit TrainingSetDialog(QWidget *parent = 0) :
//            TrainingSetObject(parent)
//        {
//            initTS(1);
//        }

//        explicit TrainingSetDialog(int size = 1, QWidget *parent = 0) :
//            TrainingSetObject(parent)
//        {
//            initTS(size);
//        }

//        explicit TrainingSetDialog(const QVector<TrainingPattern> &ts, QWidget *parent = 0) :
//            TrainingSetObject(parent)
//        {
//            initTS(ts);
//        }

//        void setTrainingSet(const QVector<TrainingPattern> &ts){
//            this->ts = ts;
//            ui->patternTable->setRowCount(ts.size());
//        }

//        QVector<TrainingPattern> getTrainingSet() const{
//            return ts;
//        }


//    private:
//        QVector<TrainingPattern> ts;

//        void initTS(QVector<TrainingPattern> ts)
//        {
//            this->ts = ts;
//            ui->patternTable->setRowCount(ts.size());
//            qDebug() << "entro en qvector";
//            initHeaders();
//        }

//        void initTS(int size){
//            ts.resize(size);
//            ui->patternTable->setRowCount(size);
//            qDebug() << "entro en size";
//            initHeaders();
//        }

//        void initHeaders(){
//            std::type_info type = typeid(TrainingPattern);
//            setWindowTitle(type.name());
//            if(strcmp(type.name(), "PerceptronTrainingPattern") == 0){
//                ui->patternTable->setColumnCount(ts[0].getInputs().size() + ts[0].getOutputs().size());
//            }
//        }

//        TrainingPattern getPattern(int index);
//};

#endif // TRAININGSETDIALOG_H
