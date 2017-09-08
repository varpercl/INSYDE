#include "datarepresentation.h"

core::DataRepresentation::DataRepresentation()
{
//    Q_INIT_RESOURCE(core_media); //At least in linux, never call this inside user namespace, instead use a wrapper function
	init(Raw, QImage::Format_RGB32, 1, 1);
}

core::DataRepresentation::DataRepresentation(const core::DataRepresentation::Type &type, const QImage::Format &imgFormat, int w, int h)
{
//    Q_INIT_RESOURCE(core_media);
	init(type, imgFormat, w, h);
}

core::DataRepresentation::DataRepresentation(const core::DataRepresentation &dr)
{
	*this = dr;
}

core::DataRepresentation::~DataRepresentation()
{

}

core::DataRepresentation::Type core::DataRepresentation::getType() const
{
	return type;
}

void core::DataRepresentation::setType(const DataRepresentation::Type &value)
{
	type = value;
}

QString core::DataRepresentation::getName() const
{
	switch (type) {
		case DataRepresentation::Raw:
			return "Raw";
		case DataRepresentation::Image:
			return "Image";
		case DataRepresentation::DotMatrix:
			return "DotMatrix";
		case DataRepresentation::Sound:
			return "Sound";
		case DataRepresentation::Text:
			return "Text";
		case DataRepresentation::Chart:
			return "Chart";
	}
	return "";
}

int core::DataRepresentation::getWidth() const
{
	return width;
}

void core::DataRepresentation::setWidth(int value)
{
	if(value >= 0){
		width = value;
	}
}

int core::DataRepresentation::getHeight() const
{
	return height;
}

void core::DataRepresentation::setHeight(int value)
{
	if(value >= 0){
		height = value;
	}
}

void core::DataRepresentation::setSize(const QSize &size)
{
	height = size.height();
	width = size.width();
}

QSize core::DataRepresentation::getSize() const
{
	return QSize(width, height);
}

QImage::Format core::DataRepresentation::getImageFormat() const
{
	return imageFormat;
}

void core::DataRepresentation::setImageFormat(const QImage::Format &value)
{
	imageFormat = value;
}

QString core::DataRepresentation::getImageFormatName() const
{
	switch(imageFormat){
		case QImage::Format_Invalid:
			return "Format_Invalid";
		case QImage::Format_Mono:
			return "Format_Mono";
		case QImage::Format_MonoLSB:
			return "Format_MonoLSB";
		case QImage::Format_Indexed8:
			return "Format_Indexed8";
		case QImage::Format_RGB32:
			return "Format_RGB32";
		case QImage::Format_ARGB32:
			return "Format_ARGB32";
		case QImage::Format_ARGB32_Premultiplied:
			return "Format_ARGB32_Premultiplied";
		case QImage::Format_RGB16:
			return "Format_RGB16";
		case QImage::Format_ARGB8565_Premultiplied:
			return "Format_ARGB8565_Premultiplied";
		case QImage::Format_RGB666:
			return "Format_RGB666";
		case QImage::Format_ARGB6666_Premultiplied:
			return "Format_ARGB6666_Premultiplied";
		case QImage::Format_RGB555:
			return "Format_RGB555";
		case QImage::Format_ARGB8555_Premultiplied:
			return "Format_ARGB8555_Premultiplied";
		case QImage::Format_RGB888:
			return "Format_RGB888";
		case QImage::Format_RGB444:
			return "Format_RGB444";
		case QImage::Format_ARGB4444_Premultiplied:
			return "Format_ARGB4444_Premultiplied";
		case QImage::Format_RGBX8888:
			return "Format_RGBX8888";
		case QImage::Format_RGBA8888:
			return "Format_RGBA8888";
		case QImage::Format_RGBA8888_Premultiplied:
			return "Format_RGBA8888_Premultiplied";
		case QImage::Format_BGR30:
			return "Format_BGR30";
		case QImage::Format_A2BGR30_Premultiplied:
			return "Format_A2BGR30_Premultiplied";
		case QImage::Format_RGB30:
			return "Format_RGB30";
		case QImage::Format_A2RGB30_Premultiplied:
			return "Format_A2RGB30_Premultiplied";
		case QImage::NImageFormats:
			return "NImageFormats";
		default:
			return "";
	}
}

core::DataRepresentation &core::DataRepresentation::operator=(const DataRepresentation &dr)
{
	setType(dr.getType());
	setImageFormat(dr.getImageFormat());
	setWidth(dr.getWidth());
	setHeight(dr.getHeight());

	return *this;
}

bool core::DataRepresentation::operator==(const DataRepresentation &dr)
{
	if(getType() == dr.getType() &&
	   getImageFormat() == dr.getImageFormat() &&
	   getWidth() == dr.getWidth() &&
	   getHeight() == dr.getHeight()){
		return true;
	}
	return false;
}

bool core::DataRepresentation::operator!=(const DataRepresentation &dr)
{
	if(getType() == dr.getType() &&
	   getImageFormat() == dr.getImageFormat() &&
	   getWidth() == dr.getWidth() &&
	   getHeight() == dr.getHeight()){
		return false;
	}
	return true;
}

void core::DataRepresentation::init(const Type &type, const QImage::Format &imgFormat, int w, int h)
{
	setType(type);
	setImageFormat(imgFormat);
	setWidth(w);
	setHeight(h);
}






