#include "Canvas.h"
#include <qgraphicsscene.h>

Canvas::Canvas(QWidget *parent): QGraphicsView(parent){
  scene = new QGraphicsScene(this);
  scene->setSceneRect(0, 0, 10, 10);
  scene->setBackgroundBrush(Qt::darkGreen);
  setScene(scene);
}

