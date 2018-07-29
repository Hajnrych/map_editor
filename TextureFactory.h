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
  bool isStronger(QColor left, QColor right) const;
private:
  TextureFactory();
  QMap<int, QColor> colors;
  QList<QColor> colorStrength;
};

#endif // TEXTUREFACTORY_H
