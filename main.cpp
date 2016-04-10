#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTimer>
#include <QImage>
#include "player.h"
#include "maze.h"
#include "line.h"
#include "game.h"
#include "door.h"
#include "key.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,750,750);

    QGraphicsView *view = new QGraphicsView(scene);
    view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(750,750);

    QImage *image = new QImage(":/images/floor.png");
    QBrush *brush = new QBrush(*image);
    view->setBackgroundBrush(*brush);

    view->show();
    // bring in file to get the maze map matrix
    QVector<QVector<int>> mazemap;
    QFile mazeFile(":/maps/mazetest.txt");
    mazeFile.open(QIODevice::ReadOnly);

    QTextStream textStream(&mazeFile);
    QString line;

    while (!textStream.atEnd()) // put the maze map into the matrix
    {
        QVector<int> row;
        line = textStream.readLine();
        for(int i = 0; i < line.size(); i++)
        {
            if (line[i] != ' ')
            {
                if(line[i] == '0')
                {
                    row.push_back(0);
                }
                else if(line[i] == '1')
                {
                    row.push_back(1);
                }
                else if(line[i] == '2')
                {
                    row.push_back(2);
                }
                else if(line[i] == '3')
                {
                    row.push_back(3);
                }
                else if (line[i] == '4')
                {
                    row.push_back(4);
                }
                else if (line[i] == '5')
                {
                    row.push_back(5);
                }
            }
        }
        mazemap.push_back(row);
    }
    mazeFile.close();

    // initialize the character and walls

    Player *player = new Player();
    player->setRect(2,2,21,21);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    for(int i = mazemap.size() - 1; i >= 0; --i)
    {
        for(int j = mazemap[i].size() - 1; j >= 0; --j)
        {
            if (mazemap[i][j] == 1)
            {
                Maze *wall = new Maze();
                wall->setPixmap(QPixmap(":/images/wall.jpg"));
                scene->addItem(wall);
                wall->setPos(j*25,i*25);

            }
            else if (mazemap[i][j] == 2)
            {
                   scene->addItem(player);
                   player->setPos(j*25,i*25);
                   player->setBrush(QBrush(QColor(250,0,0)));

                   Line *left = new Line();
                   left->setPlayer(player);
                   left->setRect(-12,12,25,1);
                   scene->addItem(left);
                   left->QGraphicsRectItem::setPos(j*25,i*25);
                   left->QGraphicsRectItem::setOpacity(0);
                   player->setLeft(left);

                   Line *right = new Line();
                   right->setPlayer(player);
                   right->setRect(12,12,25,1);
                   scene->addItem(right);
                   right->QGraphicsRectItem::setPos(j*25,i*25);
                   right->QGraphicsRectItem::setOpacity(0);
                   player->setRight(right);

                   Line *up = new Line();
                   up->setPlayer(player);
                   up->setRect(12,-12,1,25);
                   scene->addItem(up);
                   up->QGraphicsRectItem::setPos(j*25,i*25);
                   up->QGraphicsRectItem::setOpacity(0);
                   player->setUp(up);

                   Line *down = new Line();
                   down->setPlayer(player);
                   down->setRect(12,12,1,25);
                   scene->addItem(down);
                   down->QGraphicsRectItem::setPos(j*25,i*25);
                   down->QGraphicsRectItem::setOpacity(0);
                   player->setDown(down);
            }
            else if(mazemap[i][j] == 3)
            {
                Game *victoryTile = new Game();
                victoryTile->setPos(j*25,i*25);
                victoryTile->setBrush(QBrush(QColor(250,0,250)));
                scene->addItem(victoryTile);
                victoryTile->setPlayer(player);
                player->setVictory(victoryTile);
            }
            else if(mazemap[i][j] == 4)
            {
                Door *door = new Door();
                door->setPlayer(player);
                door->setBrush(QBrush(QColor(0,0,250)));
                scene->addItem(door);
                door->setPos(j*25,i*25);
                player->setDoor(door);

            }
            else if(mazemap[i][j] == 5)
            {
                Key *key = new Key();
                key->setPlayer(player);
                key->setBrush(QBrush(QColor(0,250,0)));
                scene->addItem(key);
                key->setPos(j*25,i*25);
                player->setKey(key);

            }
        }
    }



    return a.exec();
}
