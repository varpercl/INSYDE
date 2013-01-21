#include "visor.h"

Visor::Visor(QWidget *parent) : QGraphicsView(parent), apuntador(NULL){
	//    simulationStatus = true;
	map = new Enviroment();
	setScene(map);
	setSimulationStatus(Stopped);
	//    setFrameStyle(0);


	setOptimizationFlags(QGraphicsView::DontAdjustForAntialiasing|
						 QGraphicsView::DontSavePainterState
						 );
	setRenderHint(QPainter::HighQualityAntialiasing);
	setAttribute(Qt::WA_TranslucentBackground, false);
	setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
	//    updateViewPort = startTimer(50);
}

void Visor::setSimulationStatus(Status sta)
{
	QList<QGraphicsItem*> itms = items();
	Unit *un;
	switch(sta){
		case Running:
			foreach(QGraphicsItem *itm, itms){
				if((un = dynamic_cast<Unit*>(itm)))
					un->setFlag(QGraphicsItem::ItemIsMovable, false);
				un->run();
			}
			break;
		case Paused:
			foreach(QGraphicsItem *itm, itms){
				if((un=dynamic_cast<Unit*>(itm)))
					un->setFlag(QGraphicsItem::ItemIsMovable, false);
				un->stop();
			}
			break;
		case Stopped:
			foreach(QGraphicsItem *itm, itms){
				if((un = dynamic_cast<Unit*>(itm))){
					un->setFlag(QGraphicsItem::ItemIsMovable);
					un->clearPoints();
				}
			}
	}
	simulationStatus = sta;
}

Status Visor::getSimulationStatus()
{
	return simulationStatus;
}

void Visor::mouseDoubleClickEvent(QMouseEvent *event)
{
	switch(simulationStatus){
		case Paused:
		case Running:
			if(event->button() == Qt::RightButton){
				event->ignore();
				return;
			}
			break;
		case Stopped:
			break;
	}
	QGraphicsView::mouseDoubleClickEvent(event);
}

void Visor::mousePressEvent(QMouseEvent *event){

	QList<QGraphicsItem*> itemsSeleccionados = scene()->selectedItems();
#if _MSC_VER == 1600
	QGraphicsItem *item = scene()->itemAt(mapToScene(event->pos()), transform());
#else
	QGraphicsItem *item = scene()->itemAt(mapToScene(event->pos()));
#endif

	if(event->button() == Qt::LeftButton){
		//en caso de querer un recuadro de seleccion personalizado
		//        selectionRect = QRect(event->pos(),QSize(0,0));
		if(event->modifiers() & Qt::ShiftModifier){
			if(item){
				//            itemsSeleccionados.append(item);
				item->setSelected(true);
			}
			//            return;
		}
		QGraphicsView::mousePressEvent(event);
	}if(event->button() == Qt::RightButton){
		switch(simulationStatus){
			case Running:
				posInicialMouse = mapToScene(event->pos()); //Captura la posicion inicial del mouse para mostrar luego la flecha de direccion
				break;
			case Paused:
				break;
			case Stopped:
				if(itemsSeleccionados.count() < 1 && item != NULL){
					item->setSelected(true);
				}
				contextualMenu(event->pos());
				break;
		}

		if(simulationStatus == Running){
			posInicialMouse = mapToScene(event->pos());
		}else{

		}
	}

	emit clicked(event);
}

void Visor::mouseMoveEvent(QMouseEvent *event){
	QGraphicsView::mouseMoveEvent(event);
	QList<QGraphicsItem*> itemsSeleccionados = scene()->selectedItems();
	int nItems = itemsSeleccionados.count();

	if(event->buttons() & Qt::LeftButton){

		//en caso de querer un cuadro de seleccion personalizado
		//        selectionRect.setBottomRight(event->pos());
		//        if(event->modifiers() & Qt::ShiftModifier){
		//            QPainterPath selPath;
		//            selPath.addRect(selectionRect);
		//            scene()->setSelectionArea(selPath);
		//            setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
		//        }
		//        viewport()->update(selectionRect);
	}else if(event->buttons() & Qt::RightButton){
		QPointF posActual = mapToScene(event->pos());
		Vector2D vector(posActual.x(), posActual.y(), posInicialMouse.x(), posInicialMouse.y());
		if(vector.getModulo() > 20){ //Si la distancia de arrastre supera el valor
			if(nItems > 1){
				showPointer(180 + (vector.getAngle()*180/M_PI));
			}
		}else{
			removePointer();
		}
	}
}

