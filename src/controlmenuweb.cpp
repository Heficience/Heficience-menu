#include "controlmenuweb.h"
#include "ui_controlmenuweb.h"
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
#include <QList>
#include <iostream>
#include <vector>

ControlMenuWeb::ControlMenuWeb(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlMenuWeb)
{
    ui->setupUi(this);

    screens = QGuiApplication::screens();
    screen = screens.first();
    screenGeometry = screen->geometry();
    HEIGHT = screenGeometry.height();
    WIDTH = screenGeometry.width();
    double dpi = QGuiApplication::primaryScreen()->physicalDotsPerInch();
    fSize2 = (int)((80*HEIGHT/2160)*72/dpi);

    myScale = QString::number(int(2.5 * (dpi /159.856) * (WIDTH / 3840)));

    int sizeButton = 80 * HEIGHT / 1080;
    fSize3 = (int)((sizeButton*HEIGHT/(2160*4))*72/dpi);

    ui->Fermeture->setMaximumWidth(sizeButton);
    ui->Fermeture->setMaximumHeight(sizeButton);
    ui->Fermeture->setIconSize(QSize(sizeButton, sizeButton));
    ui->Fermeture->setStyleSheet("background-color: grey;");

    ui->Home->setMaximumWidth(sizeButton);
    ui->Home->setMaximumHeight(sizeButton);
    ui->Home->setIconSize(QSize(sizeButton, sizeButton));

    ui->Home_App->setMaximumWidth(sizeButton);
    ui->Home_App->setMaximumHeight(sizeButton);
    ui->Home_App->setIconSize(QSize(sizeButton, sizeButton));

    ui->Retour->setMaximumWidth(sizeButton);
    ui->Retour->setMaximumHeight(sizeButton);
    ui->Retour->setIconSize(QSize(sizeButton, sizeButton));

/**    ui->Options->setMaximumWidth(sizeButton);
    ui->Options->setMaximumHeight(sizeButton);
    ui->Options->setIconSize(QSize(sizeButton, sizeButton));
**/
    ui->Favoris->setMaximumWidth(sizeButton);
    ui->Favoris->setMaximumHeight(sizeButton);
    ui->Favoris->setIconSize(QSize(sizeButton, sizeButton));
    ui->Favoris->setIcon(QIcon(":/Images/1-NavigateurWeb/star-clear.svg"));

    ui->Lien1QTB->setMaximumHeight(sizeButton/2.5);
    ui->Lien2QTB->setMaximumHeight(sizeButton/2.5);
    ui->Lien3QTB->setMaximumHeight(sizeButton/2.5);
    ui->Lien4QTB->setMaximumHeight(sizeButton/2.5);
    ui->Lien5QTB->setMaximumHeight(sizeButton/2.5);
    ui->Lien6QTB->setMaximumHeight(sizeButton/2.5);
    ui->Lien7QTB->setMaximumHeight(sizeButton/2.5);
    ui->Lien8QTB->setMaximumHeight(sizeButton/2.5);
    ui->Lien9QTB->setMaximumHeight(sizeButton/2.5);

    ui->Lien1QTB->setIconSize(QSize(sizeButton/2.5, sizeButton/2.5));
    ui->Lien2QTB->setIconSize(QSize(sizeButton/2.5, sizeButton/2.5));
    ui->Lien3QTB->setIconSize(QSize(sizeButton/2.5, sizeButton/2.5));
    ui->Lien4QTB->setIconSize(QSize(sizeButton/2.5, sizeButton/2.5));
    ui->Lien5QTB->setIconSize(QSize(sizeButton/2.5, sizeButton/2.5));
    ui->Lien6QTB->setIconSize(QSize(sizeButton/2.5, sizeButton/2.5));
    ui->Lien7QTB->setIconSize(QSize(sizeButton/2.5, sizeButton/2.5));
    ui->Lien8QTB->setIconSize(QSize(sizeButton/2.5, sizeButton/2.5));
    ui->Lien9QTB->setIconSize(QSize(sizeButton/2.5, sizeButton/2.5));

    ui->Lien1QL->setMinimumHeight(sizeButton/2);
    ui->Lien2QL->setMinimumHeight(sizeButton/2);
    ui->Lien3QL->setMinimumHeight(sizeButton/2);
    ui->Lien4QL->setMinimumHeight(sizeButton/2);
    ui->Lien5QL->setMinimumHeight(sizeButton/2);
    ui->Lien6QL->setMinimumHeight(sizeButton/2);
    ui->Lien7QL->setMinimumHeight(sizeButton/2);
    ui->Lien8QL->setMinimumHeight(sizeButton/2);
    ui->Lien9QL->setMinimumHeight(sizeButton/2);

    ui->Lien1QL->setStyleSheet("left: 1px; text-align: left;");
    ui->Lien2QL->setStyleSheet("left: 1px; text-align: left;");
    ui->Lien3QL->setStyleSheet("left: 1px; text-align: left;");
    ui->Lien4QL->setStyleSheet("left: 1px; text-align: left;");
    ui->Lien5QL->setStyleSheet("left: 1px; text-align: left;");
    ui->Lien6QL->setStyleSheet("left: 1px; text-align: left;");
    ui->Lien7QL->setStyleSheet("left: 1px; text-align: left;");
    ui->Lien8QL->setStyleSheet("left: 1px; text-align: left;");
    ui->Lien9QL->setStyleSheet("left: 1px; text-align: left;");

    QFont fontFav;
    fontFav.setPointSize(fSize3*4/2.5);
#ifdef __APPLE__
    fontFav.setPointSize(fSize3*8/2.5);
#endif
    fontFav.setBold(true);
    ui->Lien1QL->setFont(fontFav);
    ui->Lien2QL->setFont(fontFav);
    ui->Lien3QL->setFont(fontFav);
    ui->Lien4QL->setFont(fontFav);
    ui->Lien5QL->setFont(fontFav);
    ui->Lien6QL->setFont(fontFav);
    ui->Lien7QL->setFont(fontFav);
    ui->Lien8QL->setFont(fontFav);
    ui->Lien9QL->setFont(fontFav);

    ui->horizontalSpacer_2->changeSize(sizeButton,sizeButton);
    ui->horizontalSpacer_6->changeSize(sizeButton/2,sizeButton/2);

    int Size = (int)((1920 * 1920 * dpi) / WIDTH);

    ui->Horlorge->setMinimumWidth(sizeButton*1.5);
    ui->Horlorge->setMaximumWidth(Size);

    ui->gridLayout->setColumnMinimumWidth(1,Size);

    WIDTHCONTROL = int(WIDTH * 720 / 3840 -50);

    ui->gridWidget->resize(WIDTHCONTROL, HEIGHT - 50);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ControlMenuWeb::showTime);
    timer->start(1000);

    showTime();

    QTimer *timerFav = new QTimer(this);
    connect(timerFav, &QTimer::timeout, this, &ControlMenuWeb::ifFav);
    timerFav->start(15000); //time specified in ms

    mySettings.beginGroup("FavorisWeb");
    for (int i = 0; i < 8; i++) {
        if (mySettings.value("FavorisWebTitre" + QString::number(i)) != "") {
            QUrl urlici = mySettings.value("FavorisWebLien" + QString::number(i)).toUrl();
            QString titleici = mySettings.value("FavorisWebTitre" + QString::number(i)).toString();
            myFavoris.append({urlici, titleici});
        }
    }
    mySettings.endGroup();

    reorganiseFav();
}

