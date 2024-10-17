#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QDesktopServices>
#include <QPushButton>
#include <QUrl>
#include <QWidget>

class LoginWidget : public QWidget {
  Q_OBJECT

public:
  LoginWidget(QWidget *parent = 0);

private slots:
  void login();
};

#endif
