#ifndef SINGUPDIALOG_H
#define SINGUPDIALOG_H

#include "registrationdialog.h"

#include <QDialog>

namespace Ui {
class SingUpDialog;
}

class SingUpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SingUpDialog(std::shared_ptr<Client> client, QWidget *parent = nullptr);
    ~SingUpDialog();

private:
    Ui::SingUpDialog *ui;
    std::shared_ptr<Client> client;
};

#endif // SINGUPDIALOG_H
