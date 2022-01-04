#include <QWebEnginePage>
#include <QWebEngineSettings>
#include <QtWebEngineWidgets>
#include "mywebenginepage.h"
#include "controlmenumail.h"
#include "ui_controlmenumail.h"
#include "controlmenumain.h"

QWebEnginePage* MyWebEnginePage::createWindow(QWebEnginePage::WebWindowType Type)
{
    MyWebEnginePage *page = new MyWebEnginePage(this);
    connect(page, &QWebEnginePage::urlChanged, this, &MyWebEnginePage::onUrlChanged);
    return page;
}
