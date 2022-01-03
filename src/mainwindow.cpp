#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controlmenucalc.h"
#include "ui_controlmenucalc.h"
#include "controlmenuoffice.h"
#include "ui_controlmenuoffice.h"
#include "controlmenumusic.h"
#include "ui_controlmenumusic.h"
#include "controlmenudiscord.h"
#include "ui_controlmenudiscord.h"
#include "controlmenumail.h"
#include "ui_controlmenumail.h"
#include "controlmenumain.h"
#include "ui_controlmenumain.h"
#include "controlmenuweb.h"
#include "ui_controlmenuweb.h"
#include "mywebenginepage.h"
#include <QDesktopWidget>
#include <string>
#include <QRect>
#include <QWindow>
#include <QDockWidget>
#include <QTreeWidget>
#include <map>
#include <QHBoxLayout>
#include <QGuiApplication>
#include <QWebEngineProfile>
#include <QWebChannel>
#include <QWebEngineUrlRequestInfo>
#include <QWebEnginePage>
#include <QWebEngineSettings>
#include <QtWebEngineWidgets>
#include <QObject>
#include <QPalette>
#include <QSettings>
#include <QTextToSpeech>
#include <QTextToSpeechEngine>
#include <QFileInfo>
#include <QEvent>
#include <QMouseEvent>
#include <QHoverEvent>
#include <iostream>

