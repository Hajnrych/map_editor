#ifndef ASSETLOADER_H
#define ASSETLOADER_H
#include <QPixmap>
#include <QMap>
#include <QString>

class AssetLoader
{
public:
  static AssetLoader* getInstance();
  QPixmap getTexture(const QString& name) const;
private:
  AssetLoader();
  void loadTexture(const QString& name);
  QMap<QString, QPixmap> textures;
};

#endif // ASSETLOADER_H
