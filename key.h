#ifndef KEY_H
#define KEY_H

#include "player.h"

class Key: public Player
{
public:
    Key();
    Player *player;
    void setPlayer(Player*);
};

#endif // KEY_H
