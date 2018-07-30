#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H
#include <QObject>
#include <QList>

class QMenuBar;
class QAction;
class QMainWindow;
class QSignalMapper;

class MenuController : public QObject
{
  Q_OBJECT
public:
  explicit MenuController(QMainWindow* mainWin);
  void createEditMenu(int pitch);
signals:
  void gridLineVisibilityChanged(bool);
  void brushRadiusChanged(int);
  void diffusionRequested();
public slots:
  void toggleGridLineVisibility();
private:
  QMenuBar* menuBar;
  QAction* showGridLinesAction;
  //QAction* diffuseAction;
  QList<QAction*> brushActions;
  void createViewMenu();
  //void createActionMenu();
  bool linesVisible;
  QSignalMapper* brushSignalMapper;
};

#endif // MENUCONTROLLER_H
