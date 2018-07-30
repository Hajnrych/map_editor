#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QPixmap>

class TerrainFactory;

class Scene: public QGraphicsScene
{
  Q_OBJECT
public:
  explicit Scene(TerrainFactory* terrainFactory, QObject *parent = nullptr);
protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
  void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
private:
  Qt::MouseButton button;
  TerrainFactory* terrainFactory;
  void drawTerrain(QPointF mPos);
};

#endif // SCENE_H
