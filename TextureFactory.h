#ifndef TEXTUREFACTORY_H
#define TEXTUREFACTORY_H
#include <QMap>
#include <QColor>

class TextureFactory
{
public:
  static TextureFactory* getInstance();
  QColor getColor(int key) const;
  QList<int> getAllColorIds() const;
private:
  TextureFactory();
  QMap<int, QColor> colors;
};

#endif // TEXTUREFACTORY_H
