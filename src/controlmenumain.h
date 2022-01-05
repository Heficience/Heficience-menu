#ifndef CONTROLMENUMAIN_H
#define CONTROLMENUMAIN_H

#include <QWidget>
#include <QMainWindow>
#include <QRect>
#include <QScreen>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "options.h"
#include "ui_options.h"

namespace Ui {
class ControlMenuMain;
}

class ControlMenuMain : public QWidget
{
    Q_OBJECT

public:
    explicit ControlMenuMain(QWidget *parent = nullptr);
    ~ControlMenuMain();
    QSettings mySettings;
    bool DarkMode;
    bool FirstTime = true;

private:
    Ui::ControlMenuMain *ui;
    QList<QScreen*> screens;
    QScreen *screen;
    QRect screenGeometry;
    QSize QS2;
    int fSize2;
    int HEIGHT;
    int WIDTH;
    int WIDTHCONTROL;

private slots:
    void on_Fermeture_clicked();
    void on_Home_clicked();
    //void on_Options_clicked();
    void on_PowerOff_clicked();
    void showTime();
    void on_DarkMode_toggled(bool checked);
    void on_NormalMode_toggled(bool checked);
    void Reload();
};
#endif // CONTROLMENUMAIN_H