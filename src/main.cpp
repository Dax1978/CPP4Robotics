#include <QtWidgets/QApplication>
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Game game;
    // Можно и здесь заголовок установить
    // game.setWindowTitle("Snake");
    game.show();

    return app.exec();
}