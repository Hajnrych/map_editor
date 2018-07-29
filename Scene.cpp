#include "Scene.h"
#include <QGraphicsSceneMouseEvent>
#include <Cell.h>

Scene::Scene(QObject *parent): QGraphicsScene(parent){
  button = Qt::NoButton;
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent){
  button = mouseEvent->button();
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent){
  button = Qt::NoButton;
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent){
  if (button & Qt::LeftButton){
      QGraphicsItem *item = itemAt(mouseEvent->scenePos(), QTransform());
      Cell* cell = qgraphicsitem_cast<Cell*>(item);
      if (!cell)
        return;
      cell->setBrush(Qt::yellow);
  }
}
