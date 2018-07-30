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
  explicit Grid(QSize size, qreal pitch, QObject *parent = nullptr);
  void construct(QGraphicsScene* scene);
  QSize getSize() const;
  qreal getPitch() const;
  QRectF getRect() const;
  void setCellBrushForAllCells(QBrush brush);
public slots:
  void setLineVisibility(bool visible);
  void diffuse();
private:
  QSize size;
  qreal pitch;
  QList<QGraphicsLineItem*> lines;
  QList<Cell*> cells;
  void constructLines(QGraphicsScene* scene);
  void constructCells(QGraphicsScene* scene);
  void constructOneLine(QGraphicsScene* scene, QLineF line);
  void constructOneCell(QGraphicsScene* scene, QPointF topLeft);
  Cell* getCellByCoords(int ix, int iy) const;
  void diffuse(int ix, int iy);
};

#endif // GRID_H
