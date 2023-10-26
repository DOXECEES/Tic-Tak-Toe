#ifndef CREATIONDIALOG_H
#define CREATIONDIALOG_H

#include <QDialog>
#include <QRandomGenerator64>
#include <QString>
#include <QClipboard>

#include <QByteArray>
#include <QTimer>

#include "client.h"
#include "profile.h"
#include "widget.h"

namespace Ui {
class CreationDialog;
}

class CreationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreationDialog(std::shared_ptr<Client>client, std::shared_ptr<Profile> profile, QWidget *parent = nullptr);
    ~CreationDialog();
    QByteArray SendToServer(const QByteArray& arr);

private slots:
    void CopyToClipboardSlot();
signals:
    void SendToServerSignal(const QByteArray &arr);


private:
    void SetID();

private:
    Ui::CreationDialog *ui;
    std::shared_ptr<Client> client;
    std::shared_ptr<Profile> profile;
    uint64_t id;

};

#endif // CREATIONDIALOG_H
