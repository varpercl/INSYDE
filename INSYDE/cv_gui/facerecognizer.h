#ifndef FACERECOGNIZER_H
#define FACERECOGNIZER_H

#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>

#include "../core/graphicobject.h"
#include "share_cv_gui_lib.h"
#include "facerecognizerpropertydialog.h"

//#include <QtMultimedia>

//#include <mfidl.h>
//#include <mfapi.h>

using namespace cv;
using namespace core;

template <class T> void SafeRelease(T **ppT);

namespace cv_gui
{

class CV_GUI_LIB_IMPORT_EXPORT FaceRecognizer : public GraphicObject
{
	public:

		/*!
		 * \brief Build a face recognizer which is a GraphicObject.
		 */
		explicit FaceRecognizer();

		// GraphicObject interface
		QString getXML() const override;

		void pasteClick() override{}

	protected:

		void propertyClick() override;

	private:
		Q_OBJECT

		Ptr<face::FaceRecognizer> frCore;

		FaceRecognizerPropertyDialog *frpd;

		/*!
		 * \brief Initializes GUI
		 */
		void init();


//		HRESULT CreateVideoDeviceSource(IMFMediaSource **ppSource);
};
}
#endif // FACERECOGNIZER_H
