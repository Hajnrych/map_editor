#include "Scene.h"
#include <QGraphicsSceneMouseEvent>
#include <Cell.h>
#include <TextureFactory.h>
#include <QCursor>

Scene::Scene(QObject *parent): QGraphicsScene(parent){
  button = Qt::NoButton;
  brushColor = TextureFactory::getInstance()->getColor(0);
}

void Scene::setBrush(int colorId){
  brushColor = TextureFactory::getInstance()->getColor(colorId);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent){
  button = mouseEvent->button();
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent){
  Q_UNUSED(mouseEvent)
  button = Qt::NoButton;
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent){
  if (button & Qt::LeftButton){
      QGraphicsItem *item = itemAt(mouseEvent->scenePos(), QTransform());
      Cell* cell = qgraphicsitem_cast<Cell*>(item);
      if (!cell)
        return;
      cell->setColor(brushColor);
      emit cellChanged(cell->pos());
  }
}
