#ifndef CANVAS_H
#define CANVAS_H
#include <QGraphicsView>

class Scene;

class Canvas: public QGraphicsView
{
  Q_OBJECT
public:
  explicit Canvas(QWidget *parent = nullptr);
  void createGrid(unsigned nx, unsigned ny, qreal pitch);
public slots:
  void setBrush(int colorId);
protected:
  void keyPressEvent(QKeyEvent *event);
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
private:
  Scene* scene;
  void createScene(unsigned nx, unsigned ny, qreal pitch);
  void zoomIn();
  void zoomOut();
  qreal currentScale;
  static const qreal ZOOM_STEP, MIN_ZOOM, MAX_ZOOM;
};

#endif // CANVAS_H
