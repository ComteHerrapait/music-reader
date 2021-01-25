#include "imageprocessor.h"

ImageProcessor::ImageProcessor()
{

}

QString ImageProcessor::fakeProcessing(){
    QFile file("soundfonts/lamb.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
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
