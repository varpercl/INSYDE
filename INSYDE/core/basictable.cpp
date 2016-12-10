#include "basictable.h"

const QString BasicTable::STR_TABLE = "table";
const QString BasicTable::STR_ITEM = "item";
const QString BasicTable::STR_ROW = "row";
const QString BasicTable::STR_COL= "col";
const QString BasicTable::STR_DATA = "data";

BasicTable::BasicTable(QWidget *parent) :
	QTableView(parent)
{
	init();
}

BasicTable::~BasicTable()
{
//	delete cellContextMenu;
//	delete horizontalHeaderContextMenu;
//	delete verticalHeaderContextMenu;
}

void BasicTable::contextMenuEvent(QContextMenuEvent *event)
{
	cellContextMenu->exec(viewport()->mapToGlobal(event->pos()));
}

void BasicTable::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
	QTableView::selectionChanged(selected, deselected);

	emit selectedItemsChanged(selected, deselected);
}

void BasicTable::onHorizontalHeaderContextMenu(const QPoint pt)
{
//	qDebug() << "on right click: " << pt;
	horizontalHeaderContextMenu->exec(horizontalHeader()->viewport()->mapToGlobal(pt));
}

void BasicTable::onVerticalHeaderContextMenu(const QPoint pt)
{
	verticalHeaderContextMenu->exec(verticalHeader()->viewport()->mapToGlobal(pt));
}

void BasicTable::copyClick()
{
	if(!getCopyAction()->isEnabled() || !getCopyAction()->isVisible()) return;

	QModelIndexList selList = selectionModel()->selectedIndexes();

	if(selList.empty()){
		return;
	}else{
		clipboard = QApplication::clipboard();

		QString output;
		QXmlStreamWriter writer(&output);
		writer.setAutoFormatting(true);
		writer.setAutoFormattingIndent(3);

		writer.writeStartElement(STR_TABLE);
		for(int i = 0; i < selList.size(); i++){
			writer.writeEmptyElement(STR_ITEM);
			writer.writeAttribute(STR_ROW, QString::number(selList[i].row() - selList[0].row()));
			writer.writeAttribute(STR_COL, QString::number(selList[i].column() - selList[0].column()));
			writer.writeAttribute(STR_DATA, selList[i].data().toString());
		}
		writer.writeEndElement();

		clipboard->setText(output);
	}
}

void BasicTable::cutClick()
{
	if(!getCutAction()->isEnabled() || !getCutAction()->isVisible()) return;

	QModelIndexList selList = selectionModel()->selectedIndexes();

	if(selList.empty()){
		return;
	}else{
		clipboard = QApplication::clipboard();

		QString output;
		QXmlStreamWriter writer(&output);
		writer.setAutoFormatting(true);
		writer.setAutoFormattingIndent(3);

		writer.writeStartElement(STR_TABLE);
		for(int i = 0; i < selList.size(); i++){
			writer.writeEmptyElement(STR_ITEM);
			writer.writeAttribute(STR_ROW, QString::number(selList[i].row()));
			writer.writeAttribute(STR_COL, QString::number(selList[i].column()));
			writer.writeAttribute(STR_DATA, selList[i].data().toString());

			model()->setData(selList[i], "");
		}
		writer.writeEndElement();

		clipboard->setText(output);
	}
}

void BasicTable::pasteClick()
{
	if(!getPasteAction()->isEnabled() || !getPasteAction()->isVisible()) return;

	QModelIndexList selList = selectionModel()->selectedIndexes();

	if(selList.empty()){
		return;
	}else{
		clipboard = QApplication::clipboard();

		QString line = clipboard->text();
		QXmlStreamReader reader;
		reader.addData(line);

		QXmlStreamReader::TokenType tt;

		QStringRef name;
		QXmlStreamAttributes attributes;
		bool getInItem = false;

		QVector<QPair<QPoint, double> > replaceList;

		if(line != ""){
			while(!reader.atEnd()){
				tt = reader.readNext();

				if(tt == QXmlStreamReader::StartElement){

					name = reader.name();
					if(name == STR_TABLE){
						getInItem = true;
						continue;
					}else if(name == STR_ITEM && getInItem){

						attributes = reader.attributes();
						if(attributes.hasAttribute(STR_COL) &&
						   attributes.hasAttribute(STR_ROW) &&
						   attributes.hasAttribute(STR_DATA))
						{
							replaceList.push_back(qMakePair(QPoint(attributes.value(STR_ROW).toInt(), attributes.value(STR_COL).toInt()), attributes.value(STR_DATA).toDouble()));
						}
					}else{
						break;
					}
				}
			}
			if(replaceList.count() > 1){
				QMessageBox msg;
				msg.setIcon(QMessageBox::Warning);
				msg.setWindowTitle("Pegar");
				msg.setText(QString::fromLatin1("Existe mas de un elemento en el portapapeles."));
				msg.setInformativeText(QString::fromLatin1("¿Desea reemplazar los elementos correspondientes?"));
				msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

				if(msg.exec() == QMessageBox::Yes){

					for(int i = 0; i < replaceList.count(); i++){
						model()->setData(model()->index(replaceList[i].first.x() + selList[0].row(), replaceList[i].first.y() + selList[0].column()), replaceList[i].second);
					}
				}
			}else if(replaceList.count() == 1){
				model()->setData(model()->index(replaceList[0].first.x() + selList[0].row(), replaceList[0].first.y() + selList[0].column()), replaceList[0].second);
			}
		}
	}

}

