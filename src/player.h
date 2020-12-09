#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include "QSound"
#include "QList"
#include "qdir.h"
#include "qdebug.h"

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
