#ifndef OPTIONS_H
#define OPTIONS_H

#include <QWidget>
#include <QMainWindow>
#include <QSettings>
#include "options.h"
#include "ui_options.h"
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Options; }
QT_END_NAMESPACE

class Options : public QMainWindow
{
    Q_OBJECT

public:
    Options(QWidget *parent = nullptr);
    ~Options();
    QString ChoixServiceMusique;
    QSettings mySettings;
    bool CanUse = false;

private:
    Ui::Options *ui;
    QList<QScreen*> screens;
    QScreen *screen;
    QRect screenGeometry;
    QSize QS2;
    int fSize2;
    int HEIGHT;
    int WIDTH;
    QFont font;

private slots:
    void on_Arretoptions_clicked();
    void on_Jamendo_toggled();
    void on_YouTube_toggled();
    void on_Deezer_toggled();
    void on_SoundCloud_toggled();
    void on_Spotify_toggled();
    void on_apply_clicked();
};
#endif // OPTIONS_H
