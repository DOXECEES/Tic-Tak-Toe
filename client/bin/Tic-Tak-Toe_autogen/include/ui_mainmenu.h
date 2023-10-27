/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_6;
    QGridLayout *gridLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_2;
    QPushButton *pushButton_4;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pushButton_5;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_2;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName("MainMenu");
        MainMenu->resize(800, 600);
        verticalLayout = new QVBoxLayout(MainMenu);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(MainMenu);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(45);
        font.setStyleStrategy(QFont::PreferDefault);
        label->setFont(font);
        label->setPixmap(QPixmap(QString::fromUtf8("cross2.png")));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);


        verticalLayout->addLayout(verticalLayout_2);

        verticalSpacer_6 = new QSpacerItem(40, 80, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pushButton_3 = new QPushButton(MainMenu);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout->addWidget(pushButton_3, 8, 1, 1, 1);

        pushButton = new QPushButton(MainMenu);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 4, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 9, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 7, 1, 1, 1);

        label_2 = new QLabel(MainMenu);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 12, 1, 1, 1);

        pushButton_4 = new QPushButton(MainMenu);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout->addWidget(pushButton_4, 10, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 11, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(MainMenu);
        pushButton_5->setObjectName("pushButton_5");

        gridLayout->addWidget(pushButton_5, 0, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 5, 1, 1, 1);

        pushButton_2 = new QPushButton(MainMenu);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 6, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "Form", nullptr));
        label->setText(QCoreApplication::translate("MainMenu", "\320\232\320\240\320\225\320\241\320\242\320\230\320\232\320\230-\320\235\320\236\320\233\320\230\320\232\320\230", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainMenu", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
        pushButton->setText(QCoreApplication::translate("MainMenu", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\270\320\263\321\200\321\203", nullptr));
        label_2->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("MainMenu", "\320\222\321\213\320\271\321\202\320\270 \320\270\320\267 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\260", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainMenu", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainMenu", "\320\237\321\200\320\270\321\201\320\276\320\265\320\264\320\270\320\275\320\270\321\202\321\201\321\217 \320\272 \320\270\320\263\321\200\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
