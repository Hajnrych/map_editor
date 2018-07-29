#include "Canvas.h"
#include <qgraphicsscene.h>
#include <QKeyEvent>
#include <QMouseEvent>

const qreal Canvas::ZOOM_STEP = 1.25;
const qreal Canvas::MIN_ZOOM = 0.125;
const qreal Canvas::MAX_ZOOM = 2;

Canvas::Canvas(QWidget *parent): QGraphicsView(parent),
  scene(0), currentScale(1.0){}

void Canvas::createScene(unsigned nx, unsigned ny, qreal pitch){
  scene = new QGraphicsScene(this);
  scene->setSceneRect(0, 0, nx*pitch, ny*pitch);
  scene->setBackgroundBrush(Qt::white);
  setScene(scene);
}

void Canvas::createGrid(unsigned nx, unsigned ny, qreal pitch){
  createScene(nx, ny, pitch);
  QPen pen(Qt::black, 1, Qt::DashLine);
  for (unsigned ix=0; ix<nx; ix++){
    QLineF line(ix*pitch, 0, ix*pitch, ny*pitch);
    scene->addLine(line, pen);
  }
  for (unsigned iy=0; iy<ny; iy++){
    QLineF line(0, iy*pitch, nx*pitch, iy*pitch);
    scene->addLine(line, pen);
  }
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

void Canvas::setBrush(int brushId){
  int y=0;
}

