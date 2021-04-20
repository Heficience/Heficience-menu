#include "controlmenumail.h"
#include "ui_controlmenumail.h"
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
#include <QAction>

ControlMenuMail::ControlMenuMail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlMenuMail)
{
    ui->setupUi(this);

    screens = QGuiApplication::screens();
    screen = screens.first();
    screenGeometry = screen->geometry();
    HEIGHT = screenGeometry.height();
    WIDTH = screenGeometry.width();
    WIDTHCONTROL = int(WIDTH * 720 / 3840);
    WIDTHMAIN = WIDTH -WIDTHCONTROL;
    double dpi = QGuiApplication::primaryScreen()->physicalDotsPerInch();
    fSize2 = (int)((80*HEIGHT/2160)*72/dpi);
    myScale = QString::number(int(2.5 * (dpi /159.856) * (WIDTH / 3840)));

    int sizeButton = 80 * HEIGHT / 1080;

    ui->Fermeture->setMaximumWidth(sizeButton);
    ui->Fermeture->setMaximumHeight(sizeButton);
    ui->Fermeture->setIconSize(QSize(sizeButton, sizeButton));

    ui->Home->setMaximumWidth(sizeButton);
    ui->Home->setMaximumHeight(sizeButton);
    ui->Home->setIconSize(QSize(sizeButton, sizeButton));

    ui->Options->setMaximumWidth(sizeButton);
    ui->Options->setMaximumHeight(sizeButton);
    ui->Options->setIconSize(QSize(sizeButton, sizeButton));

    ui->Gmail->setMaximumWidth(sizeButton);
    ui->Gmail->setMaximumHeight(sizeButton);
    ui->Gmail->setIconSize(QSize(sizeButton, sizeButton));

    ui->Outlook->setMaximumWidth(sizeButton);
    ui->Outlook->setMaximumHeight(sizeButton);
    ui->Outlook->setIconSize(QSize(sizeButton, sizeButton));

    ui->Yahoo->setMaximumWidth(sizeButton);
    ui->Yahoo->setMaximumHeight(sizeButton);
    ui->Yahoo->setIconSize(QSize(sizeButton, sizeButton));

    ui->Orange->setMaximumWidth(sizeButton);
    ui->Orange->setMaximumHeight(sizeButton);
    ui->Orange->setIconSize(QSize(sizeButton, sizeButton));

    ui->SFR->setMaximumWidth(sizeButton);
    ui->SFR->setMaximumHeight(sizeButton);
    ui->SFR->setIconSize(QSize(sizeButton, sizeButton));

    ui->Free->setMaximumWidth(sizeButton);
    ui->Free->setMaximumHeight(sizeButton);
    ui->Free->setIconSize(QSize(sizeButton, sizeButton));

    ui->Bouygues->setMaximumWidth(sizeButton);
    ui->Bouygues->setMaximumHeight(sizeButton);
    ui->Bouygues->setIconSize(QSize(sizeButton, sizeButton));

    ui->LaPoste->setMaximumWidth(sizeButton);
    ui->LaPoste->setMaximumHeight(sizeButton);
    ui->LaPoste->setIconSize(QSize(sizeButton, sizeButton));

    int Size = (int)((1920 * 1920 * dpi) / WIDTH);

    ui->Horlorge->setMaximumWidth(Size);

    ui->gridLayout->setColumnMinimumWidth(1,Size);

    WIDTHCONTROL = int(WIDTH * 720 / 3840 -50);

    ui->gridWidget->resize(WIDTHCONTROL, HEIGHT - 50);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ControlMenuMail::showTime);
    timer->start(1000);

    showTime();
}

ControlMenuMail::~ControlMenuMail()
{
    delete ui;
}

void ControlMenuMail::on_Fermeture_clicked()
{
    this->parentWidget()->close();
}
void ControlMenuMail::on_Home_clicked() {
    this->parentWidget()->close();
}

void ControlMenuMail::on_Options_clicked() {
    Options *myOptions = new Options();
    myOptions->show();
}

