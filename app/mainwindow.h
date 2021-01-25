#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QRandomGenerator>
#include "player.h"
#include "imageprocessor.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>
#include <QtMultimedia/QMediaPlayer>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Player player;
private slots:
    void on_browseBtn_clicked();

    void on_playBtn_clicked();

    void on_TestBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
