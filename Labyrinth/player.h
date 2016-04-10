#ifndef PLAYER_H
#define PLAYER_H

#include <QList>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include "maze.h"


class Player: public QObject, public QGraphicsRectItem
{   Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);

    Player *player;
    void setPlayer(Player*);

    bool isColliding(Player*);

    Player *leftLine;
    Player *rightLine;
    Player *upLine;
    Player *downLine;

    void setLeft(Player*);
    void setRight(Player*);
    void setUp(Player*);
    void setDown(Player*);

};

#endif // PLAYER_H
