#ifndef TERRAINTYPE_H
#define TERRAINTYPE_H
#include <QBrush>

class TerrainType
{
public:
  explicit TerrainType(const QPixmap& pixmap);
  TerrainType* append(const QPixmap& pixmap);
  QBrush getDefaultBrush() const;
  QBrush getRandomBrush() const;
private:
  QList<QPixmap> pixmaps;
};

#endif // TERRAINTYPE_H
