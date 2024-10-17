#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), auth(new SpotifyAuth(this)) {
  QPushButton *authButton = new QPushButton("Authenticate with Spotify", this);
  setCentralWidget(authButton);

  connect(authButton, &QPushButton::clicked, auth, &SpotifyAuth::grant);
  connect(auth, &SpotifyAuth::authenticated, this,
          &MainWindow::onAuthenticated);
}
