#ifndef PIPELINE_H
#define PIPELINE_H

#include <opencv2/opencv.hpp>
#include <QTimer>
#include <QVector>

class FrameHandler;

class PipeLine: public QObject
{
    Q_OBJECT

public:
    void openDevice(int device);
    void openDevice(const cv::String& device);
	void addHandler(FrameHandler* handler);
    void start(int fps = 10);
    void stop();

private slots:
    void onTimer();

private:
	cv::VideoCapture _input;
    QVector<FrameHandler*> _handlers;
    QTimer _timer;
    cv::Mat _frame;
};

#endif
