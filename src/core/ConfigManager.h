#pragma once

#include <QSettings>
#include <QString>

class ConfigManager {
public:
  static ConfigManager &instance();

  ConfigManager(const ConfigManager &) = delete;
  void operator=(const ConfigManager &) = delete;

  QString clientId() const;
  QString clientSecret() const;

  QString getAccessToken() const;
  void saveAccessToken(const QString &token);
  void deleteAccessToken();

private:
  ConfigManager();
  ~ConfigManager();

  void loadConfig();

  QString m_clientId;
  QString m_clientSecret;
  QString m_accessToken;
};
