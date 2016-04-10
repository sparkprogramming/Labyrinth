#ifndef DOOR_H
#define DOOR_H

#include "player.h"

class Door: public Player
{
public:
    Door();
    Player *player;
    void setPlayer(Player*);
};

#endif // DOOR_H
