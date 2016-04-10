#ifndef GAME_H
#define GAME_H

#include "player.h"

class Game: public Player
{
public:
    Game();
    Player *player;
    void setPlayer(Player*);

};

#endif // GAME_H
