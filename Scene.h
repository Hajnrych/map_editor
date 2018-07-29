#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>

class Scene: public QGraphicsScene
{
  Q_OBJECT
public:
  explicit Scene(QObject *parent = nullptr);
protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
  void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
private:
  Qt::MouseButton button;
};

#endif // SCENE_H
