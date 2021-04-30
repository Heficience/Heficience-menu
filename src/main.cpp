#include "mainwindow.h"
#include <QApplication>
#include <QWebEngineSettings>
#include <QtWebEngineWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Handy Open Source");
    QCoreApplication::setOrganizationDomain("https://www.handy-open-source.org/");
    QCoreApplication::setApplicationName("dvkbuntu-easy-menu-qt");

    MainWindow w;
    w.setWindowState(Qt::WindowMaximized);
    w.showFullScreen();

    return a.exec();
}
