#include "plotterdata.h"


PlotterData::PlotterData() :
	QStandardItemModel()
{
	init();
}

PlotterData::~PlotterData()
{

}

void PlotterData::addPoint(int serie, double value)
{
	QModelIndex ind, lastRow;
	int rc = rowCount();

//	beginInsertRows(ind, rc, rc);
//	beginInsertRows( QModelIndex(), m_rows[serie].count(), m_rows[serie].count());

//	QVector<QVariant> dat;
//	dat.resize(nSeries + 1);
//	dat[0] = m_rows.size() - 1;
//	dat[serie + 1] = value;
//	m_rows.append(dat);
	insertRow(rc);

	rc = rowCount();
	ind = index(rc - 1, 0);
	if(rc > 1){
		lastRow = index(rc - 2, 0);
		setData(ind, data(lastRow).toDouble() + interval);
	}else{
		setData(ind, 0);
	}
	ind = index(rc - 1, serie + 1);
	setData(ind, value);
//	m_rows[0][serie] = value;
//	m_rows[1][serie] = value;
//	m_rows[serie].append(value);
//	endInsertRows();
}

void PlotterData::addPoint(const QVector<double> &valSeries)
{

}

void PlotterData::addSerie(const QVector<double> &data)
{
//	QModelIndex ind;
//	int cc = columnCount();

//	beginInsertColumns(ind, cc, cc);
	appendColumn(QList<QStandardItem*>());
	nSeries++;

//	endInsertColumns();
}

bool PlotterData::loadFromCSV( const QString& filename )
{
	//TODO: corregir

//	QFile file( filename );
//	if ( !file.exists() || !file.open ( QIODevice::ReadOnly ) ) {
//		qDebug() << "TableModel::loadFromCSV: file" << filename
//				 << "does not exist or could not be opened";
//		return false;
//	}

//	QStringList lines;
//	while ( !file.atEnd() ) {
//		lines.append( QString::fromUtf8( file.readLine() ) );
//	}

//	setTitleText( QString() );
//	m_rows.clear();
//	m_rows.resize( qMax( 0, lines.size() - ( m_dataHasHorizontalHeaders ? 1 : 0 ) ) );

//	for ( int row = 0; row < lines.size(); ++row ) {
//		QStringList cells = splitLine( lines.at( row ) );

//		QVector<QVariant> values( qMax( 0, cells.size() - ( m_dataHasVerticalHeaders ? 1 : 0 ) ) );

//		for ( int column = 0; column < cells.size(); ++column ) {
//			QString cell = cells.at( column );

//			if ( row == 0 && m_dataHasHorizontalHeaders ) {
//				// interpret the first row as column headers:
//				// the first one is an exception: interpret that as title
//				if ( column == 0 && m_dataHasVerticalHeaders ) {
//					setTitleText( cell );
//				} else {
//					m_horizontalHeaderData.append( cell );
//				}
//			} else {
//				if ( column == 0 && m_dataHasVerticalHeaders ) {
//					// interpret first column as row headers:
//					m_verticalHeaderData.append( cell );
//				} else {
//					// try to interpret cell values as floating point
//					bool convertedOk = false;
//					qreal numeric = cell.toDouble( &convertedOk );
//					const int destColumn = column - ( m_dataHasVerticalHeaders ? 1 : 0 );
//					values[ destColumn ] = convertedOk ? numeric : ( cell.isEmpty() ? QVariant() : cell );
//				}
//			}
//		}
//		const int destRow = row - ( m_dataHasHorizontalHeaders ? 1 : 0 );
//		if ( destRow >= 0 ) {
//			m_rows[ destRow ] = values;
//		}
//	}

//	beginResetModel();
//	endResetModel();

//	if ( m_rows.isEmpty() ) {
//		qDebug() << "TableModel::loadFromCSV: table loaded, but no "
//					"model data found.";
//	}
//		return true;
}

void PlotterData::setInterval(double interval)
{
	this->interval = interval;
}

double PlotterData::getInterval() const
{
	return interval;
}

void PlotterData::init(int nSeries)
{
	this-> nSeries = nSeries;

	setInterval(1);
	setColumnCount(nSeries + 1);
	setRowCount(0);
//	m_rows.resize(2);
}
