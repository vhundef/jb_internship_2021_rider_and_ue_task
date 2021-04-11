//
// Created by vhundef on 02.04.2021.
//
#include "MainWindow.hxx"
#include <QApplication>
#include <QFile>

#include <QScreen>
#include <QStyleFactory>
#include <Qpair>

QString readStyleSheetFromFile(const QString &filename);
QPair<int, int> getScreenSize();

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    QApplication::setStyle(QStyleFactory::create("fusion"));
    app.setStyleSheet(readStyleSheetFromFile("styleSheet.qss"));
    MainWindow mainWindow(getScreenSize());
    mainWindow.show();
    QApplication::exec();
    mainWindow.terminate();
    return 0;
}

QString readStyleSheetFromFile(const QString &filename) {
    QFile file(filename);
    file.open(QFile::ReadOnly);
    return QLatin1String(file.readAll());
}


QPair<int, int> getScreenSize() {
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    return {width, height};
}