void Visor::mouseReleaseEvent(QMouseEvent *event){
	QGraphicsView::mouseReleaseEvent(event);

	removePointer();

#if _MSC_VER == 1600
	QGraphicsItem *item = scene()->itemAt(mapToScene(event->pos()), transform());
#else
	QGraphicsItem *item = scene()->itemAt(mapToScene(event->pos()));
#endif
	//    if(event->button() & Qt::LeftButton){

	//    }
	switch(simulationStatus){
		case Running:
			if(event->button() == Qt::LeftButton){

			}else if(event->button() == Qt::RightButton){
				const int cols = 5;

				QList<QGraphicsItem*> itemsSeleccionados = scene()->selectedItems();
				Unit *un;
				int numItems = itemsSeleccionados.count();

				if(false){
					for(int itm = 0; itm < numItems; itm++){
						if((un = dynamic_cast<Unit*>(itemsSeleccionados[itm]))){
							if(un->getUnitColor() != Blue){
								itemsSeleccionados[itm]->setSelected(false);
							}
						}
					}

					itemsSeleccionados = scene()->selectedItems();
					numItems = itemsSeleccionados.count();
				}

				if(numItems > 0 && item != NULL){
					Unit *tmpUnit;
					if((tmpUnit = dynamic_cast<Unit*>(item))){
						ShootingUnit *su = 0;
						foreach(QGraphicsItem *gi, itemsSeleccionados){
							if((su = dynamic_cast<ShootingUnit*>(gi))){
								su->attackTo(tmpUnit);
							}
						}
						return;
					}
				}

				Unit *unit;
				QPointF posCur = mapToScene(event->pos());
				int contItems = numItems;
				if(contItems > 1){
					double factorSeparacion = 1.5;
					double anchoFormacion = 0;
					int lim = contItems;
					if(contItems > cols){
						lim = cols;
					}

					for(int i = 0; i < lim; i++){
						unit = dynamic_cast<Unit*>(itemsSeleccionados[i]);
						anchoFormacion += 2 * unit->getRadius() * factorSeparacion;
					}

					Vector2D dirCursor(posInicialMouse, posCur);
					Vector2D perpCursor = dirCursor.getPerpendicular(CounterClockWise);
					perpCursor.setModulo(anchoFormacion/2);
					Vector2D incPos = perpCursor * -1;
					QPointF lastPoint = posInicialMouse - perpCursor.toPointF();

					int contHor = 0;
					//        int contVer = 0;
					foreach(QGraphicsItem *item, itemsSeleccionados){
						unit = dynamic_cast<Unit*>(item);
						if(!(event->modifiers() & Qt::ShiftModifier)){
							unit->clearPoints();
						}

						unit->addPoint(lastPoint);
						incPos.setModulo((2 * unit->getRadius()) * factorSeparacion);
						lastPoint += incPos.toPointF();

						contHor++;
						if(contHor > cols){
							perpCursor.setModulo(anchoFormacion);
							lastPoint = lastPoint - perpCursor.toPointF()-incPos.toPointF()+incPos.getPerpendicular(ClockWise).toPointF();
							contHor = 0;
						}
					}
				}else if(contItems == 1){
					unit = dynamic_cast<Unit*>(itemsSeleccionados.at(0));
					if(!(event->modifiers() & Qt::ShiftModifier)){
						unit->clearPoints();
					}
					unit->addPoint(posCur);
				}
			}
			break;
		case Paused:
			break;
		case Stopped:
			break;
	}
}

int rectArea(QRect rect){
	return rect.width() * rect.height();
}

void Visor::contextualMenu(QPoint p){
	QMenu *cntxMenu;

	QList<QGraphicsItem*> listItems = items(p);
	if(areDifferentTypes(listItems)){
		cntxMenu = new QMenu();
		cntxMenu->addAction("Borrar", this, SLOT(deleteSelected()));
		cntxMenu->exec(mapToGlobal(p));
	}else if(!listItems.empty()){
		cntxMenu = dynamic_cast<GraphicElement*>(itemAt(p))->getContextMenu(new QMenu());
		cntxMenu->exec(mapToGlobal(p));
	}
}

void Visor::deleteSelected(){
	QList<QGraphicsItem*> itemsSeleccionados = scene()->selectedItems();
	foreach(QGraphicsItem *item, itemsSeleccionados){
		scene()->removeItem(item);
		delete item;
	}
}

void Visor::removePointer(){
	if(apuntador != 0){
		//        delete apuntador;
		//        apuntador = 0;
		scene()->removeItem(apuntador);
		delete apuntador;
		apuntador = NULL;
	}
}

void Visor::showPointer(double angle){
	if(apuntador == NULL){
		apuntador = new GraphicPointer();
		apuntador->setVisible(false);
		map->addItem(apuntador);
	}
	apuntador->setPos(posInicialMouse);
	apuntador->setRotation(angle);
	apuntador->setVisible(true);
}

bool Visor::areDifferentTypes(const QList<QGraphicsItem *> &list)
{
	int sList = list.size();
	for(int i = 1; i < sList; i++){
		if(list[0]->type() != list[i]->type()){
			return true;
		}
	}
	return false;
}
