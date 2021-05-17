#include "options.h"
#include "./ui_options.h"
#include "mainwindow.h"
#include <QWindow>
#include <QSettings>
#include <QApplication>
#include <QProcess>
#include <QThread>
#include <QSettings>
#include <QDir>

Options::Options(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Options)
{
    ui->setupUi(this);

    screens = QGuiApplication::screens();
    screen = screens.first();
    screenGeometry = screen->geometry();
    HEIGHT = screenGeometry.height();
    WIDTH = screenGeometry.width();
    double dpi = QGuiApplication::primaryScreen()->physicalDotsPerInch();
    fSize2 = (int)((80*HEIGHT/2160)*72/dpi);

    int sizeButton = 80 * HEIGHT / 1080;

    ui->Arretoptions->setMaximumWidth(sizeButton);
    ui->Arretoptions->setMaximumHeight(sizeButton);
    ui->Arretoptions->setIconSize(QSize(sizeButton, sizeButton));

    font.setPointSize(fSize2);

    ui->Deezer->setFont(font);

    ui->YouTube->setFont(font);

    ui->Jamendo->setFont(font);

    ui->Choix->setFont(font);

    ui->Redemarrage->setFont(font);

    ui->gridWidget->resize(WIDTH, HEIGHT);

    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    pal.setColor(QPalette::WindowText, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->setStyleSheet("background-color:black; color:#fff;");
    mySettings.beginGroup("ChoixMusic");
    int myInt = mySettings.value("Music").toInt();
    mySettings.endGroup();
    switch (myInt) {
        case 0:
            ui->Jamendo->setChecked(true);
            ui->YouTube->setChecked(false);
            ui->Deezer->setChecked(false);
            break;
        case 1:
            ui->Jamendo->setChecked(false);
            ui->YouTube->setChecked(true);
            ui->Deezer->setChecked(false);
            break;
        default:
            ui->Jamendo->setChecked(false);
            ui->YouTube->setChecked(false);
            ui->Deezer->setChecked(true);
            break;
    }

    CanUse = true;
    this->showFullScreen();
}

Options::~Options()
{
    delete ui;
}

void Options::on_Arretoptions_clicked()
{
    this->close();
}

void Options::on_Jamendo_toggled()
{
    if (CanUse == true) {
        mySettings.beginGroup("ChoixMusic");
        mySettings.setValue("Music", 0);
        mySettings.endGroup();
        qApp->closeAllWindows();
        //qApp->quit();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
        this->close();
    }
}

void Options::on_YouTube_toggled()
{
    if (CanUse == true) {
        mySettings.beginGroup("ChoixMusic");
        mySettings.setValue("Music", 1);
        mySettings.endGroup();
        qApp->closeAllWindows();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
        this->close();
    }
}

void Options::on_Deezer_toggled()
{
    if (CanUse == true) {
        mySettings.beginGroup("ChoixMusic");
        mySettings.setValue("Music", 2);
        mySettings.endGroup();
        qApp->closeAllWindows();
        qApp->quit();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
        this->close();
    }
}