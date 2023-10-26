#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <QLineEdit>

#include "client.h"
#include "profile.h"
#include "widget.h"

namespace Ui {
class ConnectionDialog;
}

class ConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionDialog(std::shared_ptr<Client>client, std::shared_ptr<Profile> profile, QWidget *parent = nullptr);
    ~ConnectionDialog();
    QByteArray SendToServer(const QByteArray& arr);


signals:
    void SendToServerSignal(const QByteArray &arr);

private slots:

    void SendSlot();

private:
    Ui::ConnectionDialog *ui;
    std::shared_ptr<Client> client;
    std::shared_ptr<Profile> profile;
    uint8_t gameId;

};

#endif // CONNECTIONDIALOG_H
