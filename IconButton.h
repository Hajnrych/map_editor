#ifndef ICONBUTTON_H
#define ICONBUTTON_H
#include <QPushButton>

class IconButton: public QPushButton
{
  Q_OBJECT
public:
  explicit IconButton(QString name, QWidget *parent = nullptr);

signals:

public slots:
};

#endif // ICONBUTTON_H
