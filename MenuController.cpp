#include "MenuController.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <Grid.h>
#include <QMainWindow>

MenuController::MenuController(QMainWindow* mainWin):
  QObject(mainWin),
  showGridLinesAction(0), linesVisible(true){
  menuBar = mainWin->menuBar();
  createViewMenu();
}

void MenuController::createViewMenu(){
  QMenu* viewMenu = menuBar->addMenu(tr("&View"));
  showGridLinesAction = new QAction(tr("&Hide grid lines"), this);
  connect(showGridLinesAction, SIGNAL(triggered(bool)), this,
          SLOT(toggleGridLineVisibility()));
  viewMenu->addAction(showGridLinesAction);
}

void MenuController::toggleGridLineVisibility(){
  linesVisible = !linesVisible;
  if (linesVisible)
    showGridLinesAction->setText(tr("&Hide grid lines"));
  else
    showGridLinesAction->setText(tr("&Show grid lines"));
  emit gridLineVisibilityChanged(linesVisible);
}
