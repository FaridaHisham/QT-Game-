#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"
#include <Health.h>
#include <gameover.h>

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    QPixmap p(":/images/enemies.png");
    p = p.scaledToWidth(75);
    p = p.scaledToHeight(75);
    setPixmap(p);

    //set random x position
    int random_number = rand() % 8 + 1;
    random_number*=100;
    setPos(random_number,0);

    // drew the rect

    setTransformOriginPoint(50,50);
    setRotation(180);

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Enemy::move(){
    // move enemy down
    setPos(x(),y()+5);

    // destroy enemy when it goes out of the screen
    if (pos().y() > 600){

        //decrease the health
        game->health->decrease();
        //condition for terminating game
        if(game->health->health== 0)
        {
            game->close();
            Gameover *over = new Gameover();
            over->show();


            //game over
            //close current scene and create a new one *game over*
        }

        scene()->removeItem(this);
        delete this;
    }
}

