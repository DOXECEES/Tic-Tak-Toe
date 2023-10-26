#include "statdialog.h"
#include "ui_statdialog.h"

StatDialog::StatDialog(std::shared_ptr<Client> client ,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatDialog)
{
    ui->setupUi(this);

    QByteArray buf;
    buf.push_back(Client::SenderCodes::REQUEST_STATS);
    buf.push_back(client->GetLogin().size());
    buf.push_back(client->GetLogin().toUtf8());

    connect(client.get(), &Client::SendStatsSignal, this, &StatDialog::SetStats);
    connect(this, &StatDialog::SendToServerSignal, client.get(), &Client::SendSlot);

    emit SendToServerSignal(buf);

}


/// SLOTS



void StatDialog::SetStats(const int wins, const int loses, const int draws)
{
    ui->label->setText("Победы: " + QString::number(wins));
    ui->label_2->setText("Поражения: " + QString::number(loses));
    ui->label_3->setText("Ничьи: " + QString::number(draws));
}

StatDialog::~StatDialog()
{
    delete ui;
}
