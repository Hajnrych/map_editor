#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

class Canvas;
class SideMenu;
class MenuController;
class TerrainFactory;

class MainWindow: public QMainWindow
{
  Q_OBJECT
public:
  MainWindow(QWidget *parent = 0);
  //~MainWindow();
private:
  Canvas* canvas;
  SideMenu* sideMenu;
  MenuController* menuControler;
  TerrainFactory* terrainFactory;
};

#endif // MAINWINDOW_H
