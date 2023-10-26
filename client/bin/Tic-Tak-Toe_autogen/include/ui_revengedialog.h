/********************************************************************************
** Form generated from reading UI file 'revengedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVENGEDIALOG_H
#define UI_REVENGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_RevengeDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_4;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *RevengeDialog)
    {
        if (RevengeDialog->objectName().isEmpty())
            RevengeDialog->setObjectName("RevengeDialog");
        RevengeDialog->resize(373, 165);
        gridLayout = new QGridLayout(RevengeDialog);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 3, 1, 1, 1);

        label = new QLabel(RevengeDialog);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(17);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 2, 0, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 3, 0, 1, 1);

        pushButton_2 = new QPushButton(RevengeDialog);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 5, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 7, 1, 1, 1);

        pushButton = new QPushButton(RevengeDialog);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 0, 1, 1);


        retranslateUi(RevengeDialog);

        QMetaObject::connectSlotsByName(RevengeDialog);
    } // setupUi

    void retranslateUi(QDialog *RevengeDialog)
    {
        RevengeDialog->setWindowTitle(QCoreApplication::translate("RevengeDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RevengeDialog", "\320\222\320\267\321\217\321\202\321\214 \321\200\320\265\320\262\320\260\320\275\321\210", nullptr));
        pushButton_2->setText(QCoreApplication::translate("RevengeDialog", "\320\235\320\265\321\202", nullptr));
        pushButton->setText(QCoreApplication::translate("RevengeDialog", "\320\224\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RevengeDialog: public Ui_RevengeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVENGEDIALOG_H
