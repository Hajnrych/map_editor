#include "TextureFactory.h"

TextureFactory::TextureFactory(){
  colors[0] = Qt::darkGreen;
  colors[1] = Qt::darkBlue;
  colorStrength.append(colors[0]);
  colorStrength.append(colors[1]);
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

QColor TextureFactory::getStronger(QColor left, QColor right) const{
  int leftId = colorStrength.indexOf(left);
  int rightId = colorStrength.indexOf(right);
  if (leftId < rightId)
    return right;
  return left;
}

QList<int> TextureFactory::getAllColorIds() const {
  return colors.keys();
}