ControlMenuWeb::~ControlMenuWeb()
{
    delete ui;
}

void ControlMenuWeb::on_Fermeture_clicked()
{
}
void ControlMenuWeb::on_Home_clicked() {
#if defined(_WIN32) || defined(__APPLE__)
    qApp->closeAllWindows();
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    this->close();
#endif
    this->parentWidget()->close();
}
void ControlMenuWeb::on_Home_App_clicked() {
    return_To_Home();
}
void ControlMenuWeb::return_To_Home() {
    ui->Favoris->setIcon(QIcon(":/Images/1-NavigateurWeb/star-clear.svg"));
    QList<QWebEngineView *> webViews = parentWidget()->findChildren<QWebEngineView *>();
    QList<QWebEngineView *>::iterator it = std::find_if(webViews.begin(), webViews.end(),
                                                        [](QWebEngineView *webView) -> bool {
                                                            return QLatin1String(webView->metaObject()->className()) ==
                                                                   "QWebEngineView";
                                                        });
    if (it != webViews.end()) {
        QWebEngineView *mywebview = webViews.at(std::distance(webViews.begin(), it));
        mywebview->setUrl(QUrl("https://heficience.search.paulluxwaffle.synology.me/search.php"));
        QObject::connect(mywebview, &QWebEngineView::loadFinished,
                         [=](bool arg) {
                             mywebview->setZoomFactor(myScale.toInt());
                         });
    }
}
/**void ControlMenuWeb::on_Options_clicked() {
    Options *myOptions = new Options();
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    pal.setColor(QPalette::WindowText, Qt::white);
    myOptions->setAutoFillBackground(true);
    myOptions->setPalette(pal);
    myOptions->setStyleSheet("background-color:black; color:#fff");
    myOptions->show();
}**/

