#ifndef FILEEDITLINE_H
#define FILEEDITLINE_H

#include <QtWidgets>

#include "definitions.h"
#include "share_core_lib.h"


class CORE_LIB_IMPORT_EXPORT FileEditLine : public QWidget
{
	public:

		/*!
		 * \brief FileEditLine
		 * \param parent
		 */
		explicit FileEditLine(QWidget *parent = 0);

		/*!
		 * \brief FileEditLine
		 * \param path
		 * \param paren
		 */
		explicit FileEditLine(const QString &path, QWidget *parent = 0);

		/*!
		 * \brief getFilePath
		 * \return
		 */
		QString getFilePath() const;

		/*!
		 * \brief setFilter
		 * \param formats
		 */
		void setFilter(const QString &formats);

		/*!
		 * \brief getFilter
		 * \return
		 */
		QString getFilter() const;

		/*!
		 * \brief setSelectedFilter
		 * \param sel
		 */
		void setSelectedFilter(const QString &sel);

		/*!
		 * \brief setLabelText
		 * \param text
		 */
		void setLabelText(const QString &text);

		QString getLabelText() const;

		/*!
		 * \brief getSelectedFilter
		 * \return
		 */
		QString getSelectedFilter() const;

		/*!
		 * \brief getLineEdit
		 * \return
		 */
		QLineEdit *getLineEdit() const;

		/*!
		 * \brief setLabel
		 * \param label
		 */
		void setLabel(QLabel *label);

		/*!
		 * \brief getLabel
		 * \return
		 */
		QLabel *getLabel() const;

	public slots:

		/*!
		 * \brief setFilePath
		 * \param path
		 */
		void setFilePath(const QString &path);

	private slots:

		/*!
		 * \brief onOpenFileDialogClicked
		 */
		void onOpenFileDialogClicked();

	private:

		Q_OBJECT

		QString
		path,
		formats,
		selectedFilter;

		QToolButton *btnOpenFileDIalog;

		QLineEdit *leFilePath;

		QLabel *label;

		QHBoxLayout *mainLayout;

		/*!
		 * \brief init
		 */
		void init(const QString &path);
};

#endif // FILEEDITLINE_H
