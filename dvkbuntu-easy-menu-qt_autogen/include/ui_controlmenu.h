/********************************************************************************
** Form generated from reading UI file 'controlmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLMENU_H
#define UI_CONTROLMENU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlMenu
{
public:
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QToolButton *Fermeture;
    QSpacerItem *verticalSpacer_2;
    QLabel *Horlorge;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_1;
    QToolButton *Options;
    QSpacerItem *horizontalSpacer;
    QToolButton *Home;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *ControlMenu)
    {
        if (ControlMenu->objectName().isEmpty())
            ControlMenu->setObjectName(QString::fromUtf8("ControlMenu"));
        ControlMenu->resize(562, 800);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ControlMenu->sizePolicy().hasHeightForWidth());
        ControlMenu->setSizePolicy(sizePolicy);
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
        ControlMenu->setPalette(palette);
        ControlMenu->setStyleSheet(QString::fromUtf8(""));
        gridWidget = new QWidget(ControlMenu);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setGeometry(QRect(0, 10, 400, 800));
        sizePolicy.setHeightForWidth(gridWidget->sizePolicy().hasHeightForWidth());
        gridWidget->setSizePolicy(sizePolicy);
        gridWidget->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setSpacing(9);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Fermeture = new QToolButton(gridWidget);
        Fermeture->setObjectName(QString::fromUtf8("Fermeture"));
        sizePolicy.setHeightForWidth(Fermeture->sizePolicy().hasHeightForWidth());
        Fermeture->setSizePolicy(sizePolicy);
        Fermeture->setMinimumSize(QSize(0, 0));
        Fermeture->setMaximumSize(QSize(80, 80));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/1-NavigateurWeb/close-alt.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Fermeture->setIcon(icon);
        Fermeture->setIconSize(QSize(100, 100));

        gridLayout->addWidget(Fermeture, 0, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 160, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 3, 1, 1);

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

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        verticalSpacer_1 = new QSpacerItem(50, 80, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_1, 2, 3, 1, 1);

        Options = new QToolButton(gridWidget);
        Options->setObjectName(QString::fromUtf8("Options"));
        sizePolicy.setHeightForWidth(Options->sizePolicy().hasHeightForWidth());
        Options->setSizePolicy(sizePolicy);
        Options->setMinimumSize(QSize(0, 0));
        Options->setMaximumSize(QSize(80, 80));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/2-Calculatrice/cogs.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Options->setIcon(icon1);
        Options->setIconSize(QSize(100, 100));

        gridLayout->addWidget(Options, 3, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        Home = new QToolButton(gridWidget);
        Home->setObjectName(QString::fromUtf8("Home"));
        sizePolicy.setHeightForWidth(Home->sizePolicy().hasHeightForWidth());
        Home->setSizePolicy(sizePolicy);
        Home->setMinimumSize(QSize(0, 0));
        Home->setMaximumSize(QSize(80, 80));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Images/1-NavigateurWeb/home.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Home->setIcon(icon2);
        Home->setIconSize(QSize(100, 100));

        gridLayout->addWidget(Home, 1, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 4, 1, 1);


        retranslateUi(ControlMenu);

        QMetaObject::connectSlotsByName(ControlMenu);
    } // setupUi

    void retranslateUi(QWidget *ControlMenu)
    {
        ControlMenu->setWindowTitle(QApplication::translate("ControlMenu", "Form", nullptr));
        Fermeture->setText(QApplication::translate("ControlMenu", "...", nullptr));
        Horlorge->setText(QApplication::translate("ControlMenu", "TextLabel", nullptr));
        Options->setText(QApplication::translate("ControlMenu", "...", nullptr));
        Home->setText(QApplication::translate("ControlMenu", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControlMenu: public Ui_ControlMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLMENU_H
