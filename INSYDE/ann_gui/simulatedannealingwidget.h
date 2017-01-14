#ifndef SIMULATEDANNEALINGWIDGET_H
#define SIMULATEDANNEALINGWIDGET_H

#include <QtGui>

#include "share_ann_gui_lib.h"
#include "../ann_base/satrainingsettings.h"
#include "../core/labeledintegerspinbox.h"
#include "../core/labeleddoublespinbox.h"

using namespace core;
using namespace ann_base;

namespace ann_gui
{

/*!
 * \class
 *
 * \brief The SimulatedAnnealingWidget class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class ANN_GUI_LIB_IMPORT_EXPORT SimulatedAnnealingWidget : public QWidget
{
	public:
		explicit SimulatedAnnealingWidget(QWidget *parent = 0);

		explicit SimulatedAnnealingWidget(double start,
										  int samples,
										  int changes,
										  double minTemp,
										  double fdec,
										  double itemp,
										  double minNoise,
										  double maxNoise,
										  QWidget *parent = 0);

		void setSamples(int samples);
		int getSamples() const;

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
		LabeledIntegerSpinBox
		*nChanges,
		*lisbSamples;

		LabeledDoubleSpinBox
		*startCondition,
		*minTemperature,
		*decTempFactor,
		*startTemperature,
		*minNoise,
		*maxNoise;

		QVBoxLayout *mainLayout;

		void init(int samples,
				  double start,
				  int changes,
				  double minTime,
				  double fdec,
				  double itemp,
				  double minNoise,
				  double maxNoise);

};
}
#endif // SIMULATEDANNEALINGWIDGET_H
