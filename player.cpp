#include "player.h"
#include <QDebug>
#include "text.h"
#include "door.h"
#include "maze.h"


void Player::setLeft(Player *p)
{
    leftLine = p;
}
void Player::setRight(Player *p)
{
    rightLine = p;
}
void Player::setUp(Player *p)
{
    upLine = p;
}
void Player::setDown(Player *p)
{
    downLine = p;
}

void Player::setVictory(Player *p)
{
    victory = p;
}

void Player::setDoor(Player *p)
{
    door = p;
}

void Player::setKey(Player *p)
{
    key = p;
}

bool Player::isColliding(Player *)
{
    bool collision = false;
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Maze) || typeid(*(colliding_items[i])) == typeid(Door))
        {
            collision = true;
        }
    }
    return collision;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(!(leftLine->isColliding(leftLine)))
        {
            if(pos().x() > 0)
            {
                setPos(x()-25,y());

            }
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(!(rightLine->isColliding(rightLine)))
        {
            if(pos().x() < 725)
            {
                setPos(x()+25,y());
            }
        }
    }
    else if(event->key() == Qt::Key_Up)
    {
        if(!(upLine->isColliding(upLine)))
        {
            if(pos().y() > 0)
            {
                setPos(x(),y()-25);
            }
        }
    }
    else if(event->key() == Qt::Key_Down)
    {
        if(!(downLine->isColliding(downLine)))
        {
             if(pos().y() < 725)
             {
                setPos(x(),y()+25);
             }
        }
    }
    if(collidesWithItem(key))
    {
        hasKey = true;
        delete key;
        setKey(NULL);
        return;
    }
    if(rightLine->collidesWithItem(door))
    {
        if(hasKey)
        {
            hasKey = false;
            delete door;
            setDoor(NULL);
            return;
        }
    }
    if(rightLine->collidesWithItem(victory))
    {
        delete victory;
        setVictory(NULL);

        return;
    }


}








