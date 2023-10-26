#ifndef REGISTRATIONDIALOG_H
#define REGISTRATIONDIALOG_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QString>
#include <QRegularExpressionValidator>
#include <QToolTip>
#include <QMessageBox>
#include <QFile>
#include <QDir>

#include "client.h"


namespace Ui {
class RegistrationDialog;
}

class RegistrationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationDialog(std::shared_ptr<Client> client, QWidget *parent = nullptr);
    ~RegistrationDialog();
    inline const QString& GetPassword() const {return password;};
    inline const QString& GetLogin() const {return login;};
    QByteArray SendToServer(const QByteArray& arr);

private:
    bool isOkAvailiable();

private slots:
    void GetLoginSlot(const QString &text);
    void GetPasswordSlot(const QString &text);
    void SendToServerSlot();


signals:
    void SendToServerSignal(const QByteArray& arr);

private:
    static const QString pathToAcount;
    Ui::RegistrationDialog *ui;
    std::shared_ptr<Client> client;
    bool isLoginEnter = false;
    bool isPasswordEnter = false;
    QString password;
    QString login;
    QValidator *loginValidator;
    QValidator *passwordValidator;
};

#endif // REGISTRATIONDIALOG_H
