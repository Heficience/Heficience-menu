#ifndef CONTROLMENUMAIL_H
#define CONTROLMENUMAIL_H

#include <QWidget>
#include <QMainWindow>
#include <QRect>
#include <QScreen>
#include <QWebEngineProfile>
#include <QSettings>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "options.h"
#include "ui_options.h"


namespace Ui {
class ControlMenuMail;
}

class ControlMenuMail : public QWidget
{
    Q_OBJECT

public:
    explicit ControlMenuMail(QWidget *parent = nullptr);
    ~ControlMenuMail();
    QString ChoixServiceMail;
    QProcess SetValue;
    QWidget *FenE;
    QWidget* menuE;
    QWebEngineView *mail = new QWebEngineView;
    QWebEngineProfile *profile = new QWebEngineProfile;
    QString myScale;
    QProcess *m_process = new QProcess;
    QSettings mySettings;

private:
    Ui::ControlMenuMail *ui;
    QList<QScreen*> screens;
    QScreen *screen;
    QRect screenGeometry;
    QSize QS2;
    int fSize2;
    int HEIGHT;
    int WIDTH;
    int WIDTHCONTROL;
    int WIDTHMAIN;
    QLayout *myLayout;

private slots:
    void on_Fermeture_clicked();
    void on_Home_clicked();
    void on_Home_App_clicked();
    //void on_Options_clicked();
    void on_Retour_clicked();
    void on_Gmail_clicked();
    void on_Outlook_clicked();
    void on_Yahoo_clicked();
    void on_Orange_clicked();
    void on_SFR_clicked();
    void on_Free_clicked();
    void on_Bouygues_clicked();
    void on_LaPoste_clicked();
    void showTime();
};

#endif // CONTROLMENUMAIL_H
