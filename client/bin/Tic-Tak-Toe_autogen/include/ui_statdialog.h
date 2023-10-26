/********************************************************************************
** Form generated from reading UI file 'statdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATDIALOG_H
#define UI_STATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StatDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *StatDialog)
    {
        if (StatDialog->objectName().isEmpty())
            StatDialog->setObjectName("StatDialog");
        StatDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(StatDialog);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(StatDialog);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(20);
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(StatDialog);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(StatDialog);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);


        retranslateUi(StatDialog);

        QMetaObject::connectSlotsByName(StatDialog);
    } // setupUi

    void retranslateUi(QDialog *StatDialog)
    {
        StatDialog->setWindowTitle(QCoreApplication::translate("StatDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("StatDialog", "\320\237\320\276\320\261\320\265\320\264\321\213:", nullptr));
        label_2->setText(QCoreApplication::translate("StatDialog", "\320\237\320\276\321\200\320\260\320\266\320\265\320\275\320\270\321\217:", nullptr));
        label_3->setText(QCoreApplication::translate("StatDialog", "\320\235\320\270\321\207\321\214\320\270:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatDialog: public Ui_StatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATDIALOG_H
