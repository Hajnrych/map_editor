#include "TextureFactory.h"

TextureFactory::TextureFactory(){
  colors[0] = Qt::transparent;
  colors[1] = Qt::darkBlue;
  colors[2] = Qt::darkGreen;
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

QList<int> TextureFactory::getAllColorIds() const {
  return colors.keys();
}
