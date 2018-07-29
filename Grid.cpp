#include "Grid.h"
#include <QGraphicsScene>
#include <Cell.h>

Grid::Grid(QSize size, qreal pitch, QObject *parent):
  QObject(parent), size(size), pitch(pitch){

}

void Grid::construct(QGraphicsScene* scene){
  constructLines(scene);
  constructCells(scene);
}

void Grid::constructOneLine(QGraphicsScene* scene, QLineF line){
  QPen pen(Qt::black, 1, Qt::DashLine);
  QGraphicsLineItem* item = scene->addLine(line, pen);
  lines.push_back(item);
  item->setZValue(1);
}

void Grid::constructLines(QGraphicsScene* scene){
  for (unsigned ix=0; ix<size.width(); ix++){
    constructOneLine(scene, QLineF(ix*pitch, 0, ix*pitch, size.height()*pitch));
  }
  for (unsigned iy=0; iy<size.height(); iy++){
    constructOneLine(scene, QLineF(0, iy*pitch, size.width()*pitch, iy*pitch));
  }
}

void Grid::constructCells(QGraphicsScene* scene){
  for (unsigned ix=0; ix<size.width(); ix++){
    for (unsigned iy=0; iy<size.height(); iy++){
      constructOneCell(scene, QPointF(ix*pitch, iy*pitch));
    }
  }
}

void Grid::constructOneCell(QGraphicsScene* scene, QPointF topLeft){
  QRectF cellRect(topLeft, topLeft + QPointF(pitch, pitch));
  Cell* cell = new Cell(cellRect);
  cell->setZValue(0);
  scene->addItem(cell);
}

QSize Grid::getSize() const {
  return size;
}

qreal Grid::getPitch() const {
  return pitch;
}

QRectF Grid::getRect() const {
  return QRectF(0, 0, size.width()*pitch, size.height() * pitch);
}

void Grid::setLineVisibility(bool visible){
  foreach (QGraphicsLineItem* item, lines) {
    item->setVisible(visible);
  }
}
