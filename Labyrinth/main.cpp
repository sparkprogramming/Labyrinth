#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include "player.h"
#include "maze.h"
#include "line.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTimer>


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
            }
        }
        mazemap.push_back(row);
    }
    mazeFile.close();

    // initialize the character and walls

    Player *player = new Player();
    player->setRect(0,0,25,25);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    for(int i = mazemap.size() - 1; i >= 0; --i)
    {
        for(int j = mazemap[i].size() - 1; j >= 0; --j)
        {
            if (mazemap[i][j] == 1)
            {
                Maze *wall = new Maze();
                wall->setBrush(QBrush(QColor(200,200,200)));
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
                   left->setPos(j*25,i*25);
                   left->setOpacity(0);
                   player->setLeft(left);

                   Line *right = new Line();
                   right->setPlayer(player);
                   right->setRect(12,12,25,1);
                   scene->addItem(right);
                   right->setPos(j*25,i*25);
                   right->setOpacity(0);
                   player->setRight(right);

                   Line *up = new Line();
                   up->setPlayer(player);
                   up->setRect(12,-12,1,25);
                   scene->addItem(up);
                   up->setPos(j*25,i*25);
                   up->setOpacity(0);
                   player->setUp(up);

                   Line *down = new Line();
                   down->setPlayer(player);
                   down->setRect(12,12,1,25);
                   scene->addItem(down);
                   down->setPos(j*25,i*25);
                   down->setOpacity(0);
                   player->setDown(down);
            }
        }
    }



    return a.exec();
}
