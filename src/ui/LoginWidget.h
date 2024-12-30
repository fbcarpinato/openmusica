#pragma once

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class LoginWidget : public QWidget {
  Q_OBJECT

public:
  LoginWidget(QWidget *parent = nullptr);

signals:
  void login();

private slots:
  void onLogin();
};
