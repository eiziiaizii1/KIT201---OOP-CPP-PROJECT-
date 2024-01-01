
#include "Game.h"

int main()
{
    //Game object initialization
    
    

    Game game;


    //Main Game Loop
    while (game.isRunning()) {
        game.update();
        game.render();
    }

    return 0;
}