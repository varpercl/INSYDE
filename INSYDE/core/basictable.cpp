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

}

void BasicTable::contextMenuEvent(QContextMenuEvent *event)
{
	contextMenu.exec(viewport()->mapToGlobal(event->pos()));
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

		writer.writeStartElement("table");
		for(int i = 0; i < selList.size(); i++){
			writer.writeEmptyElement("item");
			writer.writeAttribute("row", QString::number(selList[i].row() - selList[0].row()));
			writer.writeAttribute("col", QString::number(selList[i].column() - selList[0].column()));
			writer.writeAttribute("data", selList[i].data().toString());
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
//						qDebug() << "(" + QString::number(replaceList[i].first.x() + selList[0].row()) + ", " + QString::number(replaceList[i].first.y() + selList[0].column()) + ")";
						model()->setData(model()->index(replaceList[i].first.x() + selList[0].row(), replaceList[i].first.y() + selList[0].column()), replaceList[i].second);
					}
				}
			}
		}

	}

}

void BasicTable::init()
{
	setCopyAction(contextMenu.addAction(ICON_COPY, "Copiar", this, SLOT(copyClick())));
	setCutAction(contextMenu.addAction(ICON_CUT, "Cortar", this, SLOT(cutClick())));
	setPasteAction(contextMenu.addAction(ICON_PASTE, "Pegar", this, SLOT(pasteClick())));
}

