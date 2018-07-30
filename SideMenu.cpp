#include "SideMenu.h"
#include <QGridLayout>
#include <QPushButton>
#include <TextureButton.h>
#include <QSignalMapper>
#include <QMap>
#include <QPixmap>
#include <TerrainFactory.h>
#include <TerrainType.h>

SideMenu::SideMenu(QWidget *parent): QWidget(parent){
  layout = new QGridLayout();
  setLayout(layout);
  signalMapper = new QSignalMapper(this);
}

void SideMenu::createButtons(TerrainFactory* terrainFactory){
  int nx = 2;
  for (int i=0; i<terrainFactory->size(); i++){
     QBrush brush = terrainFactory->getTerrain(i)->getDefaultBrush();
     QPushButton* btn = new TextureButton(brush, this);
     connect(btn, SIGNAL(clicked()), signalMapper, SLOT(map()));
     signalMapper->setMapping(btn, i);
     layout->addWidget(btn, i / nx, i % nx);
  }
  connect(signalMapper, SIGNAL(mapped(int)),
          this, SIGNAL(brushChanged(int)));
}