std::map<std::string, QString> QStringMap;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
/**#if _WIN32
    , m_speech(nullptr)
#endif**/
{

#ifdef __linux__
    QMainWindow::setWindowIcon(QIcon(":/Images/Heficience_Icone.svg"));
#elif _WIN32
    QMainWindow::setWindowIcon(QIcon(":/Images/Heficience_Icone.ico"));
#elif __APPLE__
    QMainWindow::setWindowIcon(QIcon(":/Images/Heficience_Icone.icns"));
#endif
    ui->setupUi(this);

/**#if defined(_WIN32) || defined(__APPLE__)
    m_speech = new QTextToSpeech(this);
    m_speech->setLocale(QLocale::French);
#elif __linux__
    m_speech = new QTextToSpeech("speechd", this);
    m_speech->setLocale(QLocale::French);
    QVector<QVoice> m_voices = m_speech->availableVoices();
    m_speech->setVoice(m_voices.at(1));
    m_speech->setVolume(0.05);
    //QProcess *newProcess = new QProcess();
    //newProcess->start("pulseaudio -k");
#endif**/

    screens = QGuiApplication::screens();
    screen = screens.first();
    screenGeometry = screen->geometry();
    HEIGHT = screenGeometry.height();
    WIDTH = screenGeometry.width();
    WIDTHCONTROL = int(WIDTH * 720 / 3840);
    WIDTHMAIN = WIDTH -WIDTHCONTROL;
    FenG = new QWidget;
    menuG = new ControlMenuMain();
    myWid = this->winId();
    ma_fenetreG = QWindow::fromWinId(myWid);
    FenApp = QWidget::createWindowContainer(ma_fenetreG);
    FenApp->setMinimumWidth(WIDTHMAIN);
    FenApp->setMinimumHeight(HEIGHT);
    myLayout = new QHBoxLayout(FenG);
    menuG->setMaximumWidth(WIDTHCONTROL);
    menuG->setMaximumHeight(HEIGHT);
    myLayout->addWidget(FenApp);
    myLayout->addWidget(menuG);
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    pal.setColor(QPalette::WindowText, Qt::white);
    FenG->setAutoFillBackground(true);
    FenG->setPalette(pal);
    FenG->setStyleSheet("background:#22577A; color:#fff");
    FenG->showFullScreen();

    fontC = ui->Calculatrice->font();
    fontE = ui->Email->font();
    fontI = ui->Internet->font();
    fontN = ui->Notes->font();
    fontD = ui->Discord->font();
    fontM = ui->Music->font();

    double dpi = QGuiApplication::primaryScreen()->physicalDotsPerInch();

    myScale = QString::number(int(2.5 * (dpi /159.856) * (WIDTH / 3840)));
    myScale2 = QString::number(int(4 * (dpi /159.856) * (WIDTH / 3840)));

    QS1 = QSize((int)(HEIGHT*.3),(int)(HEIGHT*.3));
    fSize1 = (int)((21*HEIGHT/2160)*72/dpi);
    QS2 = QSize((int)(HEIGHT*.05),(int)(HEIGHT*.05));
    fSize2 = (int)((120*HEIGHT/2160)*72/dpi);

    mySettings.beginGroup("ChoixMusic");
    int myInt = mySettings.value("Music").toInt();
    mySettings.endGroup();
    switch ( myInt )
    {
        case 1:
            musicText = "Ecouter de\nla musique\nsur YouTube";
            musicUrl = QUrl("https://www.youtube.com/?hl=fr&gl=FR&output=embed");
            music->load(musicUrl);
            serviceMusic = "Écouter de la musique grâce à YouTube";
            break;
        case 2:
            musicText = "Ecouter de\nla musique\nsur Deezer";
            musicUrl = QUrl("https://www.deezer.com/fr/");
            music->load(musicUrl);
            serviceMusic = "Écouter de la musique grâce à Deezer";
            break;
        case 3:
            musicText = "Ecouter de\nla musique\nsur \nSoundCloud";
            musicUrl = QUrl("https://soundcloud.com/discover");
            music->load(musicUrl);
            serviceMusic = "Écouter de la musique grâce à SoundCloud";
            break;
        default:
            musicText = "Ecouter de\nla musique\nsur Jamendo";
            musicUrl = QUrl("https://www.jamendo.com/start");
            music->load(musicUrl);
            serviceMusic = "Écouter de la musique grâce à Jamendo";
            break;
    }

    QString calculatriceText = "Calculatrice";
    QString emailText = "Gestion \ne-mail";
    QString internetText = "Accédez\nà internet";
    QString notesText = "Texte,\nCalcul ou \nPrésentation";
    QString discordText = "Nous\nrejoindre\nsur Discord";

    QStringMap["Calculatrice"] = calculatriceText;
    QStringMap["Email"] = emailText;
    QStringMap["Internet"] = internetText;
    QStringMap["Notes"] = notesText;
    QStringMap["Discord"] = discordText;
    QStringMap["Music"] = musicText;

    ui->Calculatrice->setIconSize(QS1);
    ui->Email->setIconSize(QS1);
    ui->Internet->setIconSize(QS1);
    ui->Notes->setIconSize(QS1);
    ui->Discord->setIconSize(QS1);
    ui->Music->setIconSize(QS1);
    fontC.setPointSize(fSize1);
    fontE.setPointSize(fSize1);
    fontI.setPointSize(fSize1);
    fontN.setPointSize(fSize1);
    fontD.setPointSize(fSize1);
    fontM.setPointSize(fSize1);
    ui->Calculatrice->setFont(fontC);
    ui->Email->setFont(fontE);
    ui->Internet->setFont(fontI);
    ui->Notes->setFont(fontN);
    ui->Discord->setFont(fontD);
    ui->Music->setFont(fontM);

    ui->Calculatrice->setMouseTracking(true);
    ui->Email->setMouseTracking(true);
    ui->Internet->setMouseTracking(true);
    ui->Notes->setMouseTracking(true);
    ui->Discord->setMouseTracking(true);
    ui->Music->setMouseTracking(true);

    ui->Calculatrice->setAttribute(Qt::WA_Hover);
    ui->Email->setAttribute(Qt::WA_Hover);
    ui->Internet->setAttribute(Qt::WA_Hover);
    ui->Notes->setAttribute(Qt::WA_Hover);
    ui->Discord->setAttribute(Qt::WA_Hover);
    ui->Music->setAttribute(Qt::WA_Hover);

    FenApp->setMouseTracking(true);
    FenApp->setAttribute(Qt::WA_Hover);

    ui->Calculatrice->installEventFilter(this);
    ui->Email->installEventFilter(this);
    ui->Internet->installEventFilter(this);
    ui->Notes->installEventFilter(this);
    ui->Discord->installEventFilter(this);
    ui->Music->installEventFilter(this);

    profileC = KCalculatrice->page()->profile();
    profileC->setHttpUserAgent("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.169 Safari/537.36");
    profileC->setPersistentCookiesPolicy(QWebEngineProfile::ForcePersistentCookies);
    profileC->setCachePath(".heficience/cache");
    profileC->setPersistentStoragePath(".heficience/persistentstorage");

    profileE = mail->page()->profile();
    profileE->setHttpUserAgent("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.169 Safari/537.36");
    profileE->setPersistentCookiesPolicy(QWebEngineProfile::ForcePersistentCookies);
    profileE->setCachePath(".heficience/cache");
    profileE->setPersistentStoragePath(".heficience/persistentstorage");

    profileI = web->page()->profile();
    profileI->setHttpUserAgent("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.169 Safari/537.36");
    profileI->setPersistentCookiesPolicy(QWebEngineProfile::ForcePersistentCookies);
    profileI->setCachePath(".heficience/cache");
    profileI->setPersistentStoragePath(".heficience/persistentstorage");

    profileN = office->page()->profile();
    profileN->setHttpUserAgent("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.169 Safari/537.36");
    profileN->setPersistentCookiesPolicy(QWebEngineProfile::ForcePersistentCookies);
    profileN->setCachePath(".heficience/cache");
    profileN->setPersistentStoragePath(".heficience/persistentstorage");

    profileD = DiscordLauncher->page()->profile();
    profileD->setHttpUserAgent("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.169 Safari/537.36");
    profileD->setPersistentCookiesPolicy(QWebEngineProfile::ForcePersistentCookies);
    profileD->setCachePath(".heficience/cache");
    profileD->setPersistentStoragePath(".heficience/persistentstorage");

    profileM = music->page()->profile();
    profileM->setHttpUserAgent("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.169 Safari/537.36");
    profileM->setPersistentCookiesPolicy(QWebEngineProfile::ForcePersistentCookies);
    profileM->setCachePath(".heficience/cache");
    profileM->setPersistentStoragePath(".heficience/persistentstorage");

    myWid = this->winId();

    ui->Calculatrice->setObjectName("Calculatrice");
    ui->Email->setObjectName("Email");
    ui->Internet->setObjectName("Internet");
    ui->Notes->setObjectName("Notes");
    ui->Discord->setObjectName("Discord");
    ui->Music->setObjectName("Music");

    ui->Calculatrice->setText("");
    ui->Email->setText("");
    ui->Internet->setText("");
    ui->Notes->setText("");
    ui->Discord->setText("");
    ui->Music->setText("");


#ifdef __APPLE__
    ui->Calculatrice->setAutoRaise(true);
    ui->Email->setAutoRaise(true);
    ui->Internet->setAutoRaise(true);
    ui->Notes->setAutoRaise(true);
    ui->Discord->setAutoRaise(true);
    ui->Music->setAutoRaise(true);

    ui->Calculatrice->raise();
    ui->Email->raise();
    ui->Internet->raise();
    ui->Notes->raise();
    ui->Discord->raise();
    ui->Music->raise();

    FenApp->raise();
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() != QEvent::WindowDeactivate) {

        QPropertyAnimation *animationIcon = new QPropertyAnimation(ui->Calculatrice, "iconSize");

        if (watched == ui->Calculatrice && (event->type() == QEvent::HoverEnter || event->type() == QEvent::MouseMove)) {

            ui->Calculatrice->setText(QStringMap.at("Calculatrice"));
            ui->Calculatrice->setIcon(QIcon(":/Images/0-Categorie/calculator-color.svg"));
            ui->Calculatrice->setStyleSheet("QToolButton#Calculatrice:hover {background-color: rgb(0, 0, 0);border-radius: 10px;border:  16PX solid rgb(41, 182, 71);color : white;}");

            if (play) {
                play = false;
                //m_speech->say("Ouvrir la calculatrice.");

                animationIcon->setDuration(250);
                animationIcon->setStartValue(QS1);
                animationIcon->setEndValue(QS2);
                animationIcon->start();
            }

            fontC.setPointSize(fSize2);
            ui->Calculatrice->setFont(fontC);
        }
        if (watched == ui->Calculatrice && (event->type() == QEvent::HoverLeave || event->type() == QEvent::Hide)) {
            ui->Calculatrice->setText("");
            ui->Calculatrice->setIcon(QIcon(":/Images/0-Categorie/calculator.svg"));
            ui->Calculatrice->setStyleSheet("QToolButton#Calculatrice {background-color: rgb(41, 182, 71);border-radius: 10px;border:  8PX solid red;color : white;}");

            play = true;
            //m_speech->stop();

            animationIcon->setDuration(250);
            animationIcon->setStartValue(QS2);
            animationIcon->setEndValue(QS1);
            animationIcon->start();

            fontC.setPointSize(fSize1);
            ui->Calculatrice->setFont(fontC);
        }
    }
    if (event->type() != QEvent::WindowDeactivate) {

        QPropertyAnimation *animationIcon = new QPropertyAnimation(ui->Email, "iconSize");

        if (watched == ui->Email && (event->type() == QEvent::HoverEnter || event->type() == QEvent::MouseMove)) {
            ui->Email->setText(QStringMap.at("Email"));
            ui->Email->setIcon(QIcon(":/Images/0-Categorie/envelope-color.svg"));
            ui->Email->setStyleSheet("QToolButton#Email:hover {background-color: rgb(0, 0, 0);border-radius: 10px;border:  16PX solid rgb(240, 120, 80);color : white;}");

            if (play) {
                play = false;
                //m_speech->say("Ouvrir le client email.");

                animationIcon->setDuration(250);
                animationIcon->setStartValue(QS1);
                animationIcon->setEndValue(QS2);
                animationIcon->start();
            }

            fontE.setPointSize(fSize2);
            ui->Email->setFont(fontE);
        }
        if (watched == ui->Email && (event->type() == QEvent::HoverLeave || event->type() == QEvent::Hide)) {
            ui->Email->setText("");
            ui->Email->setIcon(QIcon(":/Images/0-Categorie/envelope.svg"));
            ui->Email->setStyleSheet("QToolButton#Email {background-color: rgb(240, 120, 80);border-radius: 10px;border:  8PX solid red;color : white;}");

            play = true;
            //m_speech->stop();

            animationIcon->setDuration(250);
            animationIcon->setStartValue(QS2);
            animationIcon->setEndValue(QS1);
            animationIcon->start();

            fontE.setPointSize(fSize1);
            ui->Email->setFont(fontE);
        }
    }
    if (event->type() != QEvent::WindowDeactivate) {

        QPropertyAnimation *animationIcon = new QPropertyAnimation(ui->Internet, "iconSize");

        if (watched == ui->Internet && (event->type() == QEvent::HoverEnter || event->type() == QEvent::MouseMove)) {
            ui->Internet->setText(QStringMap.at("Internet"));
            ui->Internet->setIcon(QIcon(":/Images/0-Categorie/globe-africa-color.svg"));
            ui->Internet->setStyleSheet("QToolButton#Internet:hover {background-color: rgb(0, 0, 0);border-radius: 10px;border:  16PX solid rgb(88, 70, 55);color : white}");

            if (play) {
                play = false;
                //m_speech->say("Ouvrir le navigateur internet.");

                animationIcon->setDuration(250);
                animationIcon->setStartValue(QS1);
                animationIcon->setEndValue(QS2);
                animationIcon->start();
            }

            fontI.setPointSize(fSize2);
            ui->Internet->setFont(fontI);
        }
        if (watched == ui->Internet && (event->type() == QEvent::HoverLeave || event->type() == QEvent::Hide)) {

            QPropertyAnimation *animationIcon = new QPropertyAnimation(ui->Internet, "iconSize");

            ui->Internet->setText("");
            ui->Internet->setIcon(QIcon(":/Images/0-Categorie/globe-africa.svg"));
            ui->Internet->setStyleSheet("QToolButton#Internet {background-color: rgb(88, 70, 55);border-radius: 10px;border:  8PX solid red;color : white;}");

            play = true;
            //m_speech->stop();

            animationIcon->setDuration(250);
            animationIcon->setStartValue(QS2);
            animationIcon->setEndValue(QS1);
            animationIcon->start();

            fontI.setPointSize(fSize1);
            ui->Internet->setFont(fontI);
        }
    }
    if (event->type() != QEvent::WindowDeactivate) {

        QPropertyAnimation *animationIcon = new QPropertyAnimation(ui->Notes, "iconSize");

        if (watched == ui->Notes && (event->type() == QEvent::HoverEnter || event->type() == QEvent::MouseMove)) {
            ui->Notes->setText(QStringMap.at("Notes"));
            ui->Notes->setIcon(QIcon(":/Images/0-Categorie/All_docs-color.svg"));
            ui->Notes->setStyleSheet("QToolButton#Notes:hover {background-color: rgb(0, 0, 0);border-radius: 10px;border:  16PX solid #38A3A5;color : white;}");

            if (play) {
                play = false;
                //m_speech->say("Ouvrir la suite bureautique.");

                animationIcon->setDuration(250);
                animationIcon->setStartValue(QS1);
                animationIcon->setEndValue(QS2);
                animationIcon->start();
            }

            fontN.setPointSize(fSize2);
            ui->Notes->setFont(fontN);
        }
        if (watched == ui->Notes && (event->type() == QEvent::HoverLeave || event->type() == QEvent::Hide)) {
            ui->Notes->setText("");
            ui->Notes->setIcon(QIcon(":/Images/0-Categorie/All_docs.svg"));
            ui->Notes->setStyleSheet("QToolButton#Notes {background-color: #38A3A5;border-radius: 10px;border:  8PX solid red;color : white;}");

            play = true;
            //m_speech->stop();

            animationIcon->setDuration(250);
            animationIcon->setStartValue(QS2);
            animationIcon->setEndValue(QS1);
            animationIcon->start();

            fontN.setPointSize(fSize1);
            ui->Notes->setFont(fontN);
        }
    }
    if (event->type() != QEvent::WindowDeactivate) {

        QPropertyAnimation *animationIcon = new QPropertyAnimation(ui->Discord, "iconSize");

        if (watched == ui->Discord && (event->type() == QEvent::HoverEnter || event->type() == QEvent::MouseMove)) {
            ui->Discord->setText(QStringMap.at("Discord"));
            ui->Discord->setIcon(QIcon(":/Images/0-Categorie/discord-color.svg"));
            ui->Discord->setStyleSheet("QToolButton#Discord:hover {background-color: rgb(0, 0, 0);border-radius: 10px;border:  16PX solid rgb(114, 137, 218);color : white;}");

            if (play) {
                play = false;
                //m_speech->say("Discuter grâce à discord.");

                animationIcon->setDuration(250);
                animationIcon->setStartValue(QS1);
                animationIcon->setEndValue(QS2);
                animationIcon->start();
            }

            fontD.setPointSize(fSize2);
            ui->Discord->setFont(fontD);
        }
        if (watched == ui->Discord && (event->type() == QEvent::HoverLeave || event->type() == QEvent::Hide)) {
            ui->Discord->setText("");
            ui->Discord->setIcon(QIcon(":/Images/0-Categorie/discord.svg"));
            ui->Discord->setStyleSheet("QToolButton#Discord {background-color: rgb(114, 137, 218);border-radius: 10px;border:  8PX solid red;color : white;}");

            play = true;
            //m_speech->stop();

            animationIcon->setDuration(250);
            animationIcon->setStartValue(QS2);
            animationIcon->setEndValue(QS1);
            animationIcon->start();

            fontD.setPointSize(fSize1);
            ui->Discord->setFont(fontD);
        }
    }
    if (event->type() != QEvent::WindowDeactivate) {

        QPropertyAnimation *animationIcon = new QPropertyAnimation(ui->Music, "iconSize");

        if (watched == ui->Music && (event->type() == QEvent::HoverEnter || event->type() == QEvent::MouseMove)) {
            ui->Music->setText(QStringMap.at("Music"));
            ui->Music->setIcon(QIcon(":/Images/0-Categorie/music-color.svg"));
            ui->Music->setStyleSheet("QToolButton#Music:hover {background-color: rgb(0, 0, 0);border-radius: 10px;border:  16PX solid rgb(212, 115, 212);color : white;}");

            if (play) {
                play = false;
                //m_speech->say(serviceMusic);

                animationIcon->setDuration(250);
                animationIcon->setStartValue(QS1);
                animationIcon->setEndValue(QS2);
                animationIcon->start();
            }

            fontM.setPointSize(fSize2);
            ui->Music->setFont(fontM);
        }
        if (watched == ui->Music && (event->type() == QEvent::HoverLeave || event->type() == QEvent::Hide)) {
            ui->Music->setText("");
            ui->Music->setIcon(QIcon(":/Images/0-Categorie/music.svg"));
            ui->Music->setStyleSheet("QToolButton#Music {background-color: rgb(212, 115, 212);border-radius: 10px;border:  8PX solid red;color : white;}");

            play = true;
            //m_speech->stop();

            animationIcon->setDuration(250);
            animationIcon->setStartValue(QS2);
            animationIcon->setEndValue(QS1);
            animationIcon->start();

            fontM.setPointSize(fSize1);
            ui->Music->setFont(fontM);
        }
    }

    return false;
}

