#include "TerrainType.h"

TerrainType::TerrainType(const QPixmap& brushPixmap): brushPixmap(brushPixmap){}

void TerrainType::appendNautrePixMap(const QPixmap& pixmap){
  naturePixmaps.append(pixmap);
}

QBrush TerrainType::getBrush() const {
  return QBrush(brushPixmap);
}

QPixmap TerrainType::getRandomNaturePixMap() const {
  return naturePixmaps[qrand() % naturePixmaps.size()];
}

bool TerrainType::hasNaturePixMap() const {
  return naturePixmaps.size() > 0;
}
