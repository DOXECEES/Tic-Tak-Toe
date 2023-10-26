#include "registrationdialog.h"
#include "ui_registrationdialog.h"

RegistrationDialog::RegistrationDialog(std::shared_ptr<Client> client, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationDialog),
    client(client)
{
    ui->setupUi(this);
    // Поумолчанию кнопка ОК недоступна
    ui->buttonBox->buttons().at(0)->setEnabled(false);
    this->setModal(true);


    // Установка красного цвета для метки помощи при вводе логина
    QPalette palletL = ui->label_4->palette();
    palletL.setColor(ui->label_4->backgroundRole(), Qt::red);
    palletL.setColor(ui->label_4->foregroundRole(), Qt::red);
    ui->label_4->setPalette(palletL);

    // Установка красного цвета для метки помощи при вводе пароля
    QPalette palletP = ui->label_3->palette();
    palletP.setColor(ui->label_3->backgroundRole(), Qt::red);
    palletP.setColor(ui->label_3->foregroundRole(), Qt::red);
    ui->label_3->setPalette(palletP);



    // validators
    loginValidator    = new QRegularExpressionValidator(QRegularExpression("[a-zA-Z_]\\w{3,}"),this);
    passwordValidator = new QRegularExpressionValidator(QRegularExpression("\\w{6,}"),this);
    //


    QObject::connect(ui->lineEdit, &QLineEdit::textChanged,
                     this, &RegistrationDialog::GetLoginSlot);
    QObject::connect(ui->lineEdit_2, &QLineEdit::textChanged,
                     this, &RegistrationDialog::GetPasswordSlot);
    QObject::connect(ui->buttonBox, &QDialogButtonBox::rejected,
                     this, &QDialog::reject);
    QObject::connect(ui->buttonBox, &QDialogButtonBox::accepted,
                     this, &RegistrationDialog::SendToServerSlot);
    QObject::connect(this, &RegistrationDialog::SendToServerSignal,
                     client.get(), &Client::SendSlot);
    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &RegistrationDialog::SendToServerSlot);


}


void RegistrationDialog::GetLoginSlot(const QString &text)
{
    int pos = 0;
    if(loginValidator->validate(const_cast<QString&>(text),pos) == QValidator::Acceptable)
    {
        isLoginEnter = true;
        login = std::move(text);
        ui->label_4->setText(" ");
    }
    else
    {
        isLoginEnter = false;
        ui->label_4->setText("Логин должен начинаться с символа подчеркивания\n или буквы латинского алфавита \n"
                             "и может содержать цифры, буквы и символ подчеркивания");
    }
    ui->buttonBox->buttons().at(0)->setEnabled(isOkAvailiable());


}


void RegistrationDialog::GetPasswordSlot(const QString &text)
{
    int pos = 0;
    if(passwordValidator->validate(const_cast<QString&>(text),pos) == QValidator::Acceptable)
    {
        isPasswordEnter = true;
        password = std::move(text);
        ui->label_3->setText(" ");
    }
    else
    {
        isPasswordEnter = false;
        ui->label_3->setText("Пароль должен содержать не менее 6 символов\n цифр, букв или символоа подчеркивания");
    }
    ui->buttonBox->buttons().at(0)->setEnabled(isOkAvailiable());

}


bool RegistrationDialog::isOkAvailiable()
{
    return isLoginEnter && isPasswordEnter ? true : false;
}


void RegistrationDialog::SendToServerSlot()
{
    QByteArray buf;
    buf.push_back(Client::SenderCodes::REGISTRATION_CODE);
    buf.push_back(login.size());
    buf.push_back(login.toUtf8());
    buf.push_back(password.size());
    buf.push_back(password.toUtf8());
    bool res;
    QByteArray ans = SendToServer(buf);
    if(ans[0] == Client::ServerCodes::OK)
    {
        client->SetLogin(login);
        if(ui->checkBox->checkState() == Qt::CheckState::Checked)
        {
            QFile ac(pathToAcount);
            ac.open(QIODevice::WriteOnly | QIODevice::Text);
            ac.write(login.toUtf8() + '\n');
            ac.write(password.toUtf8());
            ac.close();
        }
        emit accept();
    }
    else
    {


        if(sender() == ui->buttonBox)
        {
            QMessageBox box;
            box.setText("Логин занят");
            box.setStandardButtons(QMessageBox::Ok);
            box.setIcon(QMessageBox::Information);
            box.exec();
        }

        if(sender() == ui->pushButton)
        {
            client->SetLogin(login);
            if(ui->checkBox->checkState() == Qt::CheckState::Checked)
            {
                QFile ac(pathToAcount);
                ac.open(QIODevice::WriteOnly | QIODevice::Text);
                ac.write(login.toUtf8() + '\n');
                ac.write(password.toUtf8());
                ac.close();
            }
            emit accept();
        }

    }

}


QByteArray RegistrationDialog::SendToServer(const QByteArray& arr)
{
    emit SendToServerSignal(arr);
    return client->GetData();
}


RegistrationDialog::~RegistrationDialog()
{
    delete loginValidator;
    delete passwordValidator;
    delete ui;
}

const QString RegistrationDialog::pathToAcount = "prof.txt";

