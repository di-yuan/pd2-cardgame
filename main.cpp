#include <QApplication>
#include "game.h"

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();
    game->setFixedSize(375,667);
    game->Init();

    return a.exec();
}
