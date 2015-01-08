#pragma once
#include <opencv2/opencv.hpp>
#include "FrameHandler.h"

using namespace cv;

class VideoSaver: public FrameHandler
{
public:
	VideoSaver(const String& filename, int fourcc, double fps, Size frameSize);
	void handleFrame(Mat& frame);

private:
	VideoWriter _videoWriter;
};

