#ifndef CELL_H
#define CELL_H
#include <QGraphicsRectItem>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QMap>
#include <QColor>

class Cell: public QGraphicsRectItem
{
public:
  Cell(const QRectF &rect);
};

#endif // CELL_H
