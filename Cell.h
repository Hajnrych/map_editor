#ifndef CELL_H
#define CELL_H
#include <QGraphicsRectItem>

class Cell: public QGraphicsRectItem
{
public:
  Cell(const QRectF &rect);
};

#endif // CELL_H
