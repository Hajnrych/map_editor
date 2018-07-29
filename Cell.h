#ifndef CELL_H
#define CELL_H
#include <QGraphicsRectItem>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QPainter>

class Cell: public QGraphicsRectItem
{
public:
  Cell(const QRectF &rect);
  void setColor(const QColor& color);
  //void setPixmap(const QPixmap& pixmap);
//protected:
//  void paint(QPainter *painter,
//             const QStyleOptionGraphicsItem *option,
//             QWidget *widget = nullptr);
//private:
//  QPixmap* pixmap;
};

#endif // CELL_H
