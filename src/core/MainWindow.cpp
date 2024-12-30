#include "MainWindow.h"
#include "ConfigManager.h"

#include "../ui/HomeWidget.h"
#include "../ui/LoginWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), auth(new SpotifyAuth(this)), m_authenticated(false) {
  m_authenticated = !ConfigManager::instance().getAccessToken().isEmpty();

  if (!m_authenticated) {
    this->onLogout();
  } else {
    this->onAuthenticated();
  }
}

void MainWindow::onLogout() {
  m_authenticated = false;
  ConfigManager::instance().deleteAccessToken();
  qDebug() << "Logged out!";

  LoginWidget *loginWidget = new LoginWidget(this);

  connect(loginWidget, &LoginWidget::login, auth, &SpotifyAuth::grant);
  connect(auth, &SpotifyAuth::authenticated, this,
          &MainWindow::onAuthenticated);

  setCentralWidget(loginWidget);
}

void MainWindow::onAuthenticated() {
  m_authenticated = true;

  HomeWidget *homeWidget = new HomeWidget(this);
  connect(homeWidget, &HomeWidget::logout, this, &MainWindow::onLogout);

  setCentralWidget(homeWidget);
}
