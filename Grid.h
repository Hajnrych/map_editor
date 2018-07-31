#ifndef GRID_H
#define GRID_H
#include <QObject>
#include <QList>
#include <QGraphicsLineItem>

class QGraphicsScene;
class Cell;

class Grid: public QObject
{
  Q_OBJECT
public:
  explicit Grid(int size, qreal pitch, QObject *parent = nullptr);
  void construct(QGraphicsScene* scene);
  qreal getPitch() const;
  QRectF getRect() const;
  void setCellBrushForAllCells(QBrush brush);
public slots:
  void setLineVisibility(bool visible);
private:
  int size;
  qreal pitch;
  QList<QGraphicsLineItem*> lines;
  QList<Cell*> cells;
  void constructCell(QGraphicsScene* scene, QPointF center, qreal radius);
};

#endif // GRID_H
