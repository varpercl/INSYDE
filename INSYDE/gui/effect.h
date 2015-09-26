#ifndef EFFECT_H
#define EFFECT_H

#include <QImage>

/*!
 * \brief The Effect class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT Effect
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
