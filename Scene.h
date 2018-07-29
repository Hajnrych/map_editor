#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QPixmap>

class Scene: public QGraphicsScene
{
  Q_OBJECT
public:
  explicit Scene(QObject *parent = nullptr);
  void setBrush(int colorId);
  void setBrushRadius(qreal radius);
protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
  void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
private:
  Qt::MouseButton button;
  qreal brushRadius;
  QBrush brush;
};

#endif // SCENE_H
