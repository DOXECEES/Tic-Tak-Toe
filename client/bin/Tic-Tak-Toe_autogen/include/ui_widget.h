/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_9;
    QPushButton *pushButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(953, 600);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setScaledContents(true);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pushButton_7 = new QPushButton(Widget);
        pushButton_7->setObjectName("pushButton_7");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(75);
        pushButton_7->setFont(font);

        gridLayout->addWidget(pushButton_7, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName("pushButton_2");
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setFont(font);

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName("pushButton_5");
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setFont(font);

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_9 = new QPushButton(Widget);
        pushButton_9->setObjectName("pushButton_9");
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        pushButton_9->setFont(font);
        pushButton_9->setIconSize(QSize(200, 200));
        pushButton_9->setAutoDefault(false);

        gridLayout->addWidget(pushButton_9, 2, 2, 1, 1);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setFont(font);

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setFont(font);
        pushButton_6->setAutoDefault(false);
        pushButton_6->setFlat(false);

        gridLayout->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton_8 = new QPushButton(Widget);
        pushButton_8->setObjectName("pushButton_8");
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setFont(font);

        gridLayout->addWidget(pushButton_8, 2, 1, 1, 1);

        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName("pushButton_4");
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setFont(font);

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName("pushButton_3");
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setFont(font);

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        retranslateUi(Widget);

        pushButton_6->setDefault(false);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\320\245\320\276\320\264 \320\270\320\263\321\200\320\276\320\272\320\260 :", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_7->setAccessibleName(QCoreApplication::translate("Widget", "7", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_7->setText(QString());
#if QT_CONFIG(accessibility)
        pushButton_2->setAccessibleName(QCoreApplication::translate("Widget", "2", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_2->setText(QString());
#if QT_CONFIG(accessibility)
        pushButton_5->setAccessibleName(QCoreApplication::translate("Widget", "5", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_5->setText(QString());
#if QT_CONFIG(accessibility)
        pushButton_9->setAccessibleName(QCoreApplication::translate("Widget", "9", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_9->setText(QString());
#if QT_CONFIG(accessibility)
        pushButton->setAccessibleName(QCoreApplication::translate("Widget", "1", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton->setText(QString());
#if QT_CONFIG(accessibility)
        pushButton_6->setAccessibleName(QCoreApplication::translate("Widget", "6", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_6->setText(QString());
#if QT_CONFIG(accessibility)
        pushButton_8->setAccessibleName(QCoreApplication::translate("Widget", "8", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_8->setText(QString());
#if QT_CONFIG(accessibility)
        pushButton_4->setAccessibleName(QCoreApplication::translate("Widget", "4", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_4->setText(QString());
#if QT_CONFIG(accessibility)
        pushButton_3->setAccessibleName(QCoreApplication::translate("Widget", "3", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
