#ifndef STATDIALOG_H
#define STATDIALOG_H

#include <QDialog>

#include "client.h"

namespace Ui {
class StatDialog;
}

class StatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StatDialog(std::shared_ptr<Client> client, QWidget *parent = nullptr);
    ~StatDialog();
    //void SendToServer(const QByteArray& arr);

public slots:
    void SetStats(const int wins, const int loses, const int draws);

signals:
    void SendToServerSignal(const QByteArray& arr);

private:
    Ui::StatDialog *ui;
    std::shared_ptr<Client> client;
};

#endif // STATDIALOG_H
