#include "SpotifyAuth.h"
#include "ConfigManager.h"

SpotifyAuth::SpotifyAuth(QObject *parent)
    : QObject(parent), oauth2(new QOAuth2AuthorizationCodeFlow(this)) {
  QString clientId = ConfigManager::instance().clientId();
  QString clientSecret = ConfigManager::instance().clientSecret();

  auto replyHandler = new QOAuthHttpServerReplyHandler(9994, this);
  oauth2->setReplyHandler(replyHandler);

  oauth2->setAuthorizationUrl(QUrl("https://accounts.spotify.com/authorize"));
  oauth2->setAccessTokenUrl(QUrl("https://accounts.spotify.com/api/token"));
  oauth2->setClientIdentifier(clientId);
  oauth2->setClientIdentifierSharedKey(clientSecret);

  connect(oauth2, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser,
          &QDesktopServices::openUrl);

  connect(oauth2, &QOAuth2AuthorizationCodeFlow::granted, this,
          &SpotifyAuth::granted);
}

void SpotifyAuth::granted() {
  qDebug() << "Access token:" << oauth2->token();

  ConfigManager::instance().saveAccessToken(oauth2->token());

  emit authenticated();
}
