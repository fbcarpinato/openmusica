#pragma once

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class HomeWidget : public QWidget {
  Q_OBJECT

public:
  HomeWidget(QWidget *parent = nullptr);

signals:
  void logout();

private slots:
  void onLogout();
};
