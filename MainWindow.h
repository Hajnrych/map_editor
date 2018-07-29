#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

class Canvas;

class MainWindow: public QMainWindow
{
  Q_OBJECT
public:
  MainWindow(QWidget *parent = 0);
  ~MainWindow();
private:
  Canvas* canvas;
};

#endif // MAINWINDOW_H