void ControlMenuWeb::on_Favoris_clicked() {
    QList<QWebEngineView *> webViews = parentWidget()->findChildren<QWebEngineView *>();
    QList<QWebEngineView *>::iterator it = std::find_if(webViews.begin(), webViews.end(),
                                                        [](QWebEngineView *webView) -> bool {
                                                            return QLatin1String(webView->metaObject()->className()) ==
                                                                   "QWebEngineView";
                                                        });
    if (it != webViews.end()) {
        QWebEngineView *mywebview = webViews.at(std::distance(webViews.begin(), it));
        QUrl Url = mywebview->url();
        QString Titre = mywebview->title();
        if (myFavoris.length() <10) {
            myFavoris.append({Url, Titre});
        }
    }
    ui->Favoris->setIcon(QIcon(":/Images/1-NavigateurWeb/star.svg"));
    reorganiseFav();
}

void ControlMenuWeb::on_Retour_clicked() {
    QList<QWebEngineView *> webViews = parentWidget()->findChildren<QWebEngineView *>();
    QList<QWebEngineView *>::iterator it = std::find_if(webViews.begin(), webViews.end(),
                                                        [](QWebEngineView *webView) -> bool {
                                                            return QLatin1String(webView->metaObject()->className()) ==
                                                                   "QWebEngineView";
                                                        });
    if (it != webViews.end()) {
        webViews.at(std::distance(webViews.begin(), it))->page()->runJavaScript("window.history.back();");
    }
}

void ControlMenuWeb::ifFav()
{
    reorganiseFav();
}

void ControlMenuWeb::showTime()
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

void ControlMenuWeb::on_Lien1QTB_clicked() {
    if (ui->Lien1QL->text() != "(vide)") {
        myFavoris.remove(0);
        if (myFavoris.length() == 0) {
            ui->Lien1QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(0), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(0), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 1) {
            ui->Lien2QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(1), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(1), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 2) {
            ui->Lien3QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(2), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(2), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 3) {
            ui->Lien4QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(3), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(3), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 4) {
            ui->Lien5QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(4), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(4), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 5) {
            ui->Lien6QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(5), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(5), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 6) {
            ui->Lien7QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(6), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(6), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 7) {
            ui->Lien8QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(7), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(7), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 8) {
            ui->Lien9QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(8), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(8), "");
            mySettings.endGroup();
        }
    }
    reorganiseFav();
}

void ControlMenuWeb::on_Lien2QTB_clicked() {
    if (ui->Lien2QL->text() != "(vide)") {
        myFavoris.remove(1);
        if (myFavoris.length() == 1) {
            ui->Lien2QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(1), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(1), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 2) {
            ui->Lien3QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(2), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(2), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 3) {
            ui->Lien4QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(3), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(3), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 4) {
            ui->Lien5QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(4), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(4), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 5) {
            ui->Lien6QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(5), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(5), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 6) {
            ui->Lien7QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(6), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(6), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 7) {
            ui->Lien8QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(7), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(7), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 8) {
            ui->Lien9QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(8), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(8), "");
            mySettings.endGroup();
        }
    }
    reorganiseFav();
}

