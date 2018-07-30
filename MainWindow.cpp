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
#include <TerrainFactory.h>
#include <TerrainType.h>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent){
  QHBoxLayout* centralWidgetlayout = new QHBoxLayout();
  QWidget* centralWidget = new QWidget(this);
  Grid* grid = new Grid(QSize(200, 200), 32, this);
  terrainFactory = new TerrainFactory(grid->getPitch(), this);
  sideMenu =new SideMenu(centralWidget);
  sideMenu->createButtons(terrainFactory);
  centralWidgetlayout->addWidget(sideMenu);
  canvas = new Canvas(terrainFactory, grid, centralWidget);
  centralWidgetlayout->addWidget(canvas);
  setCentralWidget(centralWidget);
  centralWidget->setLayout(centralWidgetlayout);
  connect(sideMenu, SIGNAL(brushChanged(int)),
          terrainFactory, SLOT(setType(int)));
  grid->setCellBrushForAllCells(terrainFactory->getDefaultTerrain()->getBrush());
  menuControler = new MenuController(this);
  menuControler->createEditMenu(grid->getPitch());
  connect(menuControler, SIGNAL(gridLineVisibilityChanged(bool)),
          grid, SLOT(setLineVisibility(bool)));
//  connect(menuControler, SIGNAL(diffusionRequested()),
//          grid, SLOT(diffuse()));
  connect(menuControler, SIGNAL(brushRadiusChanged(int)),
          terrainFactory, SLOT(setBrushRadius(int)));
  resize(QDesktopWidget().availableGeometry(this).size() * 0.5);

}

//void MainWindow::createMenu(){

//}
