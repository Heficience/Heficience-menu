/********************************************************************************
** Form generated from reading UI file 'controlmenumain.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLMENUMAIN_H
#define UI_CONTROLMENUMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlMenuMain
{
public:
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QToolButton *Options;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *PowerOff;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_1;
    QSpacerItem *horizontalSpacer;
    QToolButton *Home;
    QLabel *Horlorge;
    QToolButton *Fermeture;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *ControlMenuMain)
    {
        if (ControlMenuMain->objectName().isEmpty())
            ControlMenuMain->setObjectName(QString::fromUtf8("ControlMenuMain"));
        ControlMenuMain->resize(523, 800);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ControlMenuMain->sizePolicy().hasHeightForWidth());
        ControlMenuMain->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(28, 28, 30, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        ControlMenuMain->setPalette(palette);
        ControlMenuMain->setStyleSheet(QString::fromUtf8(""));
        gridWidget = new QWidget(ControlMenuMain);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setGeometry(QRect(0, 10, 400, 800));
        sizePolicy.setHeightForWidth(gridWidget->sizePolicy().hasHeightForWidth());
        gridWidget->setSizePolicy(sizePolicy);
        gridWidget->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setSpacing(9);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Options = new QToolButton(gridWidget);
        Options->setObjectName(QString::fromUtf8("Options"));
        sizePolicy.setHeightForWidth(Options->sizePolicy().hasHeightForWidth());
        Options->setSizePolicy(sizePolicy);
        Options->setMinimumSize(QSize(0, 0));
        Options->setMaximumSize(QSize(80, 80));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/2-Calculatrice/cogs.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Options->setIcon(icon);
        Options->setIconSize(QSize(100, 100));

        gridLayout->addWidget(Options, 3, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        PowerOff = new QToolButton(gridWidget);
        PowerOff->setObjectName(QString::fromUtf8("PowerOff"));
        sizePolicy.setHeightForWidth(PowerOff->sizePolicy().hasHeightForWidth());
        PowerOff->setSizePolicy(sizePolicy);
        PowerOff->setMinimumSize(QSize(0, 0));
        PowerOff->setMaximumSize(QSize(80, 80));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/1-NavigateurWeb/PowerOff.svg"), QSize(), QIcon::Normal, QIcon::Off);
        PowerOff->setIcon(icon1);
        PowerOff->setIconSize(QSize(100, 100));

        gridLayout->addWidget(PowerOff, 5, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 3, 1, 1);

        verticalSpacer_1 = new QSpacerItem(50, 80, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_1, 2, 3, 1, 1);

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

        Fermeture = new QToolButton(gridWidget);
        Fermeture->setObjectName(QString::fromUtf8("Fermeture"));
        sizePolicy.setHeightForWidth(Fermeture->sizePolicy().hasHeightForWidth());
        Fermeture->setSizePolicy(sizePolicy);
        Fermeture->setMinimumSize(QSize(0, 0));
        Fermeture->setMaximumSize(QSize(80, 80));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Images/1-NavigateurWeb/close-alt.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Fermeture->setIcon(icon3);
        Fermeture->setIconSize(QSize(100, 100));

        gridLayout->addWidget(Fermeture, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 4, 1, 1);


        retranslateUi(ControlMenuMain);

        QMetaObject::connectSlotsByName(ControlMenuMain);
    } // setupUi

    void retranslateUi(QWidget *ControlMenuMain)
    {
        ControlMenuMain->setWindowTitle(QApplication::translate("ControlMenuMain", "Form", nullptr));
        Options->setText(QApplication::translate("ControlMenuMain", "...", nullptr));
        PowerOff->setText(QApplication::translate("ControlMenuMain", "...", nullptr));
        Home->setText(QApplication::translate("ControlMenuMain", "...", nullptr));
        Horlorge->setText(QApplication::translate("ControlMenuMain", "TextLabel", nullptr));
        Fermeture->setText(QApplication::translate("ControlMenuMain", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControlMenuMain: public Ui_ControlMenuMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLMENUMAIN_H
