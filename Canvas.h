#ifndef CANVAS_H
#define CANVAS_H
#include <QGraphicsView>

class QGraphicsScene;

class Canvas: public QGraphicsView
{
  Q_OBJECT
public:
  explicit Canvas(QWidget *parent = nullptr);
  void createGrid(unsigned nx, unsigned ny, qreal pitch);
protected:
  void keyPressEvent(QKeyEvent *event);
private:
  QGraphicsScene* scene;
  void createScene(unsigned nx, unsigned ny, qreal pitch);
  void zoomIn();
  void zoomOut();
  qreal currentScale;
  static const qreal ZOOM_STEP, MIN_ZOOM, MAX_ZOOM;
};

#endif // CANVAS_H
