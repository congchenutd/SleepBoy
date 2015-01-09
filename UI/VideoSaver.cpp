#include "VideoSaver.h"
#include <QDateTime>
#include <QObject>

using namespace cv;

void VideoSaver::config(const QString& path, int fourcc, int fps, Size frameSize)
{
    _path       = path;
    _fourcc     = fourcc;
    _fps        = fps;
    _frameSize  = frameSize;
    _fileName   = generateFileName();
    _videoWriter.open(_fileName.toStdString(), _fourcc, _fps, _frameSize);
    _frameCount = 0;
}

void VideoSaver::handleFrame(Mat& frame)
{
    _videoWriter << frame;
    if(++_frameCount > 10 * _fps)
        config(_path, _fourcc, _fps, _frameSize);
}

QString VideoSaver::generateFileName() {
    return QObject::tr("%1/%2.avi")
            .arg(_path)
            .arg(QDateTime::currentDateTime().toMSecsSinceEpoch());
}