void ControlMenuWeb::on_Lien3QTB_clicked() {
    if (ui->Lien3QL->text() != "(vide)") {
        myFavoris.remove(2);
        if (myFavoris.length() == 2) {
            ui->Lien3QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(2), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(2), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 3) {
            ui->Lien4QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(3), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(3), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 4) {
            ui->Lien5QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(4), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(4), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 5) {
            ui->Lien6QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(5), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(5), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 6) {
            ui->Lien7QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(6), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(6), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 7) {
            ui->Lien8QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(7), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(7), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 8) {
            ui->Lien9QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(8), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(8), "");
            mySettings.endGroup();
        }
    }
    reorganiseFav();
}

void ControlMenuWeb::on_Lien4QTB_clicked() {
    if (ui->Lien4QL->text() != "(vide)") {
        myFavoris.remove(3);
        if (myFavoris.length() == 3) {
            ui->Lien4QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(3), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(3), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 4) {
            ui->Lien5QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(4), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(4), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 5) {
            ui->Lien6QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(5), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(5), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 6) {
            ui->Lien7QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(6), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(6), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 7) {
            ui->Lien8QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(7), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(7), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 8) {
            ui->Lien9QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(8), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(8), "");
            mySettings.endGroup();
        }
    }
    reorganiseFav();
}

void ControlMenuWeb::on_Lien5QTB_clicked() {
    if (ui->Lien5QL->text() != "(vide)") {
        myFavoris.remove(4);
        if (myFavoris.length() == 4) {
            ui->Lien5QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(4), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(4), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 5) {
            ui->Lien6QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(5), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(5), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 6) {
            ui->Lien7QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(6), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(6), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 7) {
            ui->Lien8QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(7), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(7), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 8) {
            ui->Lien9QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(8), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(8), "");
            mySettings.endGroup();
        }
    }
    reorganiseFav();
}

void ControlMenuWeb::on_Lien6QTB_clicked() {
    if (ui->Lien6QL->text() != "(vide)") {
        myFavoris.remove(5);
        if (myFavoris.length() == 5) {
            ui->Lien6QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(5), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(5), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 6) {
            ui->Lien7QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(6), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(6), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 7) {
            ui->Lien8QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(7), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(7), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 8) {
            ui->Lien9QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(8), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(8), "");
            mySettings.endGroup();
        }
    }
    reorganiseFav();
}

void ControlMenuWeb::on_Lien7QTB_clicked() {
    if (ui->Lien7QL->text() != "(vide)") {
        myFavoris.remove(6);
        if (myFavoris.length() == 6) {
            ui->Lien7QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(6), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(6), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 7) {
            ui->Lien8QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(7), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(7), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 8) {
            ui->Lien9QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(8), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(8), "");
            mySettings.endGroup();
        }
    }
    reorganiseFav();
}

void ControlMenuWeb::on_Lien8QTB_clicked() {
    if (ui->Lien8QL->text() != "(vide)") {
        myFavoris.remove(7);
        ui->Lien8QL->setText("(vide)");
        if (myFavoris.length() == 7) {
            ui->Lien8QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(7), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(7), "");
            mySettings.endGroup();
        }
        if (myFavoris.length() == 8) {
            ui->Lien9QL->setText("(vide)");
            mySettings.beginGroup("FavorisWeb");
            mySettings.setValue("FavorisWebLien" + QString::number(8), QUrl(""));
            mySettings.setValue("FavorisWebTitre" + QString::number(8), "");
            mySettings.endGroup();
        }
    }
    reorganiseFav();
}

void ControlMenuWeb::on_Lien9QTB_clicked() {
    if (ui->Lien9QL->text() != "(vide)") {
        myFavoris.remove(8);
        ui->Lien9QL->setText("(vide)");
        mySettings.beginGroup("FavorisWeb");
        mySettings.setValue("FavorisWebLien" + QString::number(8), QUrl(""));
        mySettings.setValue("FavorisWebTitre" + QString::number(8), "");
        mySettings.endGroup();
    }
    reorganiseFav();
}

