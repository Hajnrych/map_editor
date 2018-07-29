#ifndef CELL_H
#define CELL_H
#include <QGraphicsPixmapItem>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QMap>

class Cell: public QGraphicsPixmapItem
{
public:
  Cell(const QRectF &rect);
  void setColor(const QColor& color);
  void addNei(Cell* cell, int dir);
private:
  QMap<int, Cell*> nei;

};

#endif // CELL_H
