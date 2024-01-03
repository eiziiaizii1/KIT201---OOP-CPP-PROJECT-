
#include "Game.h"

int main()
{
    //Game object initialization
    Game game;


    //Main Game Loop
    while (game.isRunning()) {
        game.pollEvents();
        game.update();
        game.render();
    }

    return 0;
}