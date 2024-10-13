#include <QApplication>
#include <QPushButton>

#include "core/App.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  App appWindow;

  appWindow.show();

  return app.exec();
}
