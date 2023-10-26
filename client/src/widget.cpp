#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(std::shared_ptr<Client> client, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , client(client)
{
    ui->setupUi(this);

    //buttonsMap.insert(std::make_pair<int, QPushButton*>(1, ui->pushButton));
    buttonsMap[0] = ui->pushButton;
    buttonsMap[1] = ui->pushButton_2;
    buttonsMap[2] = ui->pushButton_3;
    buttonsMap[3] = ui->pushButton_4;
    buttonsMap[4] = ui->pushButton_5;
    buttonsMap[5] = ui->pushButton_6;
    buttonsMap[6] = ui->pushButton_7;
    buttonsMap[7] = ui->pushButton_8;
    buttonsMap[8] = ui->pushButton_9;


    QObject::connect(ui->pushButton,&QPushButton::clicked ,this,&Widget::SetText);
    QObject::connect(ui->pushButton_2,&QPushButton::clicked ,this,&Widget::SetText);
    QObject::connect(ui->pushButton_3,&QPushButton::clicked ,this,&Widget::SetText);
    QObject::connect(ui->pushButton_4,&QPushButton::clicked ,this,&Widget::SetText);
    QObject::connect(ui->pushButton_5,&QPushButton::clicked ,this,&Widget::SetText);
    QObject::connect(ui->pushButton_6,&QPushButton::clicked ,this,&Widget::SetText);
    QObject::connect(ui->pushButton_7,&QPushButton::clicked ,this,&Widget::SetText);
    QObject::connect(ui->pushButton_8,&QPushButton::clicked ,this,&Widget::SetText);
    QObject::connect(ui->pushButton_9,&QPushButton::clicked ,this,&Widget::SetText);
    QObject::connect(this, &Widget::SendToServerSignal, client.get(), &Client::SendSlot);

}

void Widget::SetText()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    uint8_t pos = button->accessibleName().toInt() - 1;

    QByteArray arr;
    arr.push_back(Client::SenderCodes::CHEAK_MOVE);
    arr.push_back(id);
    arr.push_back(pos);
    //qDebug() << arr;
    SendToServer(arr);
}


void Widget::GameOver()
{

    //SetCurrentPlayer();
    QMessageBox box;
    box.setText("Победа игрока " + playerWhoMove);
    box.setStandardButtons(QMessageBox::Ok);
    box.setIcon(QMessageBox::Information);
    box.exec();

    revDialog = new RevengeDialog(client,GetGameId(), this);
    revDialog->show();
}


void Widget::SetCell(const uint8_t pos)
{
    field.SetPosition(pos);
    buttonsMap[pos]->setText("X");
    buttonsMap[pos]->setEnabled(false);

}


void Widget::SetEnemyCell(const uint8_t pos)
{
    buttonsMap[pos]->setText("O");
    buttonsMap[pos]->setEnabled(false);
}


void Widget::RepeatMove()
{
    QMessageBox box;
    box.setText("Попробуйте снова");
    box.setStandardButtons(QMessageBox::Ok);
    box.setIcon(QMessageBox::Critical);
    box.exec();
}


void Widget::Draw()
{
    QMessageBox box;
    box.setText("Ничья");
    box.setStandardButtons(QMessageBox::Ok);
    box.setIcon(QMessageBox::Information);
    box.exec();
}


void Widget::SetLabel2(QString a)
{
    ui->label_2->setText(a);
}

//
QByteArray Widget::SendToServer(const QByteArray& arr)
{
    emit SendToServerSignal(arr);
    return client->GetData();
}


void Widget::SetCurrentPlayer()
{
    ui->label->setText("Ход игрока: " + playerWhoMove);
}


void Widget::Update()
{

}


void Widget::Block()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);

    if(playerWhoMove == secondPlayerLogin)
    {
       playerWhoMove = firstPlayerLogin;
    }
    else
    {
       playerWhoMove = secondPlayerLogin;
    }
    //SetCurrentPlayer();

}


void Widget::UnBlock()
{

    for(int i = 0; i < 9; i++)
    {
        if(buttonsMap[i]->text() == "")
           buttonsMap[i]->setEnabled(true);

    }

    if(playerWhoMove == secondPlayerLogin)
    {
        playerWhoMove = firstPlayerLogin;
    }
    else
    {
        playerWhoMove = secondPlayerLogin;
    }
    //SetCurrentPlayer();

}





Widget::~Widget()
{
    delete ui;
}



//bool Widget::isCross = true;
