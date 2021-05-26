#ifndef CONTROLMENUOFFICE_H
#define CONTROLMENUOFFICE_H

#include <QWidget>
#include <QMainWindow>
#include <QRect>
#include <QScreen>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "options.h"
#include "ui_options.h"


namespace Ui {
class ControlMenuOffice;
}

class ControlMenuOffice : public QWidget
{
    Q_OBJECT

public:
    explicit ControlMenuOffice(QWidget *parent = nullptr);
    ~ControlMenuOffice();
    QSettings mySettings;
    QUrl UrlIci;

private:
    Ui::ControlMenuOffice *ui;
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
#endif // CONTROLMENUOFFICE_H
