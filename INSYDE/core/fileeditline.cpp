#include "fileeditline.h"

core::FileEditLine::FileEditLine(QWidget *parent) :
	QWidget(parent)
{
//    Q_INIT_RESOURCE(core_media);
	init("");
}

core::FileEditLine::FileEditLine(const QString &path, QWidget *parent) :
	QWidget(parent)
{
//    Q_INIT_RESOURCE(core_media);
	init(path);
}

void core::FileEditLine::setFilePath(const QString &path)
{
	QFileInfo fi(path);
	if(fi.exists()){
		leFilePath->setText(this->path = path);
	}else{
		leFilePath->setText(this->path = "");
	}
}

QString core::FileEditLine::getFilePath() const
{

	return path;
}

void core::FileEditLine::setFilters(const QString &formats)
{
	this->formats = formats;
}

QString core::FileEditLine::getFilters() const
{
	return formats;
}

void core::FileEditLine::setSelectedFilter(const QString &sel)
{
	selectedFilter = sel;
}

void core::FileEditLine::setLabelText(const QString &text)
{
	label->setText(text);
}

QString core::FileEditLine::getLabelText() const
{
	return label->text();
}

QString core::FileEditLine::getSelectedFilter() const
{
	return selectedFilter;
}

QLineEdit *core::FileEditLine::getLineEdit() const
{
	return leFilePath;
}

void core::FileEditLine::setLabel(QLabel *label)
{
	this->label = label;
}

QLabel *core::FileEditLine::getLabel() const
{
	return label;
}

void core::FileEditLine::onOpenFileDialogClicked()
{
	QString path = QFileDialog::getOpenFileName(this, "Abrir archivo", DIR_SAMPLES, formats, &selectedFilter);
	if(!path.isEmpty()){
		setFilePath(path);
	}
}

void core::FileEditLine::init(const QString &path)
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
