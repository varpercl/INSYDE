#ifndef FILEEDITLINE_H
#define FILEEDITLINE_H

#include <QtWidgets>

#include "definitions.h"
#include "share_core_lib.h"

namespace core{

/*!
 * \brief The FileEditLine class is a control which is used to opens a file and update
 * the edit line with the name of the file.
 *
 * TODO: implement the correct regular expressions to detect the right sintax of a file.
 * TODO: enable different styles and look and feels.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/03/2017
 *
 */
class CORE_LIB_IMPORT_EXPORT FileEditLine : public QWidget
{
	public:

		/*!
		 * \brief An empty file edit line.
		 * \param[in] parent The parent of this control.
		 */
		explicit FileEditLine(QWidget *parent = 0);

		/*!
		 * \brief A file edit line with a default path established.
		 * \param path The path to be set.
		 * \param[in] parent The parent of this widget.
		 */
		explicit FileEditLine(const QString &path, QWidget *parent = 0);

		/*!
		 * \brief Gets the file path.
		 * \return A string which contains the current file path.
		 */
		QString getFilePath() const;

		/*!
		 * \brief Sets the filters of the "Open file" dialog.
		 * \param formats The different formats.
		 *
		 * \see QFileDialog for more information about formats.
		 */
		void setFilters(const QString &formats);

		/*!
		 * \brief Gets the current formats allowed by the "Open file" dialog.
		 * \return A string which contains the current filters.
		 */
		QString getFilters() const;

		/*!
		 * \brief Set the default filter when open the "Open file" dialog.
		 * \param sel The selected filter.
		 */
		void setSelectedFilter(const QString &sel);

		/*!
		 * \brief Set the text of the label next to the edit line.
		 * \param text The text assigned to this label.
		 */
		void setLabelText(const QString &text);

		/*!
		 * \brief Returns text of the label next to the edit line.
		 * \return The text of the label.
		 */
		QString getLabelText() const;

		/*!
		 * \brief Gets the selected filter.
		 * \return A string with the selected filter.
		 */
		QString getSelectedFilter() const;

		/*!
		 * \brief Gets the pointer to the current QLineEdit object.
		 * Useful to customize the appeareance of the control.
		 *
		 * \return A QLineEdit pointer.
		 */
		QLineEdit *getLineEdit() const;

		/*!
		 * \brief Sets a different label than the current one.
		 *
		 * \note User is responsible for managin hangling pointers.
		 *
		 * \param label The new label to be set.
		 */
		void setLabel(QLabel *label);

		/*!
		 * \brief Gets the current label pointer.
		 * \return A pointer to the current label.
		 */
		QLabel *getLabel() const;

	public slots:

		/*!
		 * \brief Sets the file path of this control.
		 * \param path The new path to be set.
		 */
		void setFilePath(const QString &path);

	private slots:

		/*!
		 * \brief Thron when click on the ellipsis.
		 * This will open the "Open file" dialog.
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
		 * \brief Initializes all graphic interface.
		 *
		 * \param path The default path.
		 */
		void init(const QString &path);
};
}
#endif // FILEEDITLINE_H
