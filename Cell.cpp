#include "Cell.h"
#include <QPen>
#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <TextureFactory.h>

Cell::Cell(const QRectF &rect){
  setRect(rect);
  setPen(Qt::NoPen);
  setBrush(TextureFactory::getInstance()->getTexture(0));
}
