#include "TextureButton.h"
#include <QIcon>

TextureButton::TextureButton(const QBrush& brush,
                             QWidget *parent): QPushButton(parent){
  if (brush.texture().isNull()){
    QPixmap pixmap(QSize(64, 64));
    pixmap.fill(brush.color());
    setIcon(QIcon(pixmap));
  }
  else {
    setIcon(QIcon(brush.texture()));
  }

}