void BasicTable::onInsertRightColumnTriggered()
{
	//There's not known (by me) way to insert one right column at the end of the table using only methods from QAbstractItemModel
	//User should reimplement this slot in order get the expected behavior
	//Consider to use insert column at X postition and move it (using QAbstractItemModel::moveColumn) at the end.
	model()->insertColumns(horizontalHeader()->logicalIndexAt(horizontalHeader()->viewport()->mapFromGlobal(horizontalHeaderContextMenu->pos())) + 1, 1);
}

void BasicTable::onInsertLeftColumnTriggered()
{
	model()->insertColumns(horizontalHeader()->logicalIndexAt(horizontalHeader()->viewport()->mapFromGlobal(horizontalHeaderContextMenu->pos())), 1);
}

void BasicTable::onRemoveColumnTriggered()
{
	model()->removeColumns(horizontalHeader()->logicalIndexAt(horizontalHeader()->viewport()->mapFromGlobal(horizontalHeaderContextMenu->pos())), 1);
}

void BasicTable::onInsertUpRowTriggered()
{
	model()->insertRows(verticalHeader()->logicalIndexAt(verticalHeader()->viewport()->mapFromGlobal(verticalHeaderContextMenu->pos())), 1);
}

void BasicTable::onInsertDownRowTriggered()
{
	model()->insertRows(verticalHeader()->logicalIndexAt(verticalHeader()->viewport()->mapFromGlobal(verticalHeaderContextMenu->pos())) + 1, 1);
}

void BasicTable::onRemoveRowTriggered()
{
	model()->removeRows(verticalHeader()->logicalIndexAt(verticalHeader()->viewport()->mapFromGlobal(verticalHeaderContextMenu->pos())), 1);
}

void BasicTable::init()
{
	cellContextMenu = new QMenu();
	horizontalHeaderContextMenu = new QMenu();
	verticalHeaderContextMenu = new QMenu();

	horizontalHeaderContextMenu->addAction(ICON_INSERT_COLUMN, "Insertar derecha", this, SLOT(onInsertRightColumnTriggered()));
	horizontalHeaderContextMenu->addAction(ICON_INSERT_COLUMN, "Insertar izquierda", this, SLOT(onInsertLeftColumnTriggered()));
	horizontalHeaderContextMenu->addSeparator();
	horizontalHeaderContextMenu->addAction(ICON_DELETE, "Eliminar", this, SLOT(onRemoveColumnTriggered()));

	verticalHeaderContextMenu->addAction(ICON_INSERT_ROW, "Insertar arriba", this, SLOT(onInsertUpRowTriggered()));
	verticalHeaderContextMenu->addAction(ICON_INSERT_ROW, "Insertar abajo", this, SLOT(onInsertDownRowTriggered()));
	horizontalHeaderContextMenu->addSeparator();
	verticalHeaderContextMenu->addAction(ICON_DELETE, QString::fromLatin1("Eliminar patrón"), this, SLOT(onRemoveRowTriggered()));

	horizontalHeader()->setContextMenuPolicy(Qt::CustomContextMenu);
	verticalHeader()->setContextMenuPolicy(Qt::CustomContextMenu);

	setCopyAction(cellContextMenu->addAction(ICON_COPY, "Copiar", this, SLOT(copyClick())));
	setCutAction(cellContextMenu->addAction(ICON_CUT, "Cortar", this, SLOT(cutClick())));
	setPasteAction(cellContextMenu->addAction(ICON_PASTE, "Pegar", this, SLOT(pasteClick())));

	connect(horizontalHeader(), SIGNAL(customContextMenuRequested(QPoint)), SLOT(onHorizontalHeaderContextMenu(QPoint)));
	connect(verticalHeader(), SIGNAL(customContextMenuRequested(QPoint)), SLOT(onVerticalHeaderContextMenu(QPoint)));
}

