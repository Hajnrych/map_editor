#ifndef GRID_H
#define GRID_H
#include <QObject>
#include <QList>
#include <QGraphicsLineItem>

class QGraphicsScene;

class Grid: public QObject
{
  Q_OBJECT
public:
  explicit Grid(QSize size, qreal pitch, QObject *parent = nullptr);
  void construct(QGraphicsScene* scene);
  QSize getSize() const;
  qreal getPitch() const;
  QRectF getRect() const;
public slots:
  void setLineVisibility(bool visible);
private:
  QSize size;
  qreal pitch;
  QList<QGraphicsLineItem*> lines;
  void constructLines(QGraphicsScene* scene);
  void constructCells(QGraphicsScene* scene);
  void constructOneLine(QGraphicsScene* scene, QLineF line);
  void constructOneCell(QGraphicsScene* scene, QPointF topLeft);
};

#endif // GRID_H
