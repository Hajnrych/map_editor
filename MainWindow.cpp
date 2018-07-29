#include "MainWindow.h"
#include <Canvas.h>
#include <QWidget>
#include <QHBoxLayout>
#include <SideMenu.h>
#include <QDesktopWidget>
#include <Grid.h>
#include <QMenuBar>
#include <QAction>
#include <MenuController.h>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent){
  QHBoxLayout* centralWidgetlayout = new QHBoxLayout();
  QWidget* centralWidget = new QWidget(this);
  sideMenu =new SideMenu(centralWidget);
  centralWidgetlayout->addWidget(sideMenu);
  Grid* grid = new Grid(QSize(100, 100), 64, this);
  canvas = new Canvas(grid, centralWidget);
  centralWidgetlayout->addWidget(canvas);
  setCentralWidget(centralWidget);
  centralWidget->setLayout(centralWidgetlayout);
  connect(sideMenu, SIGNAL(brushChanged(int)),
          canvas, SLOT(setBrush(int)));
  menuControler = new MenuController(this);
  connect(menuControler, SIGNAL(gridLineVisibilityChanged(bool)),
          grid, SLOT(setLineVisibility(bool)));
  resize(QDesktopWidget().availableGeometry(this).size() * 0.5);

}

//void MainWindow::createMenu(){

//}
