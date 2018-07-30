#include "TerrainType.h"

TerrainType::TerrainType(const QPixmap& pixmap){
  pixmaps.append(pixmap);
}

TerrainType* TerrainType::append(const QPixmap& pixmap){
  pixmaps.append(pixmap);
  return this;
}

QBrush TerrainType::getDefaultBrush() const {
  return QBrush(pixmaps[0]);
}

QBrush TerrainType::getRandomBrush() const {
  return QBrush(pixmaps[qrand() % pixmaps.size()]);
}
