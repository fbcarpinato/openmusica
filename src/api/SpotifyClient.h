#pragma once

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>

class SpotifyClient : public QObject {
  Q_OBJECT

public:
  explicit SpotifyClient(const QString &access_token,
                         QObject *parent = nullptr);

  void fetchPlaylists();

private:
  QNetworkAccessManager *networkManager;
  QString accessToken;
};
