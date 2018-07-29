#include "Cell.h"
#include <QPen>
#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

Cell::Cell(const QRectF &rect){
  QPixmap pixmap(rect.size().toSize());
  primaryColor = Qt::darkGreen;
  pixmap.fill(primaryColor);
  setPixmap(pixmap);
  setPos(rect.topLeft());
}

void Cell::setColor(const QColor& color){
  primaryColor = color;
  QPixmap p = pixmap();
  p.fill(color);
  setPixmap(p);
}

QColor Cell::getPrimaryColor() const {
  return primaryColor;
}

void Cell::diffuseEdges(QColor east, QColor north, QColor west, QColor south){

}
