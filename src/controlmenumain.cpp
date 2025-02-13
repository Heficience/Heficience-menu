#include "controlmenumain.h"
#include "ui_controlmenumain.h"
#include "options.h"
#include "ui_options.h"
#include <QDesktopWidget>
#include <QTimer>
#include <QWindow>
#include <QGuiApplication>
#include <QRect>
#include <QScreen>
#include <string>
#include <QTextStream>
#include <QDockWidget>
#include <QTreeWidget>
#include <map>
#include <QSettings>
#include <QTextToSpeech>

ControlMenuMain::ControlMenuMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlMenuMain) {
    ui->setupUi(this);

    screens = QGuiApplication::screens();
    screen = screens.first();
    screenGeometry = screen->geometry();
    HEIGHT = screenGeometry.height();
    WIDTH = screenGeometry.width();
    double dpi = QGuiApplication::primaryScreen()->physicalDotsPerInch();
    fSize2 = (int) ((80 * HEIGHT / 2160) * 72 / (dpi * 1.5));

    int sizeButton = 80 * HEIGHT / 1080;

    ui->Fermeture->setMaximumWidth(sizeButton);
    ui->Fermeture->setMaximumHeight(sizeButton);
    ui->Fermeture->setIconSize(QSize(sizeButton, sizeButton));
    //ui->Fermeture->setObjectName("Fermeture");
    //ui->Fermeture->setStyleSheet("QToolButton#Fermeture:hover {background-color: rgb(0, 0, 0);}");

    ui->Home->setMaximumWidth(sizeButton);
    ui->Home->setMaximumHeight(sizeButton);
    ui->Home->setIconSize(QSize(sizeButton, sizeButton));
    //ui->Home->setObjectName("Home");
    //ui->Home->setStyleSheet("QToolButton#Home:hover {background-color: grey;}");
/**
    ui->Options->setMaximumWidth(sizeButton);
    ui->Options->setMaximumHeight(sizeButton);
    ui->Options->setIconSize(QSize(sizeButton, sizeButton));
**/
    mySettings.beginGroup("DarkMode");
    DarkMode = mySettings.value("DarkMode").toBool();
    mySettings.endGroup();

    FirstTime = true;

    if (DarkMode) {
        ui->DarkMode->toggle();
        qputenv("QTWEBENGINE_CHROMIUM_FLAGS", "--blink-settings=forceDarkModeEnabled=true,darkModeInversionAlgorithm=4");
    } else {
        ui->NormalMode->toggle();
        qputenv("QTWEBENGINE_CHROMIUM_FLAGS", "--blink-settings=forceDarkModeEnabled=false,darkModeInversionAlgorithm=0");
    }

    FirstTime = false;

    QFont font;
    font.setPointSize(fSize2);
    ui->DarkMode->setBaseSize(sizeButton, sizeButton);
    ui->DarkMode->setMinimumWidth(3.5 * sizeButton);
    ui->DarkMode->setMinimumHeight(sizeButton);
    ui->DarkMode->setFont(font);
    ui->NormalMode->setBaseSize(sizeButton, sizeButton);
    ui->NormalMode->setMinimumWidth(3.5 * sizeButton);
    ui->NormalMode->setMinimumHeight(sizeButton);
    ui->NormalMode->setFont(font);
    ui->Theme->setMinimumHeight(sizeButton);
    ui->Theme->setFont(font);

    ui->PowerOff->setMaximumWidth(sizeButton);
    ui->PowerOff->setMaximumHeight(sizeButton);
    ui->PowerOff->setIconSize(QSize(sizeButton, sizeButton));
    //ui->PowerOff->setObjectName("PowerOff");
    //ui->PowerOff->setStyleSheet("QToolButton#PowerOff:hover {background-color: rgb(0, 0, 0);}");

    int Size = (int)((1920 * 1920 * dpi) / WIDTH);

    ui->Horlorge->setMinimumWidth(sizeButton*1.5);
    ui->Horlorge->setMaximumWidth(Size);

    ui->gridLayout->setColumnMinimumWidth(1,Size);

    WIDTHCONTROL = int(WIDTH * 720 / 3840 - 50);

    ui->gridWidget->resize(WIDTHCONTROL, HEIGHT - 50);

/**
    setMouseTracking(true);
    setAttribute(Qt::WA_Hover);
    raise();
**/

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ControlMenuMain::showTime);
    timer->start(1000);

    showTime();
}

ControlMenuMain::~ControlMenuMain()
{
    delete ui;
}

void ControlMenuMain::on_DarkMode_toggled(bool checked)
{
    if (checked) {
        mySettings.beginGroup("DarkMode");
        mySettings.setValue("DarkMode", true);
        qputenv("QTWEBENGINE_CHROMIUM_FLAGS", "--blink-settings=forceDarkModeEnabled=true,darkModeInversionAlgorithm=4");
        mySettings.endGroup();
        if (!FirstTime) {
            QTimer *timer = new QTimer(this);
            connect(timer, &QTimer::timeout, this, &ControlMenuMain::Reload);
            timer->start(1000);
        }
    }
}

void ControlMenuMain::on_NormalMode_toggled(bool checked)
{
    if (checked) {
        mySettings.beginGroup("DarkMode");
        mySettings.setValue("DarkMode", false);
        qputenv("QTWEBENGINE_CHROMIUM_FLAGS", "--blink-settings=forceDarkModeEnabled=false,darkModeInversionAlgorithm=0");
        mySettings.endGroup();
        if (!FirstTime) {
            QTimer *timer = new QTimer(this);
            connect(timer, &QTimer::timeout, this, &ControlMenuMain::Reload);
            timer->start(1000);
        }
    }
}

void ControlMenuMain::on_Fermeture_clicked()
{
/**#ifndef __APPLE__
    MainWindow().KCalculatrice->close();
    MainWindow().Email->close();
    MainWindow().web->close();
    MainWindow().Music->close();
    MainWindow().office->close();
    MainWindow().DiscordLauncher->close();
    MainWindow().ma_fenetreG->destroy();
    MainWindow().FenC->close();
    MainWindow().FenE->close();
    MainWindow().FenI->close();
    MainWindow().FenM->close();
    MainWindow().FenN->close();
    MainWindow().FenD->close();
    MainWindow().FenG->close();
    qApp->closeAllWindows();
#endif**/
    QCoreApplication::quit();
}

void ControlMenuMain::on_Home_clicked() {

}

/**void ControlMenuMain::on_Options_clicked() {
    Options *myOptions = new Options();
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    pal.setColor(QPalette::WindowText, Qt::white);
    myOptions->setAutoFillBackground(true);
    myOptions->setPalette(pal);
    myOptions->setStyleSheet("background-color:black; color:#fff");
    myOptions->show();
}**/

void ControlMenuMain::on_PowerOff_clicked() {
    QProcess Extinction;
#ifdef __linux__
    Extinction.startDetached("shutdown -P now");
#elif _WIN32
    QString myProg="shutdown";
    QStringList myArgs={"-s", "-f", "-t 00"};
    Extinction.startDetached(myProg,myArgs);
#elif __APPLE__
    Extinction.startDetached("shutdown -h now");
#endif
}

void ControlMenuMain::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    QFont font;
    font.setPointSize(fSize2);

    ui->Horlorge->setFont(font);
    ui->Horlorge->setText(text);
}

void ControlMenuMain::Reload()
{
    qApp->closeAllWindows();
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    this->parentWidget()->close();
}
