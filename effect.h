#ifndef EFFECT_H
#define EFFECT_H

#include <QImage>

class Effect
{
	public:
		enum {Nothing = 0};

		explicit Effect();
		explicit Effect(const QImage &img);

		virtual void setImage(const QImage &img);
		virtual QImage getImage();

		virtual int getType() = 0;
	protected:
		QImage image;

	private:

};

#endif // EFFECT_H
