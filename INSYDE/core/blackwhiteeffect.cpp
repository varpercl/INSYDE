#include "blackwhiteeffect.h"

core::BlackWhiteEffect::BlackWhiteEffect()
{

}

core::BlackWhiteEffect::BlackWhiteEffect(const QImage &img, ConvertionFormat cf, double threshold)
{
	init(img, cf, threshold);
}

core::BlackWhiteEffect::~BlackWhiteEffect()
{

}

void core::BlackWhiteEffect::setConvertionFormat(BlackWhiteEffect::ConvertionFormat fc)
{
	cf = fc;
}

void core::BlackWhiteEffect::setImage(const QImage &img)
{
	image = img;
}

QImage core::BlackWhiteEffect::getImage()
{
	switch(cf){
		case Threshold:{
			QImage newImage(image);
			int
					w = newImage.width(),
					h = newImage.height();
			QColor rgb;

//			double
			int
					gray;
			uint bn;

			for(int i = 0; i < w; i++){
				for(int j = 0; j < h; j++){
					rgb = QColor(newImage.pixel(i, j));

//					gray = rgb.redF()*0.3 + rgb.greenF()*0.59 + rgb.blueF()*0.11;
					gray = qGray(rgb.rgb());

					bn = (gray < (threshold * 255) ? 0xff000000 : 0xffffffff);
					newImage.setPixel(i, j, bn);
				}
			}
//			return newImage.convertToFormat(QImage::Format_Mono);

			//Prueba para devolver la imagen escalada a una altura no muy grande para
			//la red neuronal y un ancho total multiplo del ancho de la ventana.

			//El ancho de la ventana sera de 30 de alto por 20 de ancho (pixeles)
			//el intervalo de desplazamiento sera de 10 pixeles

			//Se iran realizando las pruebas hasta dar con el valor mas adecuado para
			//que la red neuronal no se vuelva lenta
//			int hni = ;
			double
					percentage = WINDOW_HEIGH / double(newImage.height()),
					width = floor(percentage * double(newImage.width())),
					tWidth = floor(width/WINDOW_STEP) * WINDOW_STEP;


			return newImage.scaled((int)tWidth, WINDOW_HEIGH)/*.convertToFormat(QImage::Format_Mono)*/;
		}
		case Mono:
			return image.convertToFormat(QImage::Format_Mono/*, Qt::MonoOnly*/);
		default:
			return image;
	}
}

void core::BlackWhiteEffect::setThreshold(double ts)
{
	if(ts > 1){
		threshold = 1;
	}else if(ts < 0){
		threshold = 0;
	}else{
		threshold = ts;
	}
}

double core::BlackWhiteEffect::getThreshold()
{
	return threshold;
}

int core::BlackWhiteEffect::getType()
{
	return BNEffectType;
}

void core::BlackWhiteEffect::init(const QImage &img, BlackWhiteEffect::ConvertionFormat fc, double threshold)
{
	setImage(img);
	setConvertionFormat(fc);
	setThreshold(threshold);
}
