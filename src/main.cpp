#include "mainwindow.h"
#include <QApplication>
#include <QWebEngineSettings>
#include <QtWebEngineWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap(":/Images/splash.png");
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();

    QCoreApplication::setOrganizationName("Handy Open Source");
    QCoreApplication::setOrganizationDomain("https://www.handy-open-source.org/");
    QCoreApplication::setApplicationName("dvkbuntu-easy-menu");

    MainWindow w;
    w.setWindowState(Qt::WindowMaximized);
    w.showFullScreen();

    QMainWindow window;
    window.show();
    splash.finish(&window);
    return a.exec();
}
