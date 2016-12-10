#include "fileeditline.h"

FileEditLine::FileEditLine(QWidget *parent) :
	QWidget(parent)
{
	init("");
}

FileEditLine::FileEditLine(const QString &path, QWidget *parent) :
	QWidget(parent)
{
	init(path);
}

void FileEditLine::setFilePath(const QString &path)
{
	QFileInfo fi(path);
	if(fi.exists()){
		leFilePath->setText(this->path = path);
	}else{
		leFilePath->setText(this->path = "");
	}
}

QString FileEditLine::getFilePath() const
{

	return path;
}

void FileEditLine::setFilter(const QString &formats)
{
	this->formats = formats;
}

QString FileEditLine::getFilter() const
{
	return formats;
}

void FileEditLine::setSelectedFilter(const QString &sel)
{
	selectedFilter = sel;
}

void FileEditLine::setLabelText(const QString &text)
{
	label->setText(text);
}

QString FileEditLine::getLabelText() const
{
	return label->text();
}

QString FileEditLine::getSelectedFilter() const
{
	return selectedFilter;
}

QLineEdit *FileEditLine::getLineEdit() const
{
	return leFilePath;
}

void FileEditLine::setLabel(QLabel *label)
{
	this->label = label;
}

QLabel *FileEditLine::getLabel() const
{
	return label;
}

void FileEditLine::onOpenFileDialogClicked()
{
	QString path = QFileDialog::getOpenFileName(this, "Abrir archivo", DIR_SAMPLES, formats, &selectedFilter);
	if(!path.isEmpty()){
		setFilePath(path);
	}
}

void FileEditLine::init(const QString &path)
{
	//Initialize QLabel
	label = new QLabel(tr("Path"));

	//Initialize QLineEdit
	leFilePath = new QLineEdit(path);

	//Initialize QToolButton
	btnOpenFileDIalog = new QToolButton();

	//Initialize QHBoxLayout
	mainLayout = new QHBoxLayout();

	this->path = path;

	btnOpenFileDIalog->setText("...");

	mainLayout->addWidget(label);
	mainLayout->addWidget(leFilePath);
	mainLayout->addWidget(btnOpenFileDIalog);

	setLayout(mainLayout);

	connect(btnOpenFileDIalog, SIGNAL(clicked()), SLOT(onOpenFileDialogClicked()));
	connect(leFilePath, SIGNAL(textEdited(QString)), SLOT(setFilePath(QString)));
}
