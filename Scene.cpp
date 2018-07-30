#include "Scene.h"
#include <QGraphicsSceneMouseEvent>
#include <Cell.h>
#include <QCursor>
#include <TerrainFactory.h>
#include <TerrainType.h>

Scene::Scene(TerrainFactory* terrainFactory,
             QObject *parent): QGraphicsScene(parent),
             terrainFactory(terrainFactory){
  button = Qt::NoButton;
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent){
  button = mouseEvent->button();
  if (button & Qt::LeftButton){
     drawTerrain(mouseEvent->scenePos());
  }
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent){
  Q_UNUSED(mouseEvent)
  button = Qt::NoButton;
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent){
  if (button & Qt::LeftButton){
     drawTerrain(mouseEvent->scenePos());
  }
}

void Scene::drawTerrain(QPointF mPos){
  qreal r = terrainFactory->getBrushRadius();
  QRectF rect(mPos.x() - r/2,  mPos.y() - r/2, r, r);
  QList<QGraphicsItem*> selectedItems = items(rect);
  foreach (QGraphicsItem* item, selectedItems) {
    Cell* cell = qgraphicsitem_cast<Cell*>(item);
    if (!cell)
      continue;
    cell->setBrush(terrainFactory->getActiveTerrain()->getRandomBrush());
}
}
