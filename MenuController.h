#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H
#include <QObject>

class QMenuBar;
class QAction;
class QMainWindow;

class MenuController : public QObject
{
  Q_OBJECT
public:
  explicit MenuController(QMainWindow* mainWin);
signals:
  void gridLineVisibilityChanged(bool);
public slots:
  void toggleGridLineVisibility();
private:
  QMenuBar* menuBar;
  QAction* showGridLinesAction;
  void createViewMenu();
  bool linesVisible;
};

#endif // MENUCONTROLLER_H
