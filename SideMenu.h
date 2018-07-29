#ifndef SIDEMENU_H
#define SIDEMENU_H
#include <QWidget>

class QGridLayout;

class SideMenu: public QWidget
{
  Q_OBJECT
public:
  explicit SideMenu(QWidget *parent = nullptr);
private:
  QGridLayout* layout;
  void createButtons();
};

#endif // SIDEMENU_H
