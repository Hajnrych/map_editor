#ifndef CANVAS_H
#define CANVAS_H
#include <QGraphicsView>

class QGraphicsScene;

class Canvas: public QGraphicsView
{
  Q_OBJECT
public:
  explicit Canvas(QWidget *parent = nullptr);
private:
  QGraphicsScene* scene;
};

#endif // CANVAS_H
