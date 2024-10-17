#include "ConfigManager.h"

ConfigManager::ConfigManager() {
  m_clientId = qgetenv("SPOTIFY_CLIENT_ID");
  m_clientSecret = qgetenv("SPOTIFY_CLIENT_SECRET");

  if (m_clientId.isEmpty() || m_clientSecret.isEmpty()) {
    qFatal("Please set the SPOTIFY_CLIENT_ID and SPOTIFY_CLIENT_SECRET "
           "environment variables");
  }
}

ConfigManager::~ConfigManager() {}

ConfigManager &ConfigManager::instance() {
  static ConfigManager instance;
  return instance;
}

QString ConfigManager::clientId() const { return m_clientId; }
QString ConfigManager::clientSecret() const { return m_clientSecret; }

QString ConfigManager::getAccessToken() const {
  QSettings settings;
  return settings.value("access_token").toString();
}

void ConfigManager::saveAccessToken(const QString &accessToken) {
  QSettings settings;
  settings.setValue("access_token", accessToken);
}

void ConfigManager::deleteAccessToken() {
  QSettings settings;
  settings.remove("access_token");
}
