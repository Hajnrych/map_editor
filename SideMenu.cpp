#include "SideMenu.h"
#include <QGridLayout>
#include <QPushButton>
#include <TextureButton.h>
#include <QSignalMapper>
#include <TextureFactory.h>
#include <QMap>
#include <QPixmap>

SideMenu::SideMenu(QWidget *parent): QWidget(parent){
  layout = new QGridLayout();
  setLayout(layout);
  signalMapper = new QSignalMapper(this);
  createButtons();
}

void SideMenu::createButtons(){
  QList<int> colorIds = TextureFactory::getInstance()->getAllTextureIds();
  int i = 0;
  int nx = 2;
  foreach (int colorId, colorIds) {
     QBrush brush = TextureFactory::getInstance()->getTexture(colorId);
     QPushButton* btn = new TextureButton(brush.color(), this);
     connect(btn, SIGNAL(clicked()), signalMapper, SLOT(map()));
     signalMapper->setMapping(btn, colorId);
     layout->addWidget(btn, i / nx, i % nx);
     i++;
  }
  connect(signalMapper, SIGNAL(mapped(int)),
          this, SIGNAL(brushChanged(int)));
}
