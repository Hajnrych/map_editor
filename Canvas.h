#ifndef CANVAS_H
#define CANVAS_H
#include <QGraphicsView>

class Scene;
class Grid;
class TerrainFactory;

class Canvas: public QGraphicsView
{
  Q_OBJECT
public:
  explicit Canvas(TerrainFactory* tf, Grid* grid, QWidget *parent = nullptr);
protected:
  void keyPressEvent(QKeyEvent *event);
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
private:
  Scene* scene;
  Grid* grid;
  void zoomIn();
  void zoomOut();
  qreal currentScale;
  static const qreal ZOOM_STEP, MIN_ZOOM, MAX_ZOOM;
};

#endif // CANVAS_H