void MainWindow::handleStateChanged(QProcess *procss, QWidget *widget, QWidget *testkill)
{
    if (procss->state() == QProcess::NotRunning)
    {
        widget->close();
        qApp->closeAllWindows();
        testkill->close();
    }
}

void MainWindow::on_Calculatrice_clicked()
{
    if (KCalculatrice->isVisible()) {
        FenC->showFullScreen();
    } else {
//#if defined(__linux__) || defined(__APPLE__)
        UrlIci = QUrl("http://paulluxwaffle.synology.me/Calculator/");
/**#elif _WIN32
        UrlIci = QUrl::fromLocalFile(QFileInfo("../Calculator/index.html").absoluteFilePath());
#endif**/
        mySettings.beginGroup("UrlIci");
        mySettings.setValue("UrlIci", UrlIci);
        mySettings.endGroup();
        KCalculatrice->load(UrlIci);
        KCalculatrice->setZoomFactor(2 * myScale.toInt());
        KCalculatrice->setMinimumWidth(WIDTHMAIN);
        KCalculatrice->setMinimumHeight(HEIGHT);
        FenC = new QWidget;
        myLayout = new QHBoxLayout(FenC);
        myLayout->addWidget(KCalculatrice);
        menuC = new ControlMenuCalc();
        menuC->setMaximumWidth(WIDTHCONTROL);
        menuC->setMaximumHeight(HEIGHT);
        myLayout->addWidget(menuC);
        QPalette pal = palette();
        pal.setColor(QPalette::Window, Qt::black);
        pal.setColor(QPalette::WindowText, Qt::white);
        FenC->setAutoFillBackground(true);
        FenC->setPalette(pal);
        FenC->setStyleSheet("background:#22577A; color:#fff");
        FenC->showFullScreen();
#ifdef __APPLE__
        this->close();
#endif
    }
}

