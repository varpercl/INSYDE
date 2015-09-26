#ifndef STATUSANIMATION_H
#define STATUSANIMATION_H

#include <QtWidgets>

#include "../core/common.h"

enum Status{
	Running,
	Paused,
	Stopped
};

/**
  @class StatusAnimationControl
  @author Edixon Vargas
  @date 08-06-2012

  La clase @code{StatusAnimationControl} brinda el control de una simulacion de cualquier sistema, ademas tiene los controles
  primarios como reproducir, pausa y stop.

  */

/*!
 * \brief La clase @code{StatusAnimationControl} brinda el control de una simulacion de cualquier sistema, ademas tiene
 * los controles primarios como reproducir, pausa y stop.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT StatusAnimationControl : public QFrame
{
	private:
		Q_OBJECT

		Status status;

		QIcon normalPlayIcon, normalPauseIcon, normalStopIcon;
		QIcon disabledPlayIcon, disabledPauseIcon, disabledStopIcon;
		QHBoxLayout *design;
		QPushButton *playPauseButton;
		QPushButton *stopButton;

		void iniciarStatusAnimation();

	public:
		explicit StatusAnimationControl(QWidget *parent = 0);

		Status getCurrentStatus();

	signals:
		void pause();
		void run();
		void stop();
		void statusChanged(Status current, Status before);

	protected slots:
		void playPauseClick();
		void stopClick();
};

#endif // STATUSANIMATION_H
