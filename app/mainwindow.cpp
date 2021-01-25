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

    QString processedPartition = ImageProcessor::fakeProcessing(); //placeholder
    this->player.playSong(processedPartition,tempo);
    ui->TestBtn->setEnabled(true);

    qDebug() << "done";
}

void MainWindow::on_TestBtn_clicked()
{
    //plays a sound
    //this->player.playSong(ImageProcessor::fakeProcessing(),ui->tempoBox->value());

    //plays a random note of the instrument
    //int v = QRandomGenerator::global()->bounded(0, 21);
    //this->player.playNote(v);

    //test
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("soundfonts/piano/Piano-01.wav"));
    //setMedia(QUrl::fromLocalFile("soundfonts/piano/leon.wav"));
    player->setVolume(50);
    player->play();
    qDebug() << QTime::currentTime() << "PLAY 1 ";

    Sleep(560);

    QMediaPlayer *player2 = new QMediaPlayer;
    player2->setMedia(QUrl::fromLocalFile("soundfonts/piano/Piano-01.wav"));
    player2->setVolume(50);
    player2->play();
    qDebug() << QTime::currentTime() << "PLAY 2 ";

    Sleep(590);

    QMediaPlayer *player3 = new QMediaPlayer;
    player3->setMedia(QUrl::fromLocalFile("soundfonts/piano/Piano-01.wav"));
    player3->setVolume(50);
    player3->play();
    qDebug() << QTime::currentTime() << "PLAY 3 ";
    Sleep(510);
}