void MainWindow::on_Email_clicked()
{
    mySettings.beginGroup("ChoixMail");
    ServiceMail = mySettings.value("Mail").toInt();
    mySettings.endGroup();
    QUrl urlici;
    switch ( ServiceMail )
    {
        case 1:
            urlici = QUrl("https://outlook.live.com/mail/0/inbox");
            break;
        case 2:
            urlici = QUrl("https://login.yahoo.com/?.src=ym&lang=fr-FR&done=https%3A%2F%2Ffr.mail.yahoo.com");
            break;
        case 3:
            urlici = QUrl("https://login.orange.fr/?return_url=https://rms.orange.fr/mail/inbox%3F");
            break;
        case 4:
            urlici = QUrl("https://www.sfr.fr/cas/login?service=https%3A%2F%2Fwebmail.sfr.fr%2Fwebmail%2Fj_spring_cas_security_check");
            break;
        case 5:
            urlici = QUrl("https://zimbra.free.fr/");
            break;
        case 6:
            urlici = QUrl("https://www.mon-compte.bouyguestelecom.fr/cas/login?service=https%3A%2F%2Foauth2.bouyguestelecom.fr%2Fcallback%2Fpicasso%2Fprotocol%2Fcas%3Fid%3Dar-33df094b-d8fb-4aca-afba-fb33f42ab763%26client_id%3Dwebmail.bouyguestelecom.fr");
            break;
        case 7:
            urlici = QUrl("https://www.laposte.net/accueil");
            break;
        default:
            urlici = QUrl("https://mail.google.com/");
    }
    mail->load(urlici);
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
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    pal.setColor(QPalette::WindowText, Qt::white);
    FenE->setAutoFillBackground(true);
    FenE->setPalette(pal);
    FenE->setStyleSheet("background:#22577A; color:#fff");
    FenE->showFullScreen();
 }
