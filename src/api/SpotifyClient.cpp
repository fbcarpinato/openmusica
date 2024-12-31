#include "SpotifyClient.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

SpotifyClient::SpotifyClient(const QString &accessToken, QObject *parent)
    : QObject(parent), accessToken(accessToken) {
  networkManager = new QNetworkAccessManager(this);
}

void SpotifyClient::fetchPlaylists() {
  QUrl url("https://api.spotify.com/v1/me/playlists");

  QNetworkRequest request(url);

  qDebug() << accessToken;

  request.setRawHeader("Authorization", "Bearer " + accessToken.toUtf8());

  QNetworkReply *reply = networkManager->get(request);
  connect(reply, &QNetworkReply::finished, this,
          [this, reply]() { onPlaylistsFetched(reply); });
}

void SpotifyClient::onPlaylistsFetched(QNetworkReply *reply) {
  if (reply->error() != QNetworkReply::NoError) {
    qWarning() << "Error while fetching playlists" << reply->error();
    reply->deleteLater();
    return;
  }

  QByteArray response = reply->readAll();
  QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
  QJsonObject jsonObject = jsonDoc.object();

  QStringList playlists;
  QJsonArray items = jsonObject["items"].toArray();

  for (const QJsonValue &item : items) {
    QString name = item.toObject()["name"].toString();
    playlists.append(name);
  }

  emit playlistsFetched(playlists);
  reply->deleteLater();
}
