#include "SpotifyClient.h"

SpotifyClient::SpotifyClient(const QString &accessToken, QObject *parent)
    : QObject(parent), accessToken(accessToken) {
  networkManager = new QNetworkAccessManager(this);
}

void SpotifyClient::fetchPlaylists() {
  QUrl url("https://api.spotify.com/v1/me/playlists");

  QNetworkRequest request(url);

  request.setRawHeader("Authorization", "Bearer: " + accessToken.toUtf8());

  QNetworkReply *reply = networkManager->get(request);
  connect(reply, &QNetworkReply::finished, this,
          [this, reply]() { qDebug("Request finished"); });
}
