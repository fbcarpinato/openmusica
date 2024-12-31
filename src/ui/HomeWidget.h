#pragma once

#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class HomeWidget : public QWidget {
  Q_OBJECT

public:
  HomeWidget(QWidget *parent = nullptr);

signals:
  void logout();

public slots:
  void onPlaylistsFetched(const QStringList &playlists);

private slots:
  void onLogout();

private:
  QListWidget *playlistsWidget;
};
