#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H
#include <QString>
#include <QImage>
#include <QDebug>
#include <QFile>
#include <QFileDialog>

class ImageProcessor
{
public:
    ImageProcessor();
    static QString fakeProcessing(QWidget *parent);
    static QString Processing(QImage partitionImage);
};

#endif // IMAGEPROCESSOR_H
