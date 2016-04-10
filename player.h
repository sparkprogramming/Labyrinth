#ifndef PLAYER_H
#define PLAYER_H

#include <QList>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QTextItem>


class Player: public QObject, public QGraphicsRectItem

{   Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);

    bool hasKey = false;

    Player *player;
    void setPlayer(Player*);

    bool isColliding(Player*);
    bool isCollidingDoor(Player*);

    Player *leftLine;
    Player *rightLine;
    Player *upLine;
    Player *downLine;

    void setLeft(Player*);
    void setRight(Player*);
    void setUp(Player*);
    void setDown(Player*);

    Player *victory;
    Player *door;
    Player *key;

    void setVictory(Player*);
    void setDoor(Player*);
    void setKey(Player*);

};

#endif // PLAYER_H
