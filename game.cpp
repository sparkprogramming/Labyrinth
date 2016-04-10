#include "game.h"


Game::Game()
{
    setRect(0,0,25,25);
}

void Game::setPlayer(Player *p)
{
    player = p;
}
