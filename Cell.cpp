#include "Cell.h"
#include <QPen>
#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

Cell::Cell(const QRectF &rect){
  setRect(rect);
  setPen(Qt::NoPen);
  setBrush(Qt::gray);
}
