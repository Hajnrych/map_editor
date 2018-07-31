#include "Grid.h"
#include <QGraphicsScene>
#include <Cell.h>
#include <ColorUtil.h>
#include <cmath>

Grid::Grid(int size, qreal pitch, QObject *parent):
  QObject(parent), size(size), pitch(pitch){

}

void Grid::construct(QGraphicsScene* scene){
  qreal radius = pitch;
  qreal shift = radius * sqrt(3);
  for (int iy=-size/2; iy<size/2; iy++){
    for (int ix=-size/2; ix<size/2; ix++){
      if (iy % 2 == 0)
        constructCell(scene, QPointF(ix*shift, 1.5*iy*radius), radius);
      else
        constructCell(scene, QPointF((ix+0.5)*shift, 1.5*iy*radius), radius);
    }
  }
}

void Grid::constructCell(QGraphicsScene* scene, QPointF center, qreal radius){
  Cell* cell = new Cell(center, radius);
  cell->setZValue(0);
  scene->addItem(cell);
  cells.append(cell);
}

qreal Grid::getPitch() const {
  return pitch;
}

QRectF Grid::getRect() const {
  return QRectF(-size*pitch/2, -size*pitch/2, size*pitch, size*pitch);
}


void Grid::setLineVisibility(bool visible){
  foreach (QGraphicsLineItem* item, lines) {
    item->setVisible(visible);
  }
}

void Grid::setCellBrushForAllCells(QBrush brush){
  foreach (Cell* cell, cells) {
     cell->setBrush(brush);
  }
}