void ControlMenuWeb::on_Lien1QL_clicked() {
    if (ui->Lien1QL->text() != "(vide)") {
        ui->Favoris->setIcon(QIcon(":/Images/1-NavigateurWeb/star.svg"));
        QList<QWebEngineView *> webViews = parentWidget()->findChildren<QWebEngineView *>();
        QList<QWebEngineView *>::iterator it = std::find_if(webViews.begin(), webViews.end(),
                                                            [](QWebEngineView *webView) -> bool {
                                                                return QLatin1String(
                                                                        webView->metaObject()->className()) ==
                                                                       "QWebEngineView";
                                                            });
        if (it != webViews.end() && myFavoris.length() >= 1) {
            QWebEngineView *mywebview = webViews.at(std::distance(webViews.begin(), it));
            mywebview->setUrl(myFavoris[0].url);
            QObject::connect(mywebview, &QWebEngineView::loadFinished,
                             [=](bool arg) {
                                 mywebview->setZoomFactor(myScale.toInt());
                             });
        }
    } else {
        return_To_Home();
    }
}

void ControlMenuWeb::on_Lien2QL_clicked() {
    if (ui->Lien2QL->text() != "(vide)") {
        ui->Favoris->setIcon(QIcon(":/Images/1-NavigateurWeb/star.svg"));
        QList<QWebEngineView *> webViews = parentWidget()->findChildren<QWebEngineView *>();
        QList<QWebEngineView *>::iterator it = std::find_if(webViews.begin(), webViews.end(),
                                                            [](QWebEngineView *webView) -> bool {
                                                                return QLatin1String(
                                                                        webView->metaObject()->className()) ==
                                                                       "QWebEngineView";
                                                            });
        if (it != webViews.end() && myFavoris.length() >= 2) {
            QWebEngineView *mywebview = webViews.at(std::distance(webViews.begin(), it));
            mywebview->setUrl(myFavoris[1].url);
            QObject::connect(mywebview, &QWebEngineView::loadFinished,
                             [=](bool arg) {
                                 mywebview->setZoomFactor(myScale.toInt());
                             });
        }
    } else {
        return_To_Home();
    }
}

void ControlMenuWeb::on_Lien3QL_clicked() {
    if (ui->Lien3QL->text() != "(vide)") {
        ui->Favoris->setIcon(QIcon(":/Images/1-NavigateurWeb/star.svg"));
        QList<QWebEngineView *> webViews = parentWidget()->findChildren<QWebEngineView *>();
        QList<QWebEngineView *>::iterator it = std::find_if(webViews.begin(), webViews.end(),
                                                            [](QWebEngineView *webView) -> bool {
                                                                return QLatin1String(
                                                                        webView->metaObject()->className()) ==
                                                                       "QWebEngineView";
                                                            });
        if (it != webViews.end() && myFavoris.length() >= 3) {
            QWebEngineView *mywebview = webViews.at(std::distance(webViews.begin(), it));
            mywebview->setUrl(myFavoris[2].url);
            QObject::connect(mywebview, &QWebEngineView::loadFinished,
                             [=](bool arg) {
                                 mywebview->setZoomFactor(myScale.toInt());
                             });
        }
    } else {
        return_To_Home();
    }
}

void ControlMenuWeb::on_Lien4QL_clicked() {
    if (ui->Lien4QL->text() != "(vide)") {
        ui->Favoris->setIcon(QIcon(":/Images/1-NavigateurWeb/star.svg"));
        QList<QWebEngineView *> webViews = parentWidget()->findChildren<QWebEngineView *>();
        QList<QWebEngineView *>::iterator it = std::find_if(webViews.begin(), webViews.end(),
                                                            [](QWebEngineView *webView) -> bool {
                                                                return QLatin1String(
                                                                        webView->metaObject()->className()) ==
                                                                       "QWebEngineView";
                                                            });
        if (it != webViews.end() && myFavoris.length() >= 4) {
            QWebEngineView *mywebview = webViews.at(std::distance(webViews.begin(), it));
            mywebview->setUrl(myFavoris[3].url);
            QObject::connect(mywebview, &QWebEngineView::loadFinished,
                             [=](bool arg) {
                                 mywebview->setZoomFactor(myScale.toInt());
                             });
        }
    } else {
        return_To_Home();
    }
}

