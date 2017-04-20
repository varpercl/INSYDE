#include "facerecognizerpropertydialog.h"

cv_gui::FaceRecognizerPropertyDialog::FaceRecognizerPropertyDialog(FaceRecognizer *fr, QWidget *parent) :
	PropertiesDialog(reinterpret_cast< GraphicObject * >(fr), parent),
	choosenCamera(nullptr)
{
	init();
}

cv_gui::FaceRecognizerPropertyDialog::~FaceRecognizerPropertyDialog()
{
	choosenCamera->stop();

	delete choosenCamera;
}

void cv_gui::FaceRecognizerPropertyDialog::init()
{
	innerWidget = new QWidget();

	vlyMainLayout = new QVBoxLayout();

	cbDevices = new QComboBox();

	cameraView = new QCameraViewfinder();
//	cbDevices->addItems(QStringList() << "Device1" << "Device2");

	cameraView->setBaseSize(QSize(300, 300));

	vlyMainLayout->addWidget(cbDevices);
	vlyMainLayout->addWidget(cameraView);

	innerWidget->setLayout(vlyMainLayout);

	updateCameraList();

	getMainWindow()->setCentralWidget(innerWidget);

	connect(cbDevices, SIGNAL(currentIndexChanged(QString)), SLOT(onCameraSelected(QString)));

}

void cv_gui::FaceRecognizerPropertyDialog::updateCameraList()
{
	cameras = QCameraInfo::availableCameras();

	cbDevices->addItem(tr("Select camera..."));
	foreach(const QCameraInfo &camera, cameras){
		cbDevices->addItem(camera.description());
	}
}

QCameraInfo cv_gui::FaceRecognizerPropertyDialog::findCameraByName(const QString &name)
{
	foreach(QCameraInfo camInfo, cameras){
		if(camInfo.deviceName() == name)
		{
			return camInfo;
		}
	}
	return QCameraInfo();
}

QCameraInfo cv_gui::FaceRecognizerPropertyDialog::findCameraByDescription(const QString &desc)
{
	foreach(QCameraInfo camInfo, cameras){
		if(camInfo.description() == desc)
		{
			return camInfo;
		}
	}

	return QCameraInfo();
}

void cv_gui::FaceRecognizerPropertyDialog::onCameraSelected(const QString &item)
{
	if(!choosenCamera)
		choosenCamera = new QCamera(findCameraByDescription(item));

	if(choosenCamera->isAvailable())
	{
		choosenCamera->setCaptureMode(QCamera::CaptureVideo);
		choosenCamera->setViewfinder(cameraView);
		choosenCamera->start();
		qDebug() << choosenCamera->errorString();
	}
}
