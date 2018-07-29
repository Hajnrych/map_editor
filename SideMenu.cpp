#include "SideMenu.h"
#include <QGridLayout>
#include <QPushButton>
#include <IconButton.h>
#include <QSignalMapper>

SideMenu::SideMenu(QWidget *parent): QWidget(parent){
  layout = new QGridLayout();
  setLayout(layout);
  signalMapper = new QSignalMapper(this);
  createButtons();
}

void SideMenu::createButton(QString name, int ix, int iy, int brush){
  QPushButton* btn = new IconButton(name, this);
  connect(btn, SIGNAL(clicked()), signalMapper, SLOT(map()));
  signalMapper->setMapping(btn, brush);
  layout->addWidget(btn, ix, iy);
}

void SideMenu::createButtons(){
  createButton("grass", 0, 0, 1);
  createButton("water", 0, 1, 2);
  connect(signalMapper, SIGNAL(mapped(int)),
          this, SIGNAL(brushChanged(int)));
}
