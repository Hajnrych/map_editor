#include "AssetLoader.h"

AssetLoader::AssetLoader(){
  loadTexture("grass");
  loadTexture("forest");
  loadTexture("water");
  loadTexture("swamp");
}

void AssetLoader::loadTexture(const QString& name){
  textures[name] = QPixmap(QString(":/textures/%1.png").arg(name));
}

AssetLoader* AssetLoader::getInstance(){
  static AssetLoader* instance = new AssetLoader();
  return instance;
}

QPixmap AssetLoader::getTexture(const QString& name) const {
  return textures[name];
}
