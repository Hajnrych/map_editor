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
  QPixmap getTree(int index) const;
private:
  AssetLoader();
  void loadTexture(const QString& name);
  void loadTree(int index);
  QMap<QString, QPixmap> textures;
  QMap<int, QPixmap> trees;
};

#endif // ASSETLOADER_H
