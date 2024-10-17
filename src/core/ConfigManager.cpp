#include "ConfigManager.h"

ConfigManager::ConfigManager() {
  m_clientId = qgetenv("SPOTIFY_CLIENT_ID");
  m_clientSecret = qgetenv("SPOTIFY_CLIENT_SECRET");

  if (m_clientId.isEmpty() || m_clientSecret.isEmpty()) {
    qFatal("Please set the SPOTIFY_CLIENT_ID and SPOTIFY_CLIENT_SECRET "
           "environment variables");
  }
}
