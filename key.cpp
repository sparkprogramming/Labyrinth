#include "key.h"

Key::Key()
{
    setRect(4,4,18,18);
}

void Key::setPlayer(Player *p)
{
    player = p;
}