void MainWindow::on_Notes_clicked()
{
    if (office->isVisible()) {
        FenN->showFullScreen();
    } else {
        office->setPage(new MyWebEnginePage);
        //UrlIci = QUrl("https://personal.onlyoffice.com/Products/Files/");
        UrlIci = QUrl("https://docs.google.com/document/u/0/");
        mySettings.beginGroup("UrlIci");
        mySettings.setValue("UrlIci", UrlIci);
        mySettings.endGroup();
        office->load(UrlIci);
        office->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
        office->settings()->setAttribute(QWebEngineSettings::JavascriptCanOpenWindows, true);
        office->setZoomFactor(myScale.toInt());
        office->setMinimumWidth(WIDTHMAIN);
        office->setMinimumHeight(HEIGHT);
        FenN = new QWidget;
        myLayout = new QHBoxLayout(FenN);
        myLayout->addWidget(office);
        menuN = new ControlMenuOffice();
        menuN->setMaximumWidth(WIDTHCONTROL);
        menuN->setMaximumHeight(HEIGHT);
        myLayout->addWidget(menuN);
        QPalette pal = palette();
        pal.setColor(QPalette::Window, Qt::black);
        pal.setColor(QPalette::WindowText, Qt::white);
        FenN->setAutoFillBackground(true);
        FenN->setPalette(pal);
        FenN->setStyleSheet("background:#22577A; color:#fff");
        FenN->showFullScreen();
#ifdef __APPLE__
        this->close();
#endif
    }
}

