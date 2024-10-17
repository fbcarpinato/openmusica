#pragma once

#include "ConfigManager.h"
#include <QDesktopServices>
#include <QOAuth2AuthorizationCodeFlow>
#include <QOAuthHttpServerReplyHandler>
#include <QObject>

class SpotifyAuth : public QObject {
  Q_OBJECT

public:
  SpotifyAuth(QObject *parent = nullptr);

  void grant() { oauth2->grant(); }

signals:
  void authenticated();

private slots:
  void granted();

private:
  QOAuth2AuthorizationCodeFlow *oauth2;
};
