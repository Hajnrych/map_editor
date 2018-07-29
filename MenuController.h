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
public slots:
  void toggleGridLineVisibility();
private:
  QMenuBar* menuBar;
  QAction* showGridLinesAction;
  QList<QAction*> brushActions;
  void createViewMenu();
  bool linesVisible;
  QSignalMapper* brushSignalMapper;
};

#endif // MENUCONTROLLER_H
