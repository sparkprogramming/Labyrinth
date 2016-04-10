#include "player.h"
#include <QDebug>

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

bool Player::isColliding(Player *)
{
    bool collision = false;
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Maze))
        {
            qDebug() << "should work";
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
}








