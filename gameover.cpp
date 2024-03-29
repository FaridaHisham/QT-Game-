#include "gameover.h"
#include "ui_gameover.h"

Gameover::Gameover(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Gameover)
{
    ui->setupUi(this);
    ui->label ;
}

Gameover::~Gameover()
{
    delete ui;
}
