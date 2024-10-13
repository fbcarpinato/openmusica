#ifndef APP_H
#define APP_H

#include <QMainWindow>
#include <QPushButton>

class App : public QMainWindow {
  Q_OBJECT

public:
  explicit App(QWidget *parent = nullptr);

private:
  QPushButton *loginButton;
};

#endif
