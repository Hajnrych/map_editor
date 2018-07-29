#include "TextureFactory.h"
#include <ColorUtil.h>
#include <AssetLoader.h>

TextureFactory::TextureFactory(){
  textureMap[0] = QBrush(AssetLoader::getInstance()->getTexture("grass"));
  textureMap[1] = QBrush(AssetLoader::getInstance()->getTexture("forest"));
  textureMap[2] = QBrush(AssetLoader::getInstance()->getTexture("water"));
  //textureMap[3] = QBrush(AssetLoader::getInstance()->getTexture("swamp"));
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
