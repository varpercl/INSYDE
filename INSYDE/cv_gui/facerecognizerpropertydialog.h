#ifndef FACERECOGNIZERPROPERTYDIALOG_H
#define FACERECOGNIZERPROPERTYDIALOG_H

#include "../core/graphicobjectpropertydialog.h"
#include "share_cv_gui_lib.h"

#include <QtMultimedia>
#include <QtMultimediaWidgets>

//#include "facerecognizer.h"

using namespace core;

namespace cv_gui
{

class FaceRecognizer;

class CV_GUI_LIB_IMPORT_EXPORT FaceRecognizerPropertyDialog : public PropertiesDialog
{
	public:

		/*!
		 * \brief Creates a property dialog that enables user to set up a FaceRecognizer
		 * \param[in] parent The parent of this dialog.
		 */
		explicit FaceRecognizerPropertyDialog(FaceRecognizer *fr, QWidget *parent = 0);

		~FaceRecognizerPropertyDialog();

	private:
		Q_OBJECT

		FaceRecognizer *fr;

		QVBoxLayout *vlyMainLayout;
		QWidget *innerWidget;
		QComboBox *cbDevices;

		QCameraViewfinder *cameraView;
		QCamera *choosenCamera;
		QList<QCameraInfo> cameras;

		/*!
		 * \brief Initializes the GUI.
		 */
		void init();

		/*!
		 * \brief Update the combo box camera list.
		 */
		void updateCameraList();

		/*!
		 * \brief Performs a by-name search over the current camera list.
		 * \param name The desired name to find out.
		 * \return The associated camera info object.
		 */
		QCameraInfo findCameraByName(const QString &name);

		/*!
		 * \brief Performs a by-description search over the current camera list.
		 * \param name The desired name to find out.
		 * \return The associated camera info object.
		 */
		QCameraInfo findCameraByDescription(const QString &desc);

	private slots:

		/*!
		 * \brief Update the current camera device depending on the selection of the user at the combo box.
		 * \param item The current selected item.
		 */
		void onCameraSelected(const QString &item);

};

}
#endif // FACERECOGNIZERPROPERTYDIALOG_H
