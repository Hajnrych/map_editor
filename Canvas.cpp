#include "Canvas.h"
#include <qgraphicsscene.h>
#include <QKeyEvent>
#include <QMouseEvent>
#include <Cell.h>
#include <Scene.h>
#include <Grid.h>

const qreal Canvas::ZOOM_STEP = 1.25;
const qreal Canvas::MIN_ZOOM = 0.125;
const qreal Canvas::MAX_ZOOM = 2;

Canvas::Canvas(Grid* grid, QWidget *parent): QGraphicsView(parent),
  grid(grid), scene(0), currentScale(1.0){
  scene = new Scene(this);
  scene->setSceneRect(grid->getRect());
  scene->setBackgroundBrush(Qt::white);
  setScene(scene);
  grid->construct(scene);
}


//void Canvas::createGrid(unsigned nx, unsigned ny, qreal pitch){
//  createScene(nx, ny, pitch);

//  for (unsigned ix=0; ix<nx; ix++){
//    for (unsigned iy=0; iy<ny; iy++){
//      qreal x = ix*pitch;
//      qreal y = iy*pitch;
//      Cell* cell = new Cell(QRectF(QPointF(x, y),
//                                QPointF(x+pitch, y+pitch)));
//      cell->setZValue(0);
//      scene->addItem(cell);
//    }
//  }
//}

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

void Canvas::setBrush(int colorId){
  scene->setBrush(colorId);
}

