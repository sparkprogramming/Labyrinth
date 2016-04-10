#include "line.h"

Line::Line()
{
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(25);
}

void Line::setPlayer(Player *p)
{
    player = p;
}

void Line::move()
{
    setPos(player->x(),player->y());

}

