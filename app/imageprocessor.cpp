#include "imageprocessor.h"

ImageProcessor::ImageProcessor()
{

}

QString ImageProcessor::fakeProcessing(){
    QString fakesong("1;1\n"
                     "1;2\n"
                     "1;5\n"
                     "1;7\n");
    return  fakesong;
}

QString ImageProcessor::Processing(QImage partitionImage){
    //TODO
    qDebug() << "Processing feature not implemented yet";
}
