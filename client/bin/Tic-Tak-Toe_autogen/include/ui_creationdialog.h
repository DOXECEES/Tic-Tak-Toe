/********************************************************************************
** Form generated from reading UI file 'creationdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATIONDIALOG_H
#define UI_CREATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CreationDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *CreationDialog)
    {
        if (CreationDialog->objectName().isEmpty())
            CreationDialog->setObjectName("CreationDialog");
        CreationDialog->resize(400, 300);
        gridLayout = new QGridLayout(CreationDialog);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(CreationDialog);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(CreationDialog);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton = new QPushButton(CreationDialog);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);


        retranslateUi(CreationDialog);

        QMetaObject::connectSlotsByName(CreationDialog);
    } // setupUi

    void retranslateUi(QDialog *CreationDialog)
    {
        CreationDialog->setWindowTitle(QCoreApplication::translate("CreationDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CreationDialog", "id:  ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CreationDialog", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \321\201\320\265\321\200\320\262\320\265\321\200", nullptr));
        pushButton->setText(QCoreApplication::translate("CreationDialog", "\320\241\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214 ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreationDialog: public Ui_CreationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATIONDIALOG_H
