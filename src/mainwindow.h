#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qfile.h>
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <qsound.h>
#include <qdebug.h>
#include "player.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_browseBtn_clicked();

    void on_playBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
