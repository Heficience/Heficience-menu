#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QMouseEvent>
#include <QProcess>
#include <QWidget>
#include <QApplication>
#include <QUrl>
#include <QMessageBox>
#include <QWebEngineView>
#include <QRect>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDesktopWidget>
#include <QSettings>
#include <QWebEngineProfile>
#include "controlmenu.h"
#include "controlmenumail.h"
#include "controlmenumain.h"
#include "mywebenginepage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QToolButton *Calculatrice;
    QToolButton *Email;
    QToolButton *Internet;
    QToolButton *Notes;
    QToolButton *Discord;
    QToolButton *Music;
    int ServiceMusique;
    int ServiceMail;
    QWindow* ma_fenetreG;
    QWidget *FenG;
    QWidget *FenC;
    QWidget *FenE;
    QWidget *FenI;
    QWidget *FenN;
    QWidget *FenD;
    QWidget *FenM;
    QList<QScreen*> screens;
    QScreen *screen;
    QRect screenGeometry;
    QFont fontC;
    QFont fontE;
    QFont fontI;
    QFont fontN;
    QFont fontD;
    QFont fontM;
    QSize QS1;
    int fSize1;
    QSize QS2;
    int fSize2;
    int HEIGHT;
    qreal WIDTH;
    int WIDTHCONTROL;
    int WIDTHMAIN;
    QProcess *m_process = new QProcess;
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    QMediaPlayer *player = new QMediaPlayer;
    QWidget* menuG;
    QWidget* menuC;
    QWidget* menuE;
    QWidget* menuI;
    QWidget* menuN;
    QWidget* menuD;
    QWidget* menuM;
    QWebEngineView *KCalculatrice = new QWebEngineView;
    QWebEngineView *DiscordLauncher = new QWebEngineView;
    QWebEngineView *web = new QWebEngineView;
    QWebEngineView *office = new QWebEngineView;
    QWebEngineView *music = new QWebEngineView;
    QWebEngineView *mail = new QWebEngineView;
    QWebEngineProfile *profileE = new QWebEngineProfile;
    QWebEngineProfile *profileD = new QWebEngineProfile;
    QString myScale;
    QString myScale2;
    QLayout *myLayout;
    QProcess GetValue;

private:
    Ui::MainWindow *ui;
    bool play = false;
    QString program;
    QString PIDtxt;
    QProcess WidFromPid;
    WId myWinID;
    int myPid;
    QWidget* myWidgetKCalc;
    QWidget* myWidgetOffice;
    QWidget* myWidgetweb;
    QWidget* myWidgetDiscord;
    QWidget *FenApp;

private slots:
    virtual bool eventFilter(QObject* watched, QEvent* event);
    void on_Calculatrice_clicked();
    void on_Email_clicked();
    void on_Notes_clicked();
    void on_Internet_clicked();
    void on_Music_clicked();
    void on_Discord_clicked();
    static void handleStateChanged(QProcess *procss, QWidget *widget, QWidget *killtest);
    void OpenNewWindows(MyWebEnginePage *);
    void ExecuteJS(bool);
};

#endif // MAINWINDOW_H