#include "SideMenu.h"
#include <QGridLayout>
#include <QPushButton>
#include <QIcon>

SideMenu::SideMenu(QWidget *parent): QWidget(parent){
  layout = new QGridLayout();
  setLayout(layout);
  createButtons();
}

void SideMenu::createButtons(){
//  unsigned nx = 2;
//  unsigned ny = 10;
//  for (unsigned ix=0; ix<nx; ix++){
//    for (unsigned iy=0; iy<ny; iy++){
//      QString text = QString("btn %1 %2").arg(ix).arg(iy);
//      QPushButton* btn = new QPushButton(text, this);
//      layout->addWidget(btn, iy, ix);
//    }
//  }
  QPushButton* btn = new QPushButton(QIcon(":/textures/res/grass.png"), "", this);
  layout->addWidget(btn, 0, 0);
  btn = new QPushButton(QIcon(":/textures/res/water.png"), "", this);
  layout->addWidget(btn, 0, 1);
}
