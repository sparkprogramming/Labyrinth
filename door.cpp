#include "door.h"

Door::Door()
{
    setRect(0,0,25,25);
}

void Door::setPlayer(Player *p)
{
    player = p;
}
