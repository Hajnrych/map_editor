#include "Canvas.h"
#include <qgraphicsscene.h>
#include <QKeyEvent>
#include <QMouseEvent>
#include <Cell.h>
#include <Scene.h>
#include <Grid.h>

const qreal Canvas::ZOOM_STEP = 1.25;
const qreal Canvas::MIN_ZOOM = 0.125/2;
const qreal Canvas::MAX_ZOOM = 2;

Canvas::Canvas(Grid* grid, QWidget *parent): QGraphicsView(parent),
  scene(0), grid(grid), currentScale(1.0){
  scene = new Scene(this);
  scene->setBrushRadius(grid->getPitch()/2);
  scene->setSceneRect(grid->getRect());
  scene->setBackgroundBrush(Qt::white);
  setScene(scene);
  grid->construct(scene);
}

void Canvas::keyPressEvent(QKeyEvent *event){
  if (event->key() == Qt::Key_Plus)
    zoomIn();
  else if (event->key() == Qt::Key_Minus)
    zoomOut();
}

void Canvas::zoomIn(){
  if (currentScale > MAX_ZOOM)
    return;
  scale(ZOOM_STEP, ZOOM_STEP);
  currentScale*= ZOOM_STEP;
}

void Canvas::zoomOut(){
  if (currentScale < MIN_ZOOM)
    return;
  scale(1/ZOOM_STEP, 1/ZOOM_STEP);
  currentScale/= ZOOM_STEP;
}

void Canvas::mouseMoveEvent(QMouseEvent *event){
  QGraphicsView::mouseMoveEvent(event);
}

void Canvas::mousePressEvent(QMouseEvent *event){
  QGraphicsView::mousePressEvent(event);
}

void Canvas::setBrushColor(int colorId){
  scene->setBrush(colorId);
}

void Canvas::setBrushRadius(int radius){
  scene->setBrushRadius(radius);
}

