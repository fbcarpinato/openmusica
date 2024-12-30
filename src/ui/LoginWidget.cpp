#include "LoginWidget.h"

LoginWidget::LoginWidget(QWidget *parent) {
  QVBoxLayout *layout = new QVBoxLayout(this);

  QPushButton *loginButton = new QPushButton("Login", this);
  connect(loginButton, &QPushButton::clicked, this, &LoginWidget::onLogin);

  loginButton->setFixedSize(100, 40);
  layout->addWidget(loginButton);

  setLayout(layout);
}

void LoginWidget::onLogin() { emit login(); }
