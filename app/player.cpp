#include "player.h"

Player::Player(QWidget *parent) : QWidget(parent)
{
}

void Player::createSoundFont(QString instrument_){
    this->soundFont.clear();
    QString intrumentPath = ":/instruments/soundfonts/" + instrument_ + "/";
    QDir directory(intrumentPath);
    QStringList noteList = directory.entryList(QStringList("*.wav"));
    for ( const auto& i : noteList  )
    {
        QFileInfo file(directory, i);
        file.canonicalFilePath();
        QString path = file.canonicalFilePath();
        QSound* s = new QSound(path);
        this->soundFont.append(s);
    }
}

void Player::playSound(int index){
    this->soundFont[index]->play();
    qDebug() << "played sound " << index;
}
