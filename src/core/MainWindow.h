#pragma once

#include <QLabel>
#include <QMainWindow>
#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>

#include "SpotifyAuth.h"

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow() { delete auth; }

private slots:
  void onAuthenticated();
  void onLogout();

private:
  SpotifyAuth *auth;
  bool m_authenticated;
};
