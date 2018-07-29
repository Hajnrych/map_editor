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
  enum Direction {east=0, north, west, south};
  Cell(const QRectF &rect);
  void setColor(const QColor& color);
  void addNeighbour(Cell* cell, Direction dir);
private:
  QMap<int, Cell*> nei;

};

#endif // CELL_H
