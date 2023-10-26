#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QDialog>
#include <QMessageBox>
#include <QFile>

#include "registrationdialog.h"
#include "creationdialog.h"
#include "database.h"
#include "connectiondialog.h"
#include "client.h"
#include "profile.h"
#include "statdialog.h"
#include "singupdialog.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(std::shared_ptr<Client>client, QWidget *parent = nullptr);
    ~MainMenu();
    static void ShowMenu(bool var);
    void ShowGameField();
    inline void SetId(uint8_t gameId) {gameId = std::move(gameId);} ;

    static inline Widget* GetWidget() {return w;};
    static inline void DelWidget() {delete w; w = nullptr;};
    static MainMenu* menu;


private slots:
    void ShowRegistrationDialog();
    void ShowCreationDialog();
    void ShowConnectionDialog();
    void ShowStatisticsDialog();
signals:
    void DBRequestRecording(const QString& login, const QString& password);
    void rejected();

private:

    RegistrationDialog *rDialog = nullptr;
    CreationDialog *cDialog = nullptr;
    ConnectionDialog *con = nullptr;
    StatDialog *statDialog = nullptr;

    uint8_t gameId;
    Ui::MainMenu *ui;
    std::shared_ptr<Client> client;
    std::shared_ptr<Profile> profile;
    static Widget *w;
};

#endif // MAINMENU_H
