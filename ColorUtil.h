#ifndef COLORUTIL_H
#define COLORUTIL_H
#include <QVector3D>
#include <QColor>

class ColorUtil
{
public:
  static QVector3D hsvToVector(const QColor& color);
  static QColor vectorToHsv(const QVector3D& vect);
  static QVector3D rgbToVector(const QColor& color);
  static QColor vectorToRgb(const QVector3D& vect);
  static QColor mixColors(const QColor& color1, const QColor& color2, double prop=0.5);
  static double getRgbDistance(const QColor& color1, const QColor& color2);
private:
  ColorUtil();
};

#endif // COLORUTIL_H
