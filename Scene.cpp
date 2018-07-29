#include "Scene.h"
#include <QGraphicsSceneMouseEvent>
#include <Cell.h>
#include <TextureFactory.h>
#include <QCursor>

Scene::Scene(QObject *parent): QGraphicsScene(parent){
  button = Qt::NoButton;
  brushColor = TextureFactory::getInstance()->getColor(0);
  brushRadius = 0;
}

void Scene::setBrushColor(int colorId){
  brushColor = TextureFactory::getInstance()->getColor(colorId);
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
        cell->setColor(brushColor);
      }
      //QGraphicsItem *item = itemAt(mouseEvent->scenePos(), QTransform());
      //emit cellChanged(cell->pos());
  }
}
