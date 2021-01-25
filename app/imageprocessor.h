#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H
#include <QString>
#include <QImage>
#include <QDebug>
#include <QFile>

class ImageProcessor
{
public:
    ImageProcessor();
    static QString fakeProcessing();
    static QString Processing(QImage partitionImage);
};

#endif // IMAGEPROCESSOR_H
