#ifndef LINE_H
#define LINE_H

#include <QGraphicsRectItem>
#include <QTimer>
#include <QList>
#include "player.h"
#include "maze.h"

class Line: public Player
{   Q_OBJECT
public:
    Line();
    Player *player;
    void setPlayer(Player*);

private slots:
    void move();
};

#endif // LINE_H
