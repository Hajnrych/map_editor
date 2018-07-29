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
  QList<int> colorIds = TextureFactory::getInstance()->getAllColorIds();
  int i = 0;
  int nx = 3;
  foreach (int colorId, colorIds) {
     QColor color = TextureFactory::getInstance()->getColor(colorId);
     QPushButton* btn = new TextureButton(color, this);
     connect(btn, SIGNAL(clicked()), signalMapper, SLOT(map()));
     signalMapper->setMapping(btn, colorId);
     layout->addWidget(btn, i / nx, i % nx);
     i++;
  }
  connect(signalMapper, SIGNAL(mapped(int)),
          this, SIGNAL(brushChanged(int)));
}
