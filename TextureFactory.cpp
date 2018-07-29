#include "TextureFactory.h"
#include <ColorUtil.h>

TextureFactory::TextureFactory(){
  colors[0] = Qt::darkGreen;
  colors[1] = ColorUtil::mixColors(Qt::darkGreen, Qt::darkRed);
  colors[2] = Qt::darkCyan;
  colors[3] = Qt::darkBlue;

  colorStrength.append(colors[0]);
  colorStrength.append(colors[1]);
  colorStrength.append(colors[2]);
  colorStrength.append(colors[3]);
}

TextureFactory* TextureFactory::getInstance(){
  static TextureFactory* instance = new TextureFactory();
  return instance;
}

QColor TextureFactory::getColor(int key) const {
  if (colors.count(key) != 0)
    return colors[key];
  return Qt::transparent;
}

bool TextureFactory::isStronger(QColor left, QColor right) const{
  int leftId = colorStrength.indexOf(left);
  int rightId = colorStrength.indexOf(right);
  return (leftId > rightId);
}

QList<int> TextureFactory::getAllColorIds() const {
  return colors.keys();
}
