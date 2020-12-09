#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QSound>
#include <QList>
#include <QDir>
#include <QDebug>

class Player : public QWidget
{
    Q_OBJECT
public:
    explicit Player(QWidget *parent = nullptr);
    QString partition;
    QList<QSound> soundFont;

    void createSoundFont();
signals:

};

#endif // PLAYER_H
