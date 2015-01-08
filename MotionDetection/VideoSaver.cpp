#include "VideoSaver.h"

using namespace cv;

VideoSaver::VideoSaver(const String& filename, int fourcc, double fps, Size frameSize)
	: _videoWriter(filename, fourcc, fps, frameSize)
{

}

void VideoSaver::handleFrame(Mat& frame)
{
	_videoWriter.write(frame);
}