void ControlMenuWeb::on_Lien5QL_clicked() {
    if (ui->Lien5QL->text() != "(vide)") {
        ui->Favoris->setIcon(QIcon(":/Images/1-NavigateurWeb/star.svg"));
        QList<QWebEngineView *> webViews = parentWidget()->findChildren<QWebEngineView *>();
        QList<QWebEngineView *>::iterator it = std::find_if(webViews.begin(), webViews.end(),
                                                            [](QWebEngineView *webView) -> bool {
                                                                return QLatin1String(
                                                                        webView->metaObject()->className()) ==
                                                                       "QWebEngineView";
                                                            });
        if (it != webViews.end() && myFavoris.length() >= 5) {
            QWebEngineView *mywebview = webViews.at(std::distance(webViews.begin(), it));
            mywebview->setUrl(myFavoris[4].url);
            QObject::connect(mywebview, &QWebEngineView::loadFinished,
                             [=](bool arg) {
                                 mywebview->setZoomFactor(myScale.toInt());
                             });
        }
    } else {
        return_To_Home();
    }
}

void ControlMenuWeb::on_Lien6QL_clicked() {
    if (ui->Lien6QL->text() != "(vide)") {
        ui->Favoris->setIcon(QIcon(":/Images/1-NavigateurWeb/star.svg"));
        QList<QWebEngineView *> webViews = parentWidget()->findChildren<QWebEngineView *>();
        QList<QWebEngineView *>::iterator it = std::find_if(webViews.begin(), webViews.end(),
                                                            [](QWebEngineView *webView) -> bool {
                                                                return QLatin1String(
                                                                        webView->metaObject()->className()) ==
                                                                       "QWebEngineView";
                                                            });
        if (it != webViews.end() && myFavoris.length() >= 6) {
            QWebEngineView *mywebview = webViews.at(std::distance(webViews.begin(), it));
            mywebview->setUrl(myFavoris[5].url);
            QObject::connect(mywebview, &QWebEngineView::loadFinished,
                             [=](bool arg) {
                                 mywebview->setZoomFactor(myScale.toInt());
                             });
        }
    } else {
        return_To_Home();
    }
}

void ControlMenuWeb::on_Lien7QL_clicked() {
    if (ui->Lien7QL->text() != "(vide)") {
        ui->Favoris->setIcon(QIcon(":/Images/1-NavigateurWeb/star.svg"));
        QList<QWebEngineView *> webViews = parentWidget()->findChildren<QWebEngineView *>();
        QList<QWebEngineView *>::iterator it = std::find_if(webViews.begin(), webViews.end(),
                                                            [](QWebEngineView *webView) -> bool {
                                                                return QLatin1String(
                                                                        webView->metaObject()->className()) ==
                                                                       "QWebEngineView";
                                                            });
        if (it != webViews.end() && myFavoris.length() >= 7) {
            QWebEngineView *mywebview = webViews.at(std::distance(webViews.begin(), it));
            mywebview->setUrl(myFavoris[6].url);
            QObject::connect(mywebview, &QWebEngineView::loadFinished,
                             [=](bool arg) {
                                 mywebview->setZoomFactor(myScale.toInt());
                             });
        }
    } else {
        return_To_Home();
    }
}

void ControlMenuWeb::on_Lien8QL_clicked() {
    if (ui->Lien8QL->text() != "(vide)") {
        ui->Favoris->setIcon(QIcon(":/Images/1-NavigateurWeb/star.svg"));
        QList<QWebEngineView *> webViews = parentWidget()->findChildren<QWebEngineView *>();
        QList<QWebEngineView *>::iterator it = std::find_if(webViews.begin(), webViews.end(),
                                                            [](QWebEngineView *webView) -> bool {
                                                                return QLatin1String(
                                                                        webView->metaObject()->className()) ==
                                                                       "QWebEngineView";
                                                            });
        if (it != webViews.end() && myFavoris.length() >= 8) {
            QWebEngineView *mywebview = webViews.at(std::distance(webViews.begin(), it));
            mywebview->setUrl(myFavoris[7].url);
            QObject::connect(mywebview, &QWebEngineView::loadFinished,
                             [=](bool arg) {
                                 mywebview->setZoomFactor(myScale.toInt());
                             });
        }
    } else {
        return_To_Home();
    }
}

