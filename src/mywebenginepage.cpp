#include <QWebEnginePage>
#include <QWebEngineSettings>
#include <QtWebEngineWidgets>
#include "mywebenginepage.h"
#include "controlmenumail.h"
#include "ui_controlmenumail.h"
#include "controlmenumain.h"

QWebEnginePage* MyWebEnginePage::createWindow(QWebEnginePage::WebWindowType Type)
{
    return this;
}
