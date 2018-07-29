#include "MainWindow.h"
#include <Canvas.h>
#include <QWidget>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent){
  QVBoxLayout* centralWidgetlayout = new QVBoxLayout();
  QWidget* centralWidget = new QWidget(this);
  canvas = new Canvas(centralWidget);
  centralWidgetlayout->addWidget(canvas);
  setCentralWidget(centralWidget);
  centralWidget->setLayout(centralWidgetlayout);
  showMaximized();
}

MainWindow::~MainWindow(){

}