void ControlMenuWeb::on_Lien9QL_clicked() {
    if (ui->Lien9QL->text() != "(vide)") {
        ui->Favoris->setIcon(QIcon(":/Images/1-NavigateurWeb/star.svg"));
        QList<QWebEngineView *> webViews = parentWidget()->findChildren<QWebEngineView *>();
        QList<QWebEngineView *>::iterator it = std::find_if(webViews.begin(), webViews.end(),
                                                            [](QWebEngineView *webView) -> bool {
                                                                return QLatin1String(
                                                                        webView->metaObject()->className()) ==
                                                                       "QWebEngineView";
                                                            });
        if (it != webViews.end() && myFavoris.length() >= 9) {
            QWebEngineView *mywebview = webViews.at(std::distance(webViews.begin(), it));
            mywebview->setUrl(myFavoris[8].url);
            QObject::connect(mywebview, &QWebEngineView::loadFinished,
                             [=](bool arg) {
                                 mywebview->setZoomFactor(myScale.toInt());
                             });
        }
    } else {
        return_To_Home();
    }
}

void ControlMenuWeb::reorganiseFav() {
    if (myFavoris.length() >= 1) {
        ui->Lien1QL->setText(myFavoris[0].title);
    }
    if (myFavoris.length() >= 2) {
        ui->Lien2QL->setText(myFavoris[1].title);
    }
    if (myFavoris.length() >= 3) {
        ui->Lien3QL->setText(myFavoris[2].title);
    }
    if (myFavoris.length() >= 4) {
        ui->Lien4QL->setText(myFavoris[3].title);
    }
    if (myFavoris.length() >= 5) {
        ui->Lien5QL->setText(myFavoris[4].title);
    }
    if (myFavoris.length() >= 6) {
        ui->Lien6QL->setText(myFavoris[5].title);
    }
    if (myFavoris.length() >= 7) {
        ui->Lien7QL->setText(myFavoris[6].title);
    }
    if (myFavoris.length() >= 8) {
        ui->Lien8QL->setText(myFavoris[7].title);
    }
    if (myFavoris.length() >= 9) {
        ui->Lien9QL->setText(myFavoris[8].title);
    }

    QList<QWebEngineView *> webViews = parentWidget()->findChildren<QWebEngineView *>();
    QList<QWebEngineView *>::iterator it = std::find_if(webViews.begin(), webViews.end(),
                                                        [](QWebEngineView *webView) -> bool {
                                                            return QLatin1String(
                                                                    webView->metaObject()->className()) ==
                                                                   "QWebEngineView";
                                                        });
    if (it != webViews.end()) {
        QWebEngineView *mywebview = webViews.at(std::distance(webViews.begin(), it));
        favBool = false;
#ifndef __APPLE__
        QObject::connect(mywebview, &QWebEngineView::loadFinished,
                         [=](bool arg) {
#endif
                             for (int i = 0; i < myFavoris.length(); i++) {
                                 mySettings.beginGroup("FavorisWeb");
                                 mySettings.setValue("FavorisWebLien" + QString::number(i), myFavoris[i].url);
                                 mySettings.setValue("FavorisWebTitre" + QString::number(i), myFavoris[i].title);
                                 mySettings.endGroup();
                                 if (!favBool) {
                                     if (mywebview->url() == myFavoris[i].url) {
                                         ui->Favoris->setIcon(QIcon(":/Images/1-NavigateurWeb/star.svg"));
                                         favBool = true;
                                     } else {
                                         ui->Favoris->setIcon(QIcon(":/Images/1-NavigateurWeb/star-clear.svg"));
                                     }
                                 }
                             }
#ifndef __APPLE__
                         });
#endif
    }

}

