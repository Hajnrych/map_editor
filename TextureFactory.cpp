#include "TextureFactory.h"
#include <ColorUtil.h>

TextureFactory::TextureFactory(){
  textureMap[0] = QBrush(Qt::darkGreen, Qt::SolidPattern);
  textureMap[1] = QBrush(ColorUtil::mixColors(Qt::darkGreen, Qt::black),
                         Qt::SolidPattern);
  textureMap[2] = QBrush(Qt::darkBlue, Qt::SolidPattern);
  textureMap[3] = QBrush(Qt::darkCyan, Qt::SolidPattern);
  textureMap[4] = QBrush(ColorUtil::mixColors(Qt::green, Qt::gray),
                         Qt::SolidPattern);
  textureMap[5] = QBrush(ColorUtil::mixColors(Qt::green, Qt::darkGreen, 0.25),
                         Qt::SolidPattern);
  textureMap[6] = QBrush(ColorUtil::mixColors(Qt::green, Qt::darkGreen, 0.5),
                         Qt::SolidPattern);
  textureMap[7] = QBrush(Qt::darkGray, Qt::SolidPattern);
  textureMap[8] = QBrush(ColorUtil::mixColors(Qt::darkGreen, Qt::darkRed),
                         Qt::SolidPattern);
}

TextureFactory* TextureFactory::getInstance(){
  static TextureFactory* instance = new TextureFactory();
  return instance;
}

QBrush TextureFactory::getTexture(int key) const {
  if (textureMap.count(key) != 0)
    return textureMap[key];
  return textureMap[0];
}

QList<int> TextureFactory::getAllTextureIds() const {
  return textureMap.keys();
}
