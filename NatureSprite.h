#ifndef NATURESPRITE_H
#define NATURESPRITE_H
#include <QGraphicsPixmapItem>

class NatureSprite: public QGraphicsPixmapItem
{
public:
  NatureSprite(const QPixmap& pixmap, QGraphicsItem* parent=nullptr);
};

#endif // NATURESPRITE_H
