#include "creationdialog.h"
#include "ui_creationdialog.h"
#include "mainmenu.h"

#include <thread>


CreationDialog::CreationDialog(std::shared_ptr<Client>client, std::shared_ptr<Profile> profile, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreationDialog),
    profile(profile),
    client(client)
{
    ui->setupUi(this);
    this->setModal(true);


    connect(ui->pushButton_2, &QPushButton::clicked, this, &QDialog::reject);
    connect(ui->pushButton, &QPushButton::clicked,this, &CreationDialog::CopyToClipboardSlot);
    connect(this, &CreationDialog::SendToServerSignal, this->client.get(), &Client::SendSlot);
    connect(MainMenu::menu, &MainMenu::rejected, this, &QDialog::reject);
    //
    QByteArray arr;
    arr.push_back(Client::SenderCodes::GAME_CREATION_CODE);
    arr.push_back(profile->GetLogin().size());
    arr.push_back(profile->GetLogin().toUtf8());


    QByteArray answer = SendToServer(arr);

    if(answer[0] == Client::ServerCodes::CREATED_SUCCESS)
    {
        id = static_cast<uint8_t>(answer[1]);
        SetID();

    }
    else
    {
        qDebug() << "NO GAME";
    }

}


QByteArray CreationDialog::SendToServer(const QByteArray& arr)
{
    emit SendToServerSignal(arr);
    return client->GetData();
}


void CreationDialog::SetID()
{
    ui->label->setText(QString::number(id));
}


void CreationDialog::CopyToClipboardSlot()
{
    QApplication::clipboard()->setText(QString::number(id));
}


CreationDialog::~CreationDialog()
{
    delete ui;
}
