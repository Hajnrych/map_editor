#include "Cell.h"
#include <QPen>
#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

Cell::Cell(const QRectF &rect){
  setRect(rect);
  setPen(Qt::NoPen);
  setBrush(Qt::NoBrush);
}

void Cell::setColor(const QColor& color){
  setBrush(color);
}

//void Cell::setPixmap(const QPixmap& pixmap){
//  if (this->pixmap)
//    delete this->pixmap;
//  this->pixmap = new QPixmap(pixmap);
//}

//void Cell::paint(QPainter *painter,
//           const QStyleOptionGraphicsItem *option,
//                 QWidget *widget){

//  Q_UNUSED(widget);
//  if (!pixmap){
//    painter->setPen(Qt::NoPen);
//    painter->setBrush(Qt::NoBrush);
//    painter->drawRect(rect());
//    return;
//  }
//  painter->setPen(Qt::NoPen);
//  painter->setBrush(Qt::red);
//  painter->drawRect(rect());
//    //painter->drawPixmap(0, 0, *pixmap);
//}
