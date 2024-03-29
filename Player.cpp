#include "Player.h"
#include <QGraphicsScene>
//#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    // /* set bullet sound
    // bulletsound = new QMediaPlayer();
    // bulletsound->setMedia(QUrl("qrc:/sounds/bullet.wav"));*/


    QPixmap p(":/images/player.png");
    p = p.scaledToWidth(100);
    p = p.scaledToHeight(100);


    // set graphic
    setPixmap(p);
}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
            setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
            setPos(x()+10,y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){

        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+45,y());
        scene()->addItem(bullet);

        // // play bulletsound
        // if (bulletsound->state() == QMediaPlayer::PlayingState){
        //     bulletsound->setPosition(0);
        // }
        // else if (bulletsound->state() == QMediaPlayer::StoppedState){
        //     bulletsound->play();
        // }

    }
}

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
