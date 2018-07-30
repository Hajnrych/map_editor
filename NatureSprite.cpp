#include "NatureSprite.h"

NatureSprite::NatureSprite(const QPixmap& pixmap, QGraphicsItem* parent):
  QGraphicsPixmapItem(pixmap, parent){
  //setPixmap(pixmap);
  setVisible(true);
}
