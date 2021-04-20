/********************************************************************************
** Form generated from reading UI file 'controlmenumail.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLMENUMAIL_H
#define UI_CONTROLMENUMAIL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlMenuMail
{
public:
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_1;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QToolButton *Home;
    QToolButton *Fermeture;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *Options;
    QSpacerItem *verticalSpacer_2;
    QLabel *Horlorge;
    QToolButton *Gmail;
    QToolButton *Yahoo;
    QToolButton *SFR;
    QToolButton *Bouygues;
    QToolButton *Outlook;
    QToolButton *Orange;
    QToolButton *Free;
    QToolButton *LaPoste;

    void setupUi(QWidget *ControlMenuMail)
    {
        if (ControlMenuMail->objectName().isEmpty())
            ControlMenuMail->setObjectName(QString::fromUtf8("ControlMenuMail"));
        ControlMenuMail->resize(562, 800);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ControlMenuMail->sizePolicy().hasHeightForWidth());
        ControlMenuMail->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(15, 15, 17, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(22, 22, 25, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(18, 18, 21, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(7, 7, 8, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(10, 10, 11, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush8(QColor(255, 255, 255, 128));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        ControlMenuMail->setPalette(palette);
        ControlMenuMail->setStyleSheet(QString::fromUtf8(""));
        gridWidget = new QWidget(ControlMenuMail);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setGeometry(QRect(0, 20, 400, 800));
        sizePolicy.setHeightForWidth(gridWidget->sizePolicy().hasHeightForWidth());
        gridWidget->setSizePolicy(sizePolicy);
        gridWidget->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setSpacing(9);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_3 = new QSpacerItem(50, 80, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_3, 4, 3, 1, 1);

        verticalSpacer_1 = new QSpacerItem(50, 80, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_1, 2, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 14, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 8, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        Home = new QToolButton(gridWidget);
        Home->setObjectName(QString::fromUtf8("Home"));
        sizePolicy.setHeightForWidth(Home->sizePolicy().hasHeightForWidth());
        Home->setSizePolicy(sizePolicy);
        Home->setMinimumSize(QSize(0, 0));
        Home->setMaximumSize(QSize(80, 80));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/1-NavigateurWeb/home.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Home->setIcon(icon);
        Home->setIconSize(QSize(100, 100));

        gridLayout->addWidget(Home, 1, 3, 1, 1);

        Fermeture = new QToolButton(gridWidget);
        Fermeture->setObjectName(QString::fromUtf8("Fermeture"));
        sizePolicy.setHeightForWidth(Fermeture->sizePolicy().hasHeightForWidth());
        Fermeture->setSizePolicy(sizePolicy);
        Fermeture->setMinimumSize(QSize(0, 0));
        Fermeture->setMaximumSize(QSize(80, 80));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/1-NavigateurWeb/close-alt.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Fermeture->setIcon(icon1);
        Fermeture->setIconSize(QSize(100, 100));

        gridLayout->addWidget(Fermeture, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        Options = new QToolButton(gridWidget);
        Options->setObjectName(QString::fromUtf8("Options"));
        sizePolicy.setHeightForWidth(Options->sizePolicy().hasHeightForWidth());
        Options->setSizePolicy(sizePolicy);
        Options->setMinimumSize(QSize(0, 0));
        Options->setMaximumSize(QSize(80, 80));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Images/2-Calculatrice/cogs.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Options->setIcon(icon2);
        Options->setIconSize(QSize(100, 100));

        gridLayout->addWidget(Options, 3, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 160, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 13, 3, 1, 1);

        Horlorge = new QLabel(gridWidget);
        Horlorge->setObjectName(QString::fromUtf8("Horlorge"));
        sizePolicy.setHeightForWidth(Horlorge->sizePolicy().hasHeightForWidth());
        Horlorge->setSizePolicy(sizePolicy);
        Horlorge->setMinimumSize(QSize(0, 0));
        Horlorge->setMaximumSize(QSize(0, 100));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        Horlorge->setFont(font);
        Horlorge->setStyleSheet(QString::fromUtf8("color: red;"));
        Horlorge->setScaledContents(false);
        Horlorge->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(Horlorge, 0, 1, 1, 1);

        Gmail = new QToolButton(gridWidget);
        Gmail->setObjectName(QString::fromUtf8("Gmail"));
        sizePolicy.setHeightForWidth(Gmail->sizePolicy().hasHeightForWidth());
        Gmail->setSizePolicy(sizePolicy);
        Gmail->setMinimumSize(QSize(0, 0));
        Gmail->setMaximumSize(QSize(80, 80));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Images/4-Courriel/Gmail.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Gmail->setIcon(icon3);
        Gmail->setIconSize(QSize(100, 100));

        gridLayout->addWidget(Gmail, 5, 2, 1, 1);

        Yahoo = new QToolButton(gridWidget);
        Yahoo->setObjectName(QString::fromUtf8("Yahoo"));
        sizePolicy.setHeightForWidth(Yahoo->sizePolicy().hasHeightForWidth());
        Yahoo->setSizePolicy(sizePolicy);
        Yahoo->setMinimumSize(QSize(0, 0));
        Yahoo->setMaximumSize(QSize(80, 80));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Images/4-Courriel/Yahoo.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Yahoo->setIcon(icon4);
        Yahoo->setIconSize(QSize(100, 100));

        gridLayout->addWidget(Yahoo, 6, 2, 1, 1);

        SFR = new QToolButton(gridWidget);
        SFR->setObjectName(QString::fromUtf8("SFR"));
        sizePolicy.setHeightForWidth(SFR->sizePolicy().hasHeightForWidth());
        SFR->setSizePolicy(sizePolicy);
        SFR->setMinimumSize(QSize(0, 0));
        SFR->setMaximumSize(QSize(80, 80));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Images/4-Courriel/SFR.svg"), QSize(), QIcon::Normal, QIcon::Off);
        SFR->setIcon(icon5);
        SFR->setIconSize(QSize(100, 100));

        gridLayout->addWidget(SFR, 7, 2, 1, 1);

        Bouygues = new QToolButton(gridWidget);
        Bouygues->setObjectName(QString::fromUtf8("Bouygues"));
        sizePolicy.setHeightForWidth(Bouygues->sizePolicy().hasHeightForWidth());
        Bouygues->setSizePolicy(sizePolicy);
        Bouygues->setMinimumSize(QSize(0, 0));
        Bouygues->setMaximumSize(QSize(80, 80));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Images/4-Courriel/Bouygues.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Bouygues->setIcon(icon6);
        Bouygues->setIconSize(QSize(100, 100));

        gridLayout->addWidget(Bouygues, 8, 2, 1, 1);

        Outlook = new QToolButton(gridWidget);
        Outlook->setObjectName(QString::fromUtf8("Outlook"));
        sizePolicy.setHeightForWidth(Outlook->sizePolicy().hasHeightForWidth());
        Outlook->setSizePolicy(sizePolicy);
        Outlook->setMinimumSize(QSize(0, 0));
        Outlook->setMaximumSize(QSize(80, 80));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Images/4-Courriel/Outlook.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Outlook->setIcon(icon7);
        Outlook->setIconSize(QSize(100, 100));

        gridLayout->addWidget(Outlook, 5, 3, 1, 1);

        Orange = new QToolButton(gridWidget);
        Orange->setObjectName(QString::fromUtf8("Orange"));
        sizePolicy.setHeightForWidth(Orange->sizePolicy().hasHeightForWidth());
        Orange->setSizePolicy(sizePolicy);
        Orange->setMinimumSize(QSize(0, 0));
        Orange->setMaximumSize(QSize(80, 80));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Images/4-Courriel/Orange.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Orange->setIcon(icon8);
        Orange->setIconSize(QSize(100, 100));

        gridLayout->addWidget(Orange, 6, 3, 1, 1);

        Free = new QToolButton(gridWidget);
        Free->setObjectName(QString::fromUtf8("Free"));
        sizePolicy.setHeightForWidth(Free->sizePolicy().hasHeightForWidth());
        Free->setSizePolicy(sizePolicy);
        Free->setMinimumSize(QSize(0, 0));
        Free->setMaximumSize(QSize(80, 80));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Images/4-Courriel/Free.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Free->setIcon(icon9);
        Free->setIconSize(QSize(100, 100));

        gridLayout->addWidget(Free, 7, 3, 1, 1);

        LaPoste = new QToolButton(gridWidget);
        LaPoste->setObjectName(QString::fromUtf8("LaPoste"));
        sizePolicy.setHeightForWidth(LaPoste->sizePolicy().hasHeightForWidth());
        LaPoste->setSizePolicy(sizePolicy);
        LaPoste->setMinimumSize(QSize(0, 0));
        LaPoste->setMaximumSize(QSize(80, 80));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Images/4-Courriel/LaPoste.svg"), QSize(), QIcon::Normal, QIcon::Off);
        LaPoste->setIcon(icon10);
        LaPoste->setIconSize(QSize(100, 100));

        gridLayout->addWidget(LaPoste, 8, 3, 1, 1);


        retranslateUi(ControlMenuMail);

        QMetaObject::connectSlotsByName(ControlMenuMail);
    } // setupUi

    void retranslateUi(QWidget *ControlMenuMail)
    {
        ControlMenuMail->setWindowTitle(QApplication::translate("ControlMenuMail", "Form", nullptr));
        Home->setText(QApplication::translate("ControlMenuMail", "...", nullptr));
        Fermeture->setText(QApplication::translate("ControlMenuMail", "...", nullptr));
        Options->setText(QApplication::translate("ControlMenuMail", "...", nullptr));
        Horlorge->setText(QApplication::translate("ControlMenuMail", "TextLabel", nullptr));
        Gmail->setText(QApplication::translate("ControlMenuMail", "...", nullptr));
        Yahoo->setText(QApplication::translate("ControlMenuMail", "...", nullptr));
        SFR->setText(QApplication::translate("ControlMenuMail", "...", nullptr));
        Bouygues->setText(QApplication::translate("ControlMenuMail", "...", nullptr));
        Outlook->setText(QApplication::translate("ControlMenuMail", "...", nullptr));
        Orange->setText(QApplication::translate("ControlMenuMail", "...", nullptr));
        Free->setText(QApplication::translate("ControlMenuMail", "...", nullptr));
        LaPoste->setText(QApplication::translate("ControlMenuMail", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControlMenuMail: public Ui_ControlMenuMail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLMENUMAIL_H
