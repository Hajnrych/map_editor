#ifndef SIDEMENU_H
#define SIDEMENU_H
#include <QWidget>

class QGridLayout;
class QSignalMapper;
class TerrainFactory;

class SideMenu: public QWidget
{
  Q_OBJECT
public:
  explicit SideMenu(QWidget *parent = nullptr);
  void createButtons(TerrainFactory* terrainFactory);
signals:
  void brushChanged(int);
private:
  QGridLayout* layout;
  QSignalMapper* signalMapper;
};

#endif // SIDEMENU_H
