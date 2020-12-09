#include "player.h"

Player::Player(QWidget *parent) : QWidget(parent)
{
}

void Player::createSoundFont(){
    QDir directory(":/instruments/soundfonts/piano/");
    QStringList noteList = directory.entryList(QStringList("*.wav"));
    qDebug() << noteList;
}
