#include "player.h"

Player::Player(QWidget *parent) : QWidget(parent)
{
}

void Player::createSoundFont(QString instrument_){
    this->soundFont.clear();
    QString intrumentPath = "instruments/" + instrument_ + "/";
    qDebug() << "path to instrument" << intrumentPath;
    QDir directory(intrumentPath);
    QStringList noteList = directory.entryList(QStringList("*.mp3"));
    for ( const auto& i : noteList  )
    {
        QFileInfo file(directory, i);
        file.canonicalFilePath();
        QString *path = new QString(file.canonicalFilePath());
        this->soundFont.append(path);
    }
    qDebug() << "soundfont initialized";
    foreach (QString * note, this->soundFont){
        qDebug() << "note :" << *note;
    }

}


void Player::playNote(int index){
    QMediaPlayer *media = new QMediaPlayer;
    media->setMedia(QUrl::fromLocalFile(*this->soundFont[index]));
    media->setVolume(50);
    media->play();
}

void Player::playNotes(QList<int> indexes){
    foreach (int i , indexes)
    {
        this->playNote(i);
    }
    qDebug() << QTime::currentTime() << "played sounds " << indexes;
}

void Player::playSong(QString partition, int tempo){
    QTimer timer;
    QStringList instants = partition.split(QRegExp("[\n]"), QString::SkipEmptyParts);
    foreach (QString instant, instants){
        QStringList elements = instant.split(QRegExp("[,]"), QString::SkipEmptyParts);
        double duration = elements.first().toDouble();
        elements.removeFirst();
        QList<int> notesInt;
        foreach(QString note, elements){
            if (note != "-1") {
                notesInt << note.toInt();
            }
        }
        this->playNotes(notesInt);
        Sleep(duration * 60000/tempo);
        //std::this_thread::sleep_for(std::chrono::milliseconds(tempo/60000));
    }


}
