#include "controlmenucalc.h"
#include "ui_controlmenucalc.h"
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

ControlMenuCalc::ControlMenuCalc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlMenuCalc)
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

    ui->Home_App->setMaximumWidth(sizeButton);
    ui->Home_App->setMaximumHeight(sizeButton);
    ui->Home_App->setIconSize(QSize(sizeButton, sizeButton));

    ui->Retour->setMaximumWidth(sizeButton);
    ui->Retour->setMaximumHeight(sizeButton);
    ui->Retour->setIconSize(QSize(sizeButton, sizeButton));
/**
    ui->Options->setMaximumWidth(sizeButton);
    ui->Options->setMaximumHeight(sizeButton);
    ui->Options->setIconSize(QSize(sizeButton, sizeButton));
**/
    ui->horizontalSpacer_2->changeSize(sizeButton,sizeButton);

    int Size = (int)((1920 * 1920 * dpi) / WIDTH);

    ui->Horlorge->setMinimumWidth(sizeButton*1.5);
    ui->Horlorge->setMaximumWidth(Size);

    ui->gridLayout->setColumnMinimumWidth(1,Size);

    WIDTHCONTROL = int(WIDTH * 720 / 3840 -50);

    ui->gridWidget->resize(WIDTHCONTROL, HEIGHT - 50);

    QTimer *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &ControlMenuCalc::showTime);
    timer->start(1000);

    showTime();

    mySettings.beginGroup("UrlIci");
    UrlIci = mySettings.value("UrlIci").toUrl();
    mySettings.endGroup();
}

ControlMenuCalc::~ControlMenuCalc()
{
    delete ui;
}

void ControlMenuCalc::on_Fermeture_clicked()
{
}
void ControlMenuCalc::on_Home_clicked() {
#if defined(_WIN32) || defined(__APPLE__)
    qApp->closeAllWindows();
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    this->close();
#endif
    this->parentWidget()->close();
}

void ControlMenuCalc::on_Home_App_clicked() {
    QList<QWebEngineView *> webViews = parentWidget()->findChildren<QWebEngineView *>();
    QList<QWebEngineView *>::iterator it = std::find_if(webViews.begin(), webViews.end(),
                                                        [](QWebEngineView *webView) -> bool {
                                                            return QLatin1String(webView->metaObject()->className()) ==
                                                                   "QWebEngineView";
                                                        });
    if (it != webViews.end()) {
        QWebEngineView *mywebview = webViews.at(std::distance(webViews.begin(), it));
        mywebview->setUrl(UrlIci);
        QObject::connect(mywebview, &QWebEngineView::loadFinished,
                         [=](bool arg) {
                             mywebview->setZoomFactor(myScale.toInt());
                         });
    }
}

/**void ControlMenuCalc::on_Options_clicked() {
    Options *myOptions = new Options();
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    pal.setColor(QPalette::WindowText, Qt::white);
    myOptions->setAutoFillBackground(true);
    myOptions->setPalette(pal);
    myOptions->setStyleSheet("background-color:black; color:#fff");
    myOptions->show();
}**/

void ControlMenuCalc::on_Retour_clicked() {
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

void ControlMenuCalc::showTime()
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
