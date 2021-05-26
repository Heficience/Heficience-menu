#ifndef CONTROLMENUCALC_H
#define CONTROLMENUCALC_H

#include <QWidget>
#include <QMainWindow>
#include <QRect>
#include <QScreen>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "options.h"
#include "ui_options.h"


namespace Ui {
class ControlMenuCalc;
}

class ControlMenuCalc : public QWidget
{
    Q_OBJECT

public:
    explicit ControlMenuCalc(QWidget *parent = nullptr);
    ~ControlMenuCalc();
    QSettings mySettings;
    QUrl UrlIci;

private:
    Ui::ControlMenuCalc *ui;
    QList<QScreen*> screens;
    QScreen *screen;
    QRect screenGeometry;
    QSize QS2;
    int fSize2;
    int HEIGHT;
    int WIDTH;
    int WIDTHCONTROL;
    QString myScale;

private slots:
    void on_Fermeture_clicked();
    void on_Home_clicked();
    void on_Home_App_clicked();
    //void on_Options_clicked();
    void on_Retour_clicked();
    void showTime();
};
#endif // CONTROLMENUCALC_H
