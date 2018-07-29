#include "ColorUtil.h"

ColorUtil::ColorUtil(){}

QVector3D ColorUtil::hsvToVector(const QColor& color){
  return QVector3D(color.hueF(), color.saturationF(), color.valueF());
}

QColor ColorUtil::vectorToHsv(const QVector3D& vect){
  return QColor::fromHsvF(vect.x(), vect.y(), vect.z());
}

QVector3D ColorUtil::rgbToVector(const QColor& color){
  return QVector3D(color.redF(), color.greenF(), color.blueF());
}

QColor ColorUtil::vectorToRgb(const QVector3D& vect){
  return QColor::fromRgbF(vect.x(), vect.y(), vect.z());
}

QColor ColorUtil::mixColors(const QColor& color1, const QColor& color2, double prop) {
  QVector3D a = ColorUtil::rgbToVector(color1);
  QVector3D b = ColorUtil::rgbToVector(color2);
  return ColorUtil::vectorToRgb(a * prop + b * (1 - prop));
}

double ColorUtil::getRgbDistance(const QColor& color1, const QColor& color2){
  QVector3D a = ColorUtil::rgbToVector(color1);
  QVector3D b = ColorUtil::rgbToVector(color2);
  return (a - b).length();
}
