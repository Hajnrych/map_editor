#include "Cell.h"
#include <QPen>
#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <TextureFactory.h>
#include <ColorUtil.h>

Cell::Cell(const QRectF &rect){
  QPixmap pixmap(rect.size().toSize());
  primaryColor = Qt::darkGreen;
  pixmap.fill(primaryColor);
  setPixmap(pixmap);
  setPos(rect.topLeft());
}

void Cell::setColor(const QColor& color){
  primaryColor = color;
  QPixmap p = pixmap();
  p.fill(color);
  setPixmap(p);
}

QColor Cell::getPrimaryColor() const {
  return primaryColor;
}

void Cell::diffuseEdges(QColor east, QColor north, QColor west, QColor south){
  QImage img = pixmap().toImage();
  //diffuseEast(img, east);
}

void Cell::diffuseEast(QImage& img, QColor inputColor){
  if (TextureFactory::getInstance()->isStronger(primaryColor, inputColor))
    return;
  //setColor(ColorUtil::mixColors(primaryColor, inputColor));
  //return;
  QRect rect = img.rect();
  int x0 = rect.topLeft().x();
  int y0 = rect.topLeft().y();
  for (int iy=y0; iy<rect.height(); iy++){
    for (int ix=x0; iy<rect.width()/2; ix++){
      //QColor c = img.pixelColor(ix, iy);
      img.setPixelColor(QPoint(ix, iy), ColorUtil::mixColors(primaryColor, inputColor));
    }
  }
}
