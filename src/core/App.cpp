#include "App.h"

App::App(QWidget *parent) : QMainWindow(parent) {
  setWindowTitle("OpenMusica");
  resize(400, 300);

  // Add a login button for example
  loginButton = new QPushButton("Login", this);
  loginButton->setGeometry(QRect(QPoint(150, 100), QSize(100, 50)));
}
