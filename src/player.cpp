#include "player.h"

Player::Player(QWidget *parent) : QWidget(parent)
{
    qDebug() << "player created";
}

void createSoundFont(){
    QDir directory(":/instruments/soundfonts/piano/");
    QStringList noteList = directory.entryList(QStringList("*.wav"));
    qDebug() << noteList;
}
