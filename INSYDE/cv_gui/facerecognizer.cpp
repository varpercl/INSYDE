#include "facerecognizer.h"

cv_gui::FaceRecognizer::FaceRecognizer() :
	GraphicObject()
{
	init();
}

QString cv_gui::FaceRecognizer::getXML() const
{
	return "";
}

void cv_gui::FaceRecognizer::propertyClick()
{
	if(!frpd)
	{
		frpd = new FaceRecognizerPropertyDialog(this);
	}

	if(frpd->exec() == QDialog::Accepted)
	{

	}
}

void cv_gui::FaceRecognizer::init()
{
	frpd = nullptr;
	frCore = face::createEigenFaceRecognizer();

	cv::VideoCapture vid(0);

//	IMFMediaSource **sources;

//	*sources = (IMFMediaSource*) malloc(sizeof(IMFMediaSource));

//	CreateVideoDeviceSource(sources);


}

//HRESULT cv_gui::FaceRecognizer::CreateVideoDeviceSource(IMFMediaSource **ppSource)
//{
//	*ppSource = NULL;

//	IMFMediaSource *pSource = NULL;
//	IMFAttributes *pAttributes = NULL;
//	IMFActivate **ppDevices = NULL;

//	// Create an attribute store to specify the enumeration parameters.
//	HRESULT hr = MFCreateAttributes(&pAttributes, 1);
//	if (FAILED(hr))
//	{
//		goto done;
//	}

//	// Source type: video capture devices
//	hr = pAttributes->SetGUID(
//				MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE,
//				MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID
//				);
//	if (FAILED(hr))
//	{
//		goto done;
//	}

//	// Enumerate devices.
//	UINT32 count;
//	hr = MFEnumDeviceSources(pAttributes, &ppDevices, &count);
//	if (FAILED(hr))
//	{
//		goto done;
//	}

//	if (count == 0)
//	{
//		hr = E_FAIL;
//		goto done;
//	}

//	// Create the media source object.
//	hr = ppDevices[0]->ActivateObject(IID_PPV_ARGS(&pSource));
//	if (FAILED(hr))
//	{
//		goto done;
//	}

//	*ppSource = pSource;
//	(*ppSource)->AddRef();

//done:
//	SafeRelease(&pAttributes);

//	for (DWORD i = 0; i < count; i++)
//	{
//		SafeRelease(&ppDevices[i]);
//	}
//	CoTaskMemFree(ppDevices);
//	SafeRelease(&pSource);
//	return hr;
//}

template <class T> void SafeRelease(T **ppT)
{
	if (*ppT)
	{
		(*ppT)->Release();
		*ppT = NULL;
	}
}
