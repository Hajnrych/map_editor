#include "TerrainFactory.h"
#include <TerrainType.h>
#include <AssetLoader.h>

TerrainFactory::TerrainFactory(qreal pitch, QObject *parent): QObject(parent),
  brushRadius(1), currentIndex(0){
  types.append(new TerrainType(AssetLoader::getInstance()->getTexture("grass")));
  types.append(new TerrainType(AssetLoader::getInstance()->getTexture("forest")));
  types.append(new TerrainType(AssetLoader::getInstance()->getTexture("rocky")));
  types.append(new TerrainType(AssetLoader::getInstance()->getTexture("dirt")));
  types.append(new TerrainType(AssetLoader::getInstance()->getTexture("swamp")));
  types.append(new TerrainType(AssetLoader::getInstance()->getTexture("desert")));
  //QSize size(pitch, pitch);
  //types[1]->append(AssetLoader::getInstance()->getTree(1).scaled(size));
  //types[1]->append(AssetLoader::getInstance()->getTree(2).scaled(size));
  //types[1]->append(AssetLoader::getInstance()->getTree(3).scaled(size));
  types.append(new TerrainType(AssetLoader::getInstance()->getTexture("water")));
}

TerrainType* TerrainFactory::getTerrain(int index) const {
  return types[index];
}

TerrainType* TerrainFactory::getActiveTerrain() const {
  return getTerrain(currentIndex);
}

TerrainType* TerrainFactory::getDefaultTerrain() const {
  return getTerrain(0);
}

void TerrainFactory::setType(int typeId){
  currentIndex = typeId;
}

int TerrainFactory::size() const {
  return types.size();
}

qreal TerrainFactory::getBrushRadius() const {
  return brushRadius;
}

void TerrainFactory::setBrushRadius(int radius){
  brushRadius = radius;
}
