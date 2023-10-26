#include "singupdialog.h"
#include "ui_singupdialog.h"

SingUpDialog::SingUpDialog(std::shared_ptr<Client> client, QWidget *parent) :
    client(client),
    ui(new Ui::SingUpDialog)
{
    ui->setupUi(this);




}

SingUpDialog::~SingUpDialog()
{
    delete ui;
}
