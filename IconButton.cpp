#include "IconButton.h"
#include <QIcon>

IconButton::IconButton(QString name, QWidget *parent): QPushButton(parent){
  setIcon(QIcon(QString(":/textures/res/%1.png").arg(name)));
}
