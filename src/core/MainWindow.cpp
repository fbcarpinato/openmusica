#include "MainWindow.h"
#include "ConfigManager.h"

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

  QPushButton *authButton = new QPushButton("Authenticate with Spotify", this);
  setCentralWidget(authButton);

  connect(authButton, &QPushButton::clicked, auth, &SpotifyAuth::grant);
  connect(auth, &SpotifyAuth::authenticated, this,
          &MainWindow::onAuthenticated);
}

void MainWindow::onAuthenticated() {
  m_authenticated = true;

  QLabel *label = new QLabel("Authenticated!", this);

  QPushButton *logoutButton = new QPushButton("Logout", this);
  connect(logoutButton, &QPushButton::clicked, this, &MainWindow::onLogout);

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(label);
  layout->addWidget(logoutButton);

  QWidget *widget = new QWidget(this);
  widget->setLayout(layout);
  setCentralWidget(widget);
}
