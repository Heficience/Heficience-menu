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

    QSettings mySettings;

    mySettings.beginGroup("DarkMode");
    bool DarkMode = mySettings.value("DarkMode").toBool();
    mySettings.endGroup();

    if (DarkMode) {
        qputenv("QTWEBENGINE_CHROMIUM_FLAGS", "--blink-settings=forceDarkModeEnabled=true");
    } else {
        qputenv("QTWEBENGINE_CHROMIUM_FLAGS", "--blink-settings=forceDarkModeEnabled=false");
    }

    MainWindow w;
    w.setWindowState(Qt::WindowMaximized);
    w.showFullScreen();

    splash.finish(&w);
    return a.exec();
}
