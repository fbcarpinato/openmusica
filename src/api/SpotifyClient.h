#pragma once

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <qnetworkreply.h>

class SpotifyClient : public QObject {
  Q_OBJECT

public:
  explicit SpotifyClient(const QString &access_token,
                         QObject *parent = nullptr);

  void fetchPlaylists();

signals:
  void playlistsFetched(const QStringList &playlists);

private slots:
  void onPlaylistsFetched(QNetworkReply *reply);

private:
  QNetworkAccessManager *networkManager;
  QString accessToken;
};
