#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  app.setApplicationName("OpenMusica");
  app.setApplicationVersion("0.1");

  QPushButton button("Hello, Wayland!");
  button.resize(200, 60);
  button.show();

  return app.exec();
}
