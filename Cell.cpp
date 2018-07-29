#include "Cell.h"
#include <QPen>
#include <QBrush>

Cell::Cell(const QRectF &rect){
  setRect(rect);
  setPen(Qt::NoPen);
  setBrush(Qt::NoBrush);
}
