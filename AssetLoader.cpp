#include "AssetLoader.h"

AssetLoader::AssetLoader(){
  loadTexture("grass");
  loadTexture("forest");
  loadTexture("water");
  loadTexture("swamp");
  loadTexture("desert");
  loadTexture("dirt");
  loadTexture("rocky");
  loadTexture("road");
  loadTree(1);
  loadTree(2);
  loadTree(3);
}

void AssetLoader::loadTexture(const QString& name){
  textures[name] = QPixmap(QString(":/textures/%1.png").arg(name));
}

void AssetLoader::loadTree(int index){
  trees[index] = QPixmap(QString(":/textures/tree%1.png").arg(index));
}

AssetLoader* AssetLoader::getInstance(){
  static AssetLoader* instance = new AssetLoader();
  return instance;
}

QPixmap AssetLoader::getTexture(const QString& name) const {
  return textures[name];
}

QPixmap AssetLoader::getTree(int index) const {
  return trees[index];
}
