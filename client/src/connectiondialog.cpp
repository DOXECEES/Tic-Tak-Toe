#include "connectiondialog.h"
#include "ui_connectiondialog.h"
#include "mainmenu.h"


ConnectionDialog::ConnectionDialog(std::shared_ptr<Client>client, std::shared_ptr<Profile> profile, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog),
    client(client),
    profile(profile)
{
    ui->setupUi(this);


    connect(this, &ConnectionDialog::SendToServerSignal, this->client.get(), &Client::SendSlot);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, [this](const QString &text){this->gameId = std::move(text.toInt());});
    connect(ui->pushButton, &QPushButton::clicked, this, &ConnectionDialog::SendSlot);
    connect(MainMenu::menu, &MainMenu::rejected, this, &QDialog::reject);
}


void ConnectionDialog::SendSlot()
{
    // 0 - code
    // 1 - game id
    // 2 - login size
    // 3, end - login
    QByteArray arr;
    arr.push_back(Client::SenderCodes::GAME_CONNECTION_CODE);
    arr.push_back(gameId);
    qDebug() << gameId;
    arr.push_back(profile->GetLogin().size());
    arr.push_back(profile->GetLogin().toUtf8());


    QByteArray ans = SendToServer(arr);


}


QByteArray ConnectionDialog::SendToServer(const QByteArray& arr)
{
    emit SendToServerSignal(arr);
    return client->GetData();
}


ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}
