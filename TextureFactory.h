#ifndef TEXTUREFACTORY_H
#define TEXTUREFACTORY_H
#include <QMap>
#include <QColor>
#include <QBrush>

class TextureFactory
{
public:
  static TextureFactory* getInstance();
  QBrush getTexture(int key) const;
  QList<int> getAllTextureIds() const;
private:
  TextureFactory();
  QMap<int, QBrush> textureMap;
};

#endif // TEXTUREFACTORY_H
