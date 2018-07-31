#include "Cell.h"
#include <QPen>
#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QtMath>

Cell::Cell(const QPointF &pos, qreal radius){
  setPen(QPen(Qt::black, 1));
  setBrush(Qt::gray);
  QPolygonF polygon;
  for (int i=0; i<6; i++){
    qreal angle = qDegreesToRadians((i+0.5) * 60.0);
    QPointF relPos(radius*qCos(angle), radius*qSin(angle));
    polygon.append(pos + relPos);
  }
  //setPos(pos + polygon.boundingRect().center());
  setPolygon(polygon);
}
