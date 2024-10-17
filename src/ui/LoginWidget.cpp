#include "LoginWidget.h"

#define SPOTIFY_CLIENT_ID "9465bc906e384628bdee67a03fcea4c9"
#define SPOTIFY_REDIRECT_URL "openmusica://callback"
#define SPOTIFY_RESPONSE_TYPE "token"

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent) {
  QPushButton *loginButton = new QPushButton("Login", this);
  loginButton->setGeometry(0, 0, 100, 50);
  loginButton->move(50, 50);

  connect(loginButton, &QPushButton::clicked, this, &LoginWidget::login);
}

void LoginWidget::login() {
  std::string url =
      "https://accounts.spotify.com/authorize?client_id=" SPOTIFY_CLIENT_ID
      "&redirect_uri=" SPOTIFY_REDIRECT_URL
      "&response_type=" SPOTIFY_RESPONSE_TYPE;

  QDesktopServices::openUrl(QUrl(url.c_str()));
}
