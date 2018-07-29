#include "Scene.h"
#include <QGraphicsSceneMouseEvent>
#include <Cell.h>
#include <TextureFactory.h>
#include <QCursor>

Scene::Scene(QObject *parent): QGraphicsScene(parent){
  button = Qt::NoButton;
  brush = TextureFactory::getInstance()->getTexture(0);
  brushRadius = 0;
}

void Scene::setBrush(int colorId){
  brush = TextureFactory::getInstance()->getTexture(colorId);
}

void Scene::setBrushRadius(qreal radius){
  this->brushRadius = radius;
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
      QPointF mPos = mouseEvent->scenePos();
      QRectF rect(mPos.x() - brushRadius/2,  mPos.y() - brushRadius/2,
                  brushRadius, brushRadius);
      QList<QGraphicsItem*> selectedItems = items(rect);
      foreach (QGraphicsItem* item, selectedItems) {
        Cell* cell = qgraphicsitem_cast<Cell*>(item);
        if (!cell)
          continue;
        cell->setBrush(brush);
    }
  }
}
