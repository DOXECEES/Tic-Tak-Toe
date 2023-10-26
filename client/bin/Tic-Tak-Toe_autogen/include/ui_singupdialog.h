/********************************************************************************
** Form generated from reading UI file 'singupdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGUPDIALOG_H
#define UI_SINGUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SingUpDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QCheckBox *checkBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SingUpDialog)
    {
        if (SingUpDialog->objectName().isEmpty())
            SingUpDialog->setObjectName("SingUpDialog");
        SingUpDialog->resize(300, 299);
        verticalLayout = new QVBoxLayout(SingUpDialog);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(SingUpDialog);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(SingUpDialog);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        label_4 = new QLabel(SingUpDialog);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        label_2 = new QLabel(SingUpDialog);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(SingUpDialog);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout->addWidget(lineEdit_2);

        label_3 = new QLabel(SingUpDialog);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        checkBox = new QCheckBox(SingUpDialog);
        checkBox->setObjectName("checkBox");

        verticalLayout->addWidget(checkBox);

        buttonBox = new QDialogButtonBox(SingUpDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SingUpDialog);

        QMetaObject::connectSlotsByName(SingUpDialog);
    } // setupUi

    void retranslateUi(QDialog *SingUpDialog)
    {
        SingUpDialog->setWindowTitle(QCoreApplication::translate("SingUpDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SingUpDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\273\320\276\320\263\320\270\320\275", nullptr));
        label_4->setText(QString());
        label_2->setText(QCoreApplication::translate("SingUpDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_3->setText(QString());
        checkBox->setText(QCoreApplication::translate("SingUpDialog", "\320\227\320\260\320\277\320\276\320\274\320\275\320\270\321\202\321\214 \320\274\320\265\320\275\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SingUpDialog: public Ui_SingUpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGUPDIALOG_H
