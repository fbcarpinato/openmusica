#include "HomeWidget.h"
#include <qlabel.h>

HomeWidget::HomeWidget(QWidget *parent) {
  QVBoxLayout *layout = new QVBoxLayout(this);

  QLabel *label = new QLabel("Authenticated!", this);

  QPushButton *logoutButton = new QPushButton("Logout", this);
  connect(logoutButton, &QPushButton::clicked, this, &HomeWidget::onLogout);

  layout->addWidget(label);
  layout->addWidget(logoutButton);

  setLayout(layout);
}

void HomeWidget::onLogout() { emit logout(); }
