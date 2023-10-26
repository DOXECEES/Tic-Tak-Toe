#ifndef REVENGEDIALOG_H
#define REVENGEDIALOG_H

#include <QDialog>

#include "client.h"

namespace Ui {
class RevengeDialog;
}

class RevengeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RevengeDialog(std::shared_ptr<Client> client, uint8_t gameId, QWidget *parent = nullptr);
    ~RevengeDialog();

private slots:
    void AcceptSlot();
    void RejectSlot();

signals:
    void SendToServerSignal(const QByteArray& arr);

private:
    Ui::RevengeDialog *ui;
    std::shared_ptr<Client> client;
    uint8_t gameId;
};

#endif // REVENGEDIALOG_H
