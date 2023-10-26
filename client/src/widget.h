#ifndef WIDGET_H
#define WIDGET_H

#include "bitboard.h"
#include "client.h"
#include <QWidget>
#include <QTableWidget>
#include <bitset>
#include <QPushButton>
#include <QMessageBox>

#include "revengedialog.h"
//#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(std::shared_ptr<Client> client, QWidget *parent = nullptr);
    ~Widget();

    inline QString GetSymbol() const {return symbol;};
    void BlockMove(bool var);
    void SetCurrentPlayer();

    inline void SetFirstPlayerLogin(const QString& login) {firstPlayerLogin = std::move(login);};
    inline void SetSecondPlayerLogin(const QString& login) {secondPlayerLogin = std::move(login);};

    inline void SetId(const uint8_t id ) {this->id = std::move(id);};
    inline void SetPlayerWhoMove(const QString& login) {playerWhoMove = std::move(login);};
    void Block();
    void UnBlock();

    void Update();
    void RepeatMove();
    void GameOver();
    void Draw();

    void SetCell(const uint8_t pos);
    void SetEnemyCell(const uint8_t pos);

    QString GetCurrentMoveSymbol();
    inline uint8_t GetGameId() const {return id;};
    inline uint16_t GetBoard() const {return field.GetBoard();};

    //
    void SetLabel2(QString a);

private:
    QByteArray SendToServer(const QByteArray& arr);

private slots:
    void SetText();

signals:
    void SendToServerSignal(const QByteArray &arr);


private:
    std::unordered_map<int, QPushButton*> buttonsMap;
    BitBoard field;
    std::bitset<9> buton;
    uint8_t id;
    QString firstPlayerLogin;
    QString secondPlayerLogin;
    QString playerWhoMove;
    bool isMoveBlock = false;
    QString symbol;
    QString opponentSymbol;
    Ui::Widget *ui;
    std::shared_ptr<Client> client;
    RevengeDialog *revDialog = nullptr;
};

#endif // WIDGET_H
