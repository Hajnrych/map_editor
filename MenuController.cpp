#include "MenuController.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <Grid.h>
#include <QMainWindow>
#include <QSignalMapper>

MenuController::MenuController(QMainWindow* mainWin):
  QObject(mainWin),
  showGridLinesAction(0), linesVisible(true){
  menuBar = mainWin->menuBar();
  createViewMenu();
  //createActionMenu();
  brushSignalMapper = new QSignalMapper();
}

void MenuController::createViewMenu(){
  QMenu* viewMenu = menuBar->addMenu("View");
  showGridLinesAction = new QAction("Hide grid lines", this);
  connect(showGridLinesAction, SIGNAL(triggered(bool)), this,
          SLOT(toggleGridLineVisibility()));
  viewMenu->addAction(showGridLinesAction);
}

//void MenuController::createActionMenu(){
//  QMenu* actionMenu = menuBar->addMenu("Action");
//  diffuseAction = new QAction("Diffuse edges", this);
//  connect(diffuseAction, SIGNAL(triggered(bool)), this,
//          SIGNAL(diffusionRequested()));
//  actionMenu->addAction(diffuseAction);
//}

void MenuController::createEditMenu(int pitch){
  QMenu* viewMenu = menuBar->addMenu(tr("&Edit"));
  QList<int> brushSizes;
  brushSizes << pitch/2 << 2 * pitch << 4 * pitch << 8 * pitch << 16 * pitch;
  foreach (int brushSize, brushSizes) {
    QAction* brushAction = new QAction(
          QString("&Activate brush size %1").arg(2*brushSize/(pitch)), this);
    viewMenu->addAction(brushAction);
    connect(brushAction, SIGNAL(triggered(bool)), brushSignalMapper, SLOT(map()));
    brushSignalMapper->setMapping(brushAction, brushSize);
  }
  connect(brushSignalMapper, SIGNAL(mapped(int)),
          this, SIGNAL(brushRadiusChanged(int)));
}

void MenuController::toggleGridLineVisibility(){
  linesVisible = !linesVisible;
  if (linesVisible)
    showGridLinesAction->setText("Hide grid lines");
  else
    showGridLinesAction->setText("Show grid lines");
  emit gridLineVisibilityChanged(linesVisible);
}