void ControlMenuMail::on_Gmail_clicked() {
    ChoixServiceMail = QString::fromUtf8("0");
    SetValue.start("bash -c \"mkdir -p \"$HOME\"/.easymenu && echo \"" + ChoixServiceMail + "\" > \"$HOME\"/.easymenu/ServiceMail\"");
    SetValue.waitForFinished(-1);

    MyWebEnginePage *page = new MyWebEnginePage();
    mail->setPage(page);

    mail->load(QUrl("https://mail.google.com/"));

    mail->setZoomFactor(myScale.toInt());
    mail->setMinimumWidth(WIDTHMAIN);
    mail->setMinimumHeight(HEIGHT);
    FenE = new QWidget;
    myLayout = new QHBoxLayout(FenE);
    myLayout->addWidget(mail);
    menuE = new ControlMenuMail();
    menuE->setMaximumWidth(WIDTHCONTROL);
    menuE->setMaximumHeight(HEIGHT);
    myLayout->addWidget(menuE);
    FenE->showFullScreen();
    this->parentWidget()->close();
}

void ControlMenuMail::on_Outlook_clicked() {
    ChoixServiceMail = QString::fromUtf8("1");
    SetValue.start("bash -c \"mkdir -p \"$HOME\"/.easymenu && echo \"" + ChoixServiceMail + "\" > \"$HOME\"/.easymenu/ServiceMail\"");
    SetValue.waitForFinished(-1);

    MyWebEnginePage *page = new MyWebEnginePage();
    mail->setPage(page);

    mail->load(QUrl("https://outlook.live.com/owa/"));
    mail->setZoomFactor(myScale.toInt());
    mail->setMinimumWidth(WIDTHMAIN);
    mail->setMinimumHeight(HEIGHT);
    FenE = new QWidget;
    myLayout = new QHBoxLayout(FenE);
    myLayout->addWidget(mail);
    menuE = new ControlMenuMail();
    menuE->setMaximumWidth(WIDTHCONTROL);
    menuE->setMaximumHeight(HEIGHT);
    myLayout->addWidget(menuE);
    FenE->showFullScreen();
    this->parentWidget()->close();
}

void ControlMenuMail::on_Yahoo_clicked() {
    ChoixServiceMail = QString::fromUtf8("2");
    SetValue.start("bash -c \"mkdir -p \"$HOME\"/.easymenu && echo \"" + ChoixServiceMail + "\" > \"$HOME\"/.easymenu/ServiceMail\"");
    SetValue.waitForFinished(-1);

    MyWebEnginePage *page = new MyWebEnginePage();
    mail->setPage(page);

    mail->load(QUrl("https://login.yahoo.com/?.src=ym&lang=fr-FR&done=https%3A%2F%2Ffr.mail.yahoo.com"));
    mail->setZoomFactor(myScale.toInt());
    mail->setMinimumWidth(WIDTHMAIN);
    mail->setMinimumHeight(HEIGHT);
    FenE = new QWidget;
    myLayout = new QHBoxLayout(FenE);
    myLayout->addWidget(mail);
    menuE = new ControlMenuMail();
    menuE->setMaximumWidth(WIDTHCONTROL);
    menuE->setMaximumHeight(HEIGHT);
    myLayout->addWidget(menuE);
    FenE->showFullScreen();
    this->parentWidget()->close();
}

void ControlMenuMail::on_Orange_clicked() {
    ChoixServiceMail = QString::fromUtf8("3");
    SetValue.start("bash -c \"mkdir -p \"$HOME\"/.easymenu && echo \"" + ChoixServiceMail + "\" > \"$HOME\"/.easymenu/ServiceMail\"");
    SetValue.waitForFinished(-1);

    MyWebEnginePage *page = new MyWebEnginePage();
    mail->setPage(page);

    mail->load(QUrl("https://login.orange.fr/?return_url=https://rms.orange.fr/mail/inbox%3F"));
    mail->setZoomFactor(myScale.toInt());
    mail->setMinimumWidth(WIDTHMAIN);
    mail->setMinimumHeight(HEIGHT);
    FenE = new QWidget;
    myLayout = new QHBoxLayout(FenE);
    myLayout->addWidget(mail);
    menuE = new ControlMenuMail();
    menuE->setMaximumWidth(WIDTHCONTROL);
    menuE->setMaximumHeight(HEIGHT);
    myLayout->addWidget(menuE);
    FenE->showFullScreen();
    this->parentWidget()->close();
}

