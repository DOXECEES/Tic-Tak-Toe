#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(std::shared_ptr<Client>client, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu),
    client(client)
{
    menu = this;
    ui->setupUi(this);
    QFile prof("prof.txt");
    if (prof.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&prof);

        QString login = in.readLine();
        QString password = in.readLine();

        if(!login.isEmpty() && !password.isEmpty())
        {
            profile = std::make_shared<Profile>(client, login, password);
            if(profile->isVerified())
            {
                ui->label_2->setText("Пользователь "+ profile->GetLogin());
                client->SetLogin(profile->GetLogin());
                ui->pushButton_5->hide();
            }
            else
            {
                qDebug() << "Not aut" << login << password;
                profile = std::make_shared<Profile>(client);
            }
        }
        else
            profile = std::make_shared<Profile>(client);

        prof.close();
    }
    else
    {
        qDebug() << "Not open";
        profile = std::make_shared<Profile>(client);
    }

    connect(ui->pushButton_4, &QPushButton::clicked, this, &QApplication::quit );
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainMenu::ShowRegistrationDialog);
    connect(ui->pushButton,   &QPushButton::clicked, this, &MainMenu::ShowCreationDialog);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainMenu::ShowConnectionDialog);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainMenu::ShowStatisticsDialog);
    connect(client.get(), &Client::ShowFieldSignal, this, &MainMenu::ShowGameField);
}

MainMenu::~MainMenu()
{
    delete ui;
}

//
// SLOTS
//

void MainMenu::ShowRegistrationDialog()
{
    rDialog = new RegistrationDialog(client, this);
    if(rDialog->exec() == QDialog::Accepted)
    {
        profile = std::make_shared<Profile>(client, rDialog->GetLogin(), rDialog->GetPassword());
        ui->label_2->setText("Пользователь "+ profile->GetLogin());
        ui->pushButton_5->hide();
    }
    delete rDialog;
}


void MainMenu::ShowCreationDialog()
{
    if(!profile->isVerified())
    {
        QMessageBox box;
        box.setText("Вы не авторизованны");
        box.setStandardButtons(QMessageBox::Ok);
        box.setIcon(QMessageBox::Critical);
        box.exec();
        return;
    }

    cDialog = new CreationDialog(client, profile, this);
    if(cDialog->exec() == QDialog::Rejected)
    {
        delete cDialog;
    }
}


void MainMenu::ShowConnectionDialog()
{
    if(!profile->isVerified())
    {
        QMessageBox box;
        box.setText("Вы не авторизованны");
        box.setStandardButtons(QMessageBox::Ok);
        box.setIcon(QMessageBox::Critical);
        box.exec();
        return;
    }

    con = new ConnectionDialog(client, profile, this);
    if(con->exec() == QDialog::Rejected)
    {
        delete con;
    }
}


void MainMenu::ShowStatisticsDialog()
{
    if(!profile->isVerified())
    {
        QMessageBox box;
        box.setText("Вы не авторизованны");
        box.setStandardButtons(QMessageBox::Ok);
        box.setIcon(QMessageBox::Critical);
        box.exec();
        return;
    }

    statDialog = new StatDialog(client, this);
    if(statDialog->exec() == QDialog::Rejected)
    {
        delete statDialog;
    }
}


void MainMenu::ShowGameField()
{
    w = new Widget(client);
    w->show();
    this->hide();
    if(con != nullptr)
        emit this->rejected();
    if(cDialog != nullptr)
        emit this->rejected();
}




Widget* MainMenu::w = nullptr;
MainMenu* MainMenu::menu = nullptr;
