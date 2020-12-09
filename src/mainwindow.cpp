#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browseBtn_clicked()
{
    //choose the path to read the partition from
    QString path = QFileDialog::getOpenFileName(this, "choisir une image de partitions",
                                                "",//default directory
                                                "images (*.jpg, *.png)");
    ui->pathEdit->setText(path);
}

void MainWindow::on_playBtn_clicked()
{
    QString path(ui->pathEdit->text());
    QFile imageFile(path);
    if (!imageFile.exists()){
        QMessageBox::information(0, "Erreur", imageFile.errorString());
        return;
    }

    QImage partition(path);
    int tempo(ui->tempoBox->value());
    QString instrument(ui->instrumentBox->currentText());

    qDebug() << tempo;

    Player player;
    player.createSoundFont();
}
