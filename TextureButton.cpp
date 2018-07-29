#include "TextureButton.h"
#include <QIcon>

TextureButton::TextureButton(const QColor& color,
                             QWidget *parent): QPushButton(parent){
  QPixmap pixmap(QSize(64, 64));
  pixmap.fill(color);
  setIcon(QIcon(pixmap));
}
