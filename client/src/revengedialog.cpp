#include "revengedialog.h"
#include "ui_revengedialog.h"

RevengeDialog::RevengeDialog(std::shared_ptr<Client> client, uint8_t gameId, QWidget *parent) :
    QDialog(parent),
     ui(new Ui::RevengeDialog)
    ,client(client)
    ,gameId(gameId)
{
    ui->setupUi(this);


    connect(ui->pushButton, &QPushButton::clicked, this, &RevengeDialog::AcceptSlot);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &RevengeDialog::RejectSlot);
    connect(this, &RevengeDialog::SendToServerSignal, client.get(), &Client::SendSlot);
}


void RevengeDialog::AcceptSlot()
{
    // send to server
    // server send start game

    QByteArray arr;
    arr.push_back(Client::SenderCodes::REQUEST_REVENGE);
    arr.push_back(gameId);
    arr.push_back(true);
    emit this->SendToServerSignal(arr);


}


void RevengeDialog::RejectSlot()
{
    QByteArray arr;
    arr.push_back(Client::SenderCodes::REQUEST_REVENGE);
    arr.push_back(gameId);
    arr.push_back(false);
    emit this->SendToServerSignal(arr);

}


RevengeDialog::~RevengeDialog()
{
    delete ui;
}
