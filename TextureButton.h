#ifndef ICONBUTTON_H
#define ICONBUTTON_H
#include <QPushButton>

class TextureButton: public QPushButton
{
  Q_OBJECT
public:
  explicit TextureButton(const QColor& color, QWidget *parent = nullptr);
};

#endif // ICONBUTTON_H
