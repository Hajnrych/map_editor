#ifndef CELL_H
#define CELL_H
#include <QGraphicsRectItem>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QMap>
#include <QColor>

class Cell: public QGraphicsPolygonItem
{
public:
  Cell(const QPointF &pos, qreal radius);
};

#endif // CELL_H
