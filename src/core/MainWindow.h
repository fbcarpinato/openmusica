#pragma once

#include <QMainWindow>
#include <QObject>
#include <QPushButton>

#include "SpotifyAuth.h"

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);

private slots:
  void onAuthenticated() { qDebug() << "Authentication successful!"; }

private:
  SpotifyAuth *auth;
};
