#include "Health.h"
#include <QFont>

Health::Health(int health_, QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    // health = 3;
    this -> health = health_;
    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2

}


int Health::getHealth(){
    return health;
}
