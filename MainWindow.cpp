#include "MainWindow.h"
#include <Canvas.h>
#include <QWidget>
#include <QHBoxLayout>
#include <SideMenu.h>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent){
  QHBoxLayout* centralWidgetlayout = new QHBoxLayout();
  QWidget* centralWidget = new QWidget(this);
  sideMenu =new SideMenu(centralWidget);
  centralWidgetlayout->addWidget(sideMenu);
  canvas = new Canvas(centralWidget);
  centralWidgetlayout->addWidget(canvas);
  setCentralWidget(centralWidget);
  centralWidget->setLayout(centralWidgetlayout);
  canvas->createGrid(100, 100, 64);
  connect(sideMenu, SIGNAL(brushChanged(int)),
          canvas, SLOT(setBrush(int)));
  resize(QDesktopWidget().availableGeometry(this).size() * 0.5);
}

MainWindow::~MainWindow(){

}
