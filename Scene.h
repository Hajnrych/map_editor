#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QPixmap>

class Scene: public QGraphicsScene
{
  Q_OBJECT
public:
  explicit Scene(QObject *parent = nullptr);
  void setBrushColor(int colorId);
  void setBrushRadius(qreal radius);
signals:
  void cellChanged(QPointF);
protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
  void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
private:
  Qt::MouseButton button;
  qreal brushRadius;
  QColor brushColor;
};

#endif // SCENE_H
