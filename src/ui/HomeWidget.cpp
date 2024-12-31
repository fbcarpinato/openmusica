#include "HomeWidget.h"

#include <QLabel>

HomeWidget::HomeWidget(QWidget *parent) {
  QVBoxLayout *layout = new QVBoxLayout(this);

  QLabel *label = new QLabel("Authenticated!", this);

  QPushButton *logoutButton = new QPushButton("Logout", this);
  connect(logoutButton, &QPushButton::clicked, this, &HomeWidget::onLogout);

  playlistsWidget = new QListWidget(this);

  layout->addWidget(label);
  layout->addWidget(playlistsWidget);
  layout->addWidget(logoutButton);

  setLayout(layout);
}

void HomeWidget::onLogout() { emit logout(); }

void HomeWidget::onPlaylistsFetched(const QStringList &playlists) {
  playlistsWidget->clear();
  playlistsWidget->addItems(playlists);
}