void MainWindow::on_Internet_clicked()
{
    if (web->isVisible()) {
        FenI->showFullScreen();
    } else {
        UrlIci = QUrl("https://heficience.search.paulluxwaffle.synology.me/search.php");
        web->setPage(new MyWebEnginePage);
        web->load(UrlIci);
        web->setZoomFactor(myScale.toInt());
        web->setMinimumWidth(WIDTHMAIN);
        web->setMinimumHeight(HEIGHT);
        FenI = new QWidget;
        myLayout = new QHBoxLayout(FenI);
        myLayout->addWidget(web);
        menuI = new ControlMenuWeb();
        menuI->setMaximumWidth(WIDTHCONTROL);
        menuI->setMaximumHeight(HEIGHT);
        myLayout->addWidget(menuI);
        QPalette pal = palette();
        pal.setColor(QPalette::Window, Qt::black);
        pal.setColor(QPalette::WindowText, Qt::white);
        FenI->setAutoFillBackground(true);
        FenI->setPalette(pal);
        FenI->setStyleSheet("background:#22577A; color:#fff");
        FenI->showFullScreen();
#ifdef __APPLE__
        this->close();
#endif
}
}

void MainWindow::on_Music_clicked()
{
    if (music->isVisible()) {
        FenM->showFullScreen();
    } else {
        UrlIci = musicUrl;
        mySettings.beginGroup("UrlIci");
        mySettings.setValue("UrlIci", UrlIci);
        mySettings.endGroup();
        music->setZoomFactor(myScale.toInt());
        music->setMinimumWidth(WIDTHMAIN);
        music->setMinimumHeight(HEIGHT);
        FenM = new QWidget;
        myLayout = new QHBoxLayout(FenM);
        myLayout->addWidget(music);
        menuM = new ControlMenuMusic();
        menuM->setMaximumWidth(WIDTHCONTROL);
        menuM->setMaximumHeight(HEIGHT);
        myLayout->addWidget(menuM);
        QPalette pal = palette();
        pal.setColor(QPalette::Window, Qt::black);
        pal.setColor(QPalette::WindowText, Qt::white);
        FenM->setAutoFillBackground(true);
        FenM->setPalette(pal);
        FenM->setStyleSheet("background-color:#22577A; color:#fff");
        FenM->showFullScreen();
#ifdef __APPLE__
        this->close();
#endif
    }
}

