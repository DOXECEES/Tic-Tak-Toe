/********************************************************************************
** Form generated from reading UI file 'registrationdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONDIALOG_H
#define UI_REGISTRATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegistrationDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QCheckBox *checkBox;
    QVBoxLayout *verticalLayout;
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;

    void setupUi(QDialog *RegistrationDialog)
    {
        if (RegistrationDialog->objectName().isEmpty())
            RegistrationDialog->setObjectName("RegistrationDialog");
        RegistrationDialog->resize(330, 302);
        verticalLayout_2 = new QVBoxLayout(RegistrationDialog);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(RegistrationDialog);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(RegistrationDialog);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_2->addWidget(lineEdit);

        label_4 = new QLabel(RegistrationDialog);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);

        label_2 = new QLabel(RegistrationDialog);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(RegistrationDialog);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout_2->addWidget(lineEdit_2);

        label_3 = new QLabel(RegistrationDialog);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        checkBox = new QCheckBox(RegistrationDialog);
        checkBox->setObjectName("checkBox");

        verticalLayout_2->addWidget(checkBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        buttonBox = new QDialogButtonBox(RegistrationDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        pushButton = new QPushButton(RegistrationDialog);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(RegistrationDialog);

        QMetaObject::connectSlotsByName(RegistrationDialog);
    } // setupUi

    void retranslateUi(QDialog *RegistrationDialog)
    {
        RegistrationDialog->setWindowTitle(QCoreApplication::translate("RegistrationDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RegistrationDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\273\320\276\320\263\320\270\320\275", nullptr));
        label_4->setText(QString());
        label_2->setText(QCoreApplication::translate("RegistrationDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_3->setText(QString());
        checkBox->setText(QCoreApplication::translate("RegistrationDialog", "\320\227\320\260\320\277\320\276\320\274\320\275\320\270\321\202\321\214 \320\274\320\265\320\275\321\217", nullptr));
        pushButton->setText(QCoreApplication::translate("RegistrationDialog", "\320\222\320\276\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationDialog: public Ui_RegistrationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONDIALOG_H
