//
// Created by paul on 24/04/2021.
//

#ifndef MYWEBENGINEPAGE_H
#define MYWEBENGINEPAGE_H


#include <QArgument>
#include <QWebEngineProfile>
#include <QWebEngineUrlRequestInfo>
#include <QWebEnginePage>
#include <QWebEngineSettings>
#include <QtWebEngineWidgets>
#include <QApplication>
#include <QUrl>
#include <QWebEngineView>

class MyWebEnginePage : public QWebEnginePage
{
    Q_OBJECT
public:
    QList<QScreen*> screens = QGuiApplication::screens();
    QScreen *screen = screens.first();
    QRect screenGeometry = screen->geometry();
    qreal WIDTH = screenGeometry.width();
    double dpi = QGuiApplication::primaryScreen()->physicalDotsPerInch();
    QString myScale = QString::number(int(2.5 * (dpi /159.856) * (WIDTH / 3840)));
    QWebEnginePage *createWindow(MyWebEnginePage::WebWindowType);
    MyWebEnginePage(QObject *parent = Q_NULLPTR):QWebEnginePage(parent){
            connect(this, &MyWebEnginePage::featurePermissionRequested, this, &MyWebEnginePage::onFeaturePermissionRequested);
    }
private Q_SLOTS:
    void onFeaturePermissionRequested(const QUrl &securityOrigin, QWebEnginePage::Feature feature){
        if(feature  == QWebEnginePage::MediaAudioCapture
           || feature == QWebEnginePage::MediaVideoCapture
           || feature == QWebEnginePage::MediaAudioVideoCapture)
            setFeaturePermission(securityOrigin, feature, QWebEnginePage::PermissionGrantedByUser);
        else
            setFeaturePermission(securityOrigin, feature, QWebEnginePage::PermissionDeniedByUser);
    }
    void onUrlChanged(const QUrl & url){
        if(MyWebEnginePage *page = qobject_cast<MyWebEnginePage *>(sender())){
            setUrl(url);
            page->deleteLater();
        }
    }
};

#endif //MYWEBENGINEPAGE_H
