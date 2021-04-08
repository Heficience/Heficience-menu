/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Options
{
public:
    QWidget *gridWidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_1;
    QSpacerItem *horizontalSpacer_1;
    QRadioButton *Jamendo;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *Deezer;
    QRadioButton *YouTube;
    QDialogButtonBox *buttonBox;
    QLabel *Choix;
    QLabel *Redemarrage;
    QToolButton *Arretoptions;

    void setupUi(QWidget *Options)
    {
        if (Options->objectName().isEmpty())
            Options->setObjectName(QString::fromUtf8("Options"));
        Options->resize(1704, 954);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Options->sizePolicy().hasHeightForWidth());
        Options->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(28, 28, 30, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        Options->setPalette(palette);
        QFont font;
        font.setPointSize(25);
        Options->setFont(font);
        Options->setStyleSheet(QString::fromUtf8(""));
        gridWidget = new QWidget(Options);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setGeometry(QRect(0, 0, 1697, 880));
        sizePolicy.setHeightForWidth(gridWidget->sizePolicy().hasHeightForWidth());
        gridWidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(gridWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_1, 2, 1, 1, 1);

        horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_1, 3, 0, 1, 1);

        Jamendo = new QRadioButton(gridWidget);
        Jamendo->setObjectName(QString::fromUtf8("Jamendo"));
        sizePolicy.setHeightForWidth(Jamendo->sizePolicy().hasHeightForWidth());
        Jamendo->setSizePolicy(sizePolicy);
        Jamendo->setFont(font);
        Jamendo->setCursor(QCursor(Qt::PointingHandCursor));
        Jamendo->setAutoFillBackground(false);
        Jamendo->setIconSize(QSize(200, 200));
        Jamendo->setAutoRepeat(false);

        gridLayout_2->addWidget(Jamendo, 3, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 6, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        Deezer = new QRadioButton(gridWidget);
        Deezer->setObjectName(QString::fromUtf8("Deezer"));
        sizePolicy.setHeightForWidth(Deezer->sizePolicy().hasHeightForWidth());
        Deezer->setSizePolicy(sizePolicy);
        Deezer->setFont(font);
        Deezer->setCursor(QCursor(Qt::PointingHandCursor));
        Deezer->setStyleSheet(QString::fromUtf8("text-align: center;"));
        Deezer->setIconSize(QSize(200, 200));

        gridLayout_2->addWidget(Deezer, 5, 1, 1, 1);

        YouTube = new QRadioButton(gridWidget);
        YouTube->setObjectName(QString::fromUtf8("YouTube"));
        sizePolicy.setHeightForWidth(YouTube->sizePolicy().hasHeightForWidth());
        YouTube->setSizePolicy(sizePolicy);
        YouTube->setFont(font);
        YouTube->setCursor(QCursor(Qt::PointingHandCursor));
        YouTube->setIconSize(QSize(200, 200));

        gridLayout_2->addWidget(YouTube, 4, 1, 1, 1);

        buttonBox = new QDialogButtonBox(gridWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setFont(font);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 7, 1, 1, 1);

        Choix = new QLabel(gridWidget);
        Choix->setObjectName(QString::fromUtf8("Choix"));
        sizePolicy.setHeightForWidth(Choix->sizePolicy().hasHeightForWidth());
        Choix->setSizePolicy(sizePolicy);
        Choix->setFont(font);
        Choix->setAutoFillBackground(false);
        Choix->setStyleSheet(QString::fromUtf8("text-align: center;"));
        Choix->setScaledContents(true);
        Choix->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(Choix, 0, 1, 1, 1);

        Redemarrage = new QLabel(gridWidget);
        Redemarrage->setObjectName(QString::fromUtf8("Redemarrage"));
        sizePolicy.setHeightForWidth(Redemarrage->sizePolicy().hasHeightForWidth());
        Redemarrage->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(Redemarrage, 8, 1, 1, 1);

        Arretoptions = new QToolButton(gridWidget);
        Arretoptions->setObjectName(QString::fromUtf8("Arretoptions"));
        sizePolicy.setHeightForWidth(Arretoptions->sizePolicy().hasHeightForWidth());
        Arretoptions->setSizePolicy(sizePolicy);
        Arretoptions->setMinimumSize(QSize(0, 0));
        Arretoptions->setMaximumSize(QSize(80, 80));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/1-NavigateurWeb/close-alt.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Arretoptions->setIcon(icon);
        Arretoptions->setIconSize(QSize(20, 180));

        gridLayout_2->addWidget(Arretoptions, 0, 2, 1, 1);


        retranslateUi(Options);

        QMetaObject::connectSlotsByName(Options);
    } // setupUi

    void retranslateUi(QWidget *Options)
    {
        Options->setWindowTitle(QApplication::translate("Options", "Options", nullptr));
        Jamendo->setText(QApplication::translate("Options", "Jamendo", nullptr));
        Deezer->setText(QApplication::translate("Options", "Deezer", nullptr));
        YouTube->setText(QApplication::translate("Options", "YouTube", nullptr));
        Choix->setText(QApplication::translate("Options", "Choix du service de musique :", nullptr));
        Redemarrage->setText(QApplication::translate("Options", "(tout changement n\303\251cessite un red\303\251marrage de Easy-Menu)", nullptr));
        Arretoptions->setText(QApplication::translate("Options", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Options: public Ui_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
