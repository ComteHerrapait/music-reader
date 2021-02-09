#include "imageprocessor.h"

ImageProcessor::ImageProcessor()
{

}

QString ImageProcessor::fakeProcessing(QWidget *parent){
    QString path = QFileDialog::getOpenFileName(parent, "choisir une partition",
                                                "partitions",//default directory
                                                "partitions (*.csv)");
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "error opening preprocessed file" << file.errorString();
    }

    QStringList wordList;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        wordList.append(line);
    }

    return  wordList.join("\n");
}

QString ImageProcessor::Processing(QImage partitionImage){
    //TODO

    qDebug() << "Processing feature not implemented yet";
}
