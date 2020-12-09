#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //initialize available intruments
    QDir directory(":/instruments/soundfonts/");
    QStringList intrumentList = directory.entryList();
    if (!intrumentList.isEmpty()) {
        //remove no instrument warning
        ui->instrumentBox->removeItem(0);
        for ( const auto& i : intrumentList  )
        {
            ui->instrumentBox->addItem(i);
        }
    }
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

    this->player.createSoundFont(instrument);
    ui->TestBtn->setEnabled(true);
}

void MainWindow::on_TestBtn_clicked()
{
    //plays a random note of the instrument
    int v = QRandomGenerator::global()->bounded(0, 21);
    this->player.playSound(v);
}
