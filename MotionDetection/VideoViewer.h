#pragma once
#include "FrameHandler.h"

class VideoViewer: public FrameHandler
{
public:
	VideoViewer();
	void handleFrame(cv::Mat& frame);
};

