#ifndef TERRAINTYPE_H
#define TERRAINTYPE_H
#include <QBrush>

class TerrainType
{
public:
  explicit TerrainType(const QPixmap& brushPixmap);
  void appendNautrePixMap(const QPixmap& pixmap);
  QBrush getBrush() const;
  QPixmap getRandomNaturePixMap() const;
  bool hasNaturePixMap() const;
private:
  QPixmap brushPixmap;
  QList<QPixmap> naturePixmaps;
};

#endif // TERRAINTYPE_H
