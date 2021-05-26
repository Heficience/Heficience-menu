#ifndef CONTROLMENUWEB_H
#define CONTROLMENUWEB_H

#include <QWidget>
#include <QMainWindow>
#include <QRect>
#include <QScreen>
#include <QList>
#include <iostream>
#include <vector>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "options.h"
#include "ui_options.h"

namespace Ui {
class ControlMenuWeb;
}

class ControlMenuWeb : public QWidget
{
    Q_OBJECT

public:
    explicit ControlMenuWeb(QWidget *parent = nullptr);
    ~ControlMenuWeb();
    struct myFavori
    {
        QUrl url;
        QString title;
    };
    QVector<myFavori> myFavoris;
    QSettings mySettings;


private:
    Ui::ControlMenuWeb *ui;
    QList<QScreen*> screens;
    QScreen *screen;
    QRect screenGeometry;
    QSize QS2;
    int fSize2;
    int fSize3;
    int HEIGHT;
    int WIDTH;
    int WIDTHCONTROL;
    QString myScale;


private slots:
    void on_Fermeture_clicked();
    void on_Home_clicked();
    void on_Home_App_clicked();
    //void on_Options_clicked();
    void on_Favoris_clicked();
    void on_Retour_clicked();
    void showTime();

    void on_Lien1QTB_clicked();
    void on_Lien2QTB_clicked();
    void on_Lien3QTB_clicked();
    void on_Lien4QTB_clicked();
    void on_Lien5QTB_clicked();
    void on_Lien6QTB_clicked();
    void on_Lien7QTB_clicked();
    void on_Lien8QTB_clicked();
    void on_Lien9QTB_clicked();

    void on_Lien1QL_clicked();
    void on_Lien2QL_clicked();
    void on_Lien3QL_clicked();
    void on_Lien4QL_clicked();
    void on_Lien5QL_clicked();
    void on_Lien6QL_clicked();
    void on_Lien7QL_clicked();
    void on_Lien8QL_clicked();
    void on_Lien9QL_clicked();

    void reorganiseFav();
};

#endif // CONTROLMENUWEB_H