void ControlMenuMail::on_SFR_clicked() {
    ChoixServiceMail = QString::fromUtf8("4");
    SetValue.start("bash -c \"mkdir -p \"$HOME\"/.easymenu && echo \"" + ChoixServiceMail + "\" > \"$HOME\"/.easymenu/ServiceMail\"");
    SetValue.waitForFinished(-1);

    MyWebEnginePage *page = new MyWebEnginePage();
    mail->setPage(page);

    mail->load(QUrl("https://www.sfr.fr/cas/login?service=https%3A%2F%2Fwebmail.sfr.fr%2Fwebmail%2Fj_spring_cas_security_check"));
    mail->setZoomFactor(myScale.toInt());
    mail->setMinimumWidth(WIDTHMAIN);
    mail->setMinimumHeight(HEIGHT);
    FenE = new QWidget;
    myLayout = new QHBoxLayout(FenE);
    myLayout->addWidget(mail);
    menuE = new ControlMenuMail();
    menuE->setMaximumWidth(WIDTHCONTROL);
    menuE->setMaximumHeight(HEIGHT);
    myLayout->addWidget(menuE);
    FenE->showFullScreen();
    this->parentWidget()->close();
}

void ControlMenuMail::on_Free_clicked() {
    ChoixServiceMail = QString::fromUtf8("5");
    SetValue.start("bash -c \"mkdir -p \"$HOME\"/.easymenu && echo \"" + ChoixServiceMail + "\" > \"$HOME\"/.easymenu/ServiceMail\"");
    SetValue.waitForFinished(-1);

    MyWebEnginePage *page = new MyWebEnginePage();
    mail->setPage(page);

    mail->load(QUrl("https://zimbra.free.fr/"));
    mail->setZoomFactor(myScale.toInt());
    mail->setMinimumWidth(WIDTHMAIN);
    mail->setMinimumHeight(HEIGHT);
    FenE = new QWidget;
    myLayout = new QHBoxLayout(FenE);
    myLayout->addWidget(mail);
    menuE = new ControlMenuMail();
    menuE->setMaximumWidth(WIDTHCONTROL);
    menuE->setMaximumHeight(HEIGHT);
    myLayout->addWidget(menuE);
    FenE->showFullScreen();
    this->parentWidget()->close();
}

void ControlMenuMail::on_Bouygues_clicked() {
    ChoixServiceMail = QString::fromUtf8("6");
    SetValue.start("bash -c \"mkdir -p \"$HOME\"/.easymenu && echo \"" + ChoixServiceMail + "\" > \"$HOME\"/.easymenu/ServiceMail\"");
    SetValue.waitForFinished(-1);

    MyWebEnginePage *page = new MyWebEnginePage();
    mail->setPage(page);

    mail->load(QUrl("https://www.mon-compte.bouyguestelecom.fr/cas/login?service=https%3A%2F%2Foauth2.bouyguestelecom.fr%2Fcallback%2Fpicasso%2Fprotocol%2Fcas%3Fid%3Dar-33df094b-d8fb-4aca-afba-fb33f42ab763%26client_id%3Dwebmail.bouyguestelecom.fr"));
    mail->setZoomFactor(myScale.toInt());
    mail->setMinimumWidth(WIDTHMAIN);
    mail->setMinimumHeight(HEIGHT);
    FenE = new QWidget;
    myLayout = new QHBoxLayout(FenE);
    myLayout->addWidget(mail);
    menuE = new ControlMenuMail();
    menuE->setMaximumWidth(WIDTHCONTROL);
    menuE->setMaximumHeight(HEIGHT);
    myLayout->addWidget(menuE);
    FenE->showFullScreen();
    this->parentWidget()->close();
}

void ControlMenuMail::on_LaPoste_clicked() {
    ChoixServiceMail = QString::fromUtf8("7");
    SetValue.start("bash -c \"mkdir -p \"$HOME\"/.easymenu && echo \"" + ChoixServiceMail + "\" > \"$HOME\"/.easymenu/ServiceMail\"");
    SetValue.waitForFinished(-1);

    MyWebEnginePage *page = new MyWebEnginePage();
    mail->setPage(page);

    mail->load(QUrl("https://www.laposte.net/accueil"));
    mail->setZoomFactor(myScale.toInt());
    mail->setMinimumWidth(WIDTHMAIN);
    mail->setMinimumHeight(HEIGHT);
    FenE = new QWidget;
    myLayout = new QHBoxLayout(FenE);
    myLayout->addWidget(mail);
    menuE = new ControlMenuMail();
    menuE->setMaximumWidth(WIDTHCONTROL);
    menuE->setMaximumHeight(HEIGHT);
    myLayout->addWidget(menuE);
    FenE->showFullScreen();
    this->parentWidget()->close();
}

void ControlMenuMail::showTime()
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