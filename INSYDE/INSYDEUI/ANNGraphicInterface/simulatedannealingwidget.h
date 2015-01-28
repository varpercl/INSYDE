#ifndef SIMULATEDANNEALINGWIDGET_H
#define SIMULATEDANNEALINGWIDGET_H

#include <QWidget>

#include "ANNFramework/satrainingsettings.h"
#include "../labeledintegerspinboxwidget.h"
#include "../labeleddoublespinboxwidget.h"

class SimulatedAnnealingWidget : public QWidget
{
	public:
		explicit SimulatedAnnealingWidget(QWidget *parent = 0);

		explicit SimulatedAnnealingWidget(double start,
										  int changes,
										  double minTime,
										  double fdec,
										  double itemp,
										  double minNoise,
										  double maxNoise,
										  QWidget *parent = 0);

		void setStartCondition(double sc);
		double getStartCondition() const;

		void setNumberOfChanges(int noc);
		int getNumberOfChanges() const;

		void setMinTemperature(double mt);
		double getMinTemperature() const;

		void setDecTempFactor(double dtf);
		double getDecTempFactor() const;

		void setStartTemperature(double st);
		double getStartTemperature() const;

		void setMinNoise(double mn);
		double getMinNoise() const;

		void setMaxNoise(double mn);
		double getMaxNoise() const;

		void setSASettings(SimulatedAnnealingSettings *sats);
		SimulatedAnnealingSettings *getSimulatedAnnealingSettings();

	signals:

	public slots:


	private:
		Q_OBJECT

		SimulatedAnnealingSettings sats;
		LabeledIntegerSpinBoxWidget *nChanges;

		LabeledDoubleSpinBoxWidget
		*startCondition,
		*minTemperature,
		*decTempFactor,
		*startTemperature,
		*minNoise,
		*maxNoise;

		QVBoxLayout *mainLayout;

		void init(double start,
				  int changes,
				  double minTime,
				  double fdec,
				  double itemp,
				  double minNoise,
				  double maxNoise);

};

#endif // SIMULATEDANNEALINGWIDGET_H
