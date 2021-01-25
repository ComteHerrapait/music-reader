#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QSound>
#include <QList>
#include <QDir>
#include <QDebug>
#include <QTimer>
#include <chrono>
#include <thread>


class Player : public QWidget
{
    Q_OBJECT
public:
    explicit Player(QWidget *parent = nullptr);
    QList<QSound*> soundFont;
    void createSoundFont(QString instrument_);
    void playNote(int index);
    void playNotes(QList<int> indexes);
    void playSong(QString partition, int tempo);
signals:

};

#endif // PLAYER_H
