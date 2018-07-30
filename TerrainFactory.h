#ifndef TERRAINFACTORY_H
#define TERRAINFACTORY_H
#include <QObject>
#include <QList>

class TerrainType;

class TerrainFactory : public QObject
{
  Q_OBJECT
public:
  explicit TerrainFactory(qreal pitch, QObject *parent = nullptr);
  TerrainType* getTerrain(int index) const;
  int size() const;
  TerrainType* getActiveTerrain() const;
  TerrainType* getDefaultTerrain() const;
  qreal getBrushRadius() const;
public slots:
  void setType(int typeId);
  void setBrushRadius(int radius);
private:
  QList<TerrainType*> types;
  int currentIndex;
  qreal brushRadius;
};

#endif // TERRAINFACTORY_H