void MainWindow::on_Discord_clicked()
{
    profileD = DiscordLauncher->page()->profile();
    if (DiscordLauncher->isVisible()) {
        FenD->showFullScreen();
    } else {
        DiscordLauncher->setPage(new MyWebEnginePage);
        DiscordLauncher->setUrl(QUrl("https://discord.com/channels/@me"));
        DiscordLauncher->setZoomFactor(myScale.toInt());
        DiscordLauncher->setMinimumWidth(WIDTHMAIN);
        DiscordLauncher->setMinimumHeight(HEIGHT);
        FenD = new QWidget;
        myLayout = new QHBoxLayout(FenD);
        myLayout->addWidget(DiscordLauncher);
        menuD = new ControlMenuDiscord();
        menuD->setMaximumWidth(WIDTHCONTROL);
        menuD->setMaximumHeight(HEIGHT);
        myLayout->addWidget(menuD);
        QPalette pal = palette();
        pal.setColor(QPalette::Window, Qt::black);
        pal.setColor(QPalette::WindowText, Qt::white);
        FenD->setAutoFillBackground(true);
        FenD->setPalette(pal);
        FenD->setStyleSheet("background-color:#22577A; color:#fff");
        FenD->showFullScreen();
#ifdef __APPLE__
        this->close();
#endif
    }
}
