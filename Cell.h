#ifndef CELL_H
#define CELL_H
#include <QGraphicsPixmapItem>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QMap>
#include <QColor>

class Cell: public QGraphicsPixmapItem
{
public:
  Cell(const QRectF &rect);
  void setColor(const QColor& color);
  QColor getPrimaryColor() const;
  void diffuseEdges(QColor east, QColor north, QColor west, QColor south);
private:
  QColor primaryColor;
  void diffuseEast(QImage& img, QColor inputColor);
};

#endif // CELL_H
