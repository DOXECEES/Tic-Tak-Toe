#include "mainmenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("icon.ico"));
    auto client = std::make_shared<Client>(new Client());
    MainMenu *menu = new MainMenu(client);
    menu->show();
    return a.exec();
}
