#ifndef SIDEMENU_H
#define SIDEMENU_H
#include <QWidget>

class QGridLayout;
class QSignalMapper;

class SideMenu: public QWidget
{
  Q_OBJECT
public:
  explicit SideMenu(QWidget *parent = nullptr);
signals:
  void brushChanged(int);
private:
  QGridLayout* layout;
  QSignalMapper* signalMapper;
  void createButtons();
  void createButton(QString name, int ix, int iy, int brush);
};

#endif // SIDEMENU_H
