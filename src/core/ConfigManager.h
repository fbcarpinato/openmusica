#pragma once

#include <QString>

class ConfigManager {
public:
  ConfigManager();

  QString clientId() const { return m_clientId; }
  QString clientSecret() const { return m_clientSecret; }

private:
  QString m_clientId;
  QString m_clientSecret;
};
