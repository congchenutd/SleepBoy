#include "PipeLine.h"
#include "FrameHandler.h"
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include <vector>

using namespace cv;
using namespace std;

PipeLine::PipeLine(int device)
	: _input(device)
{
}

PipeLine::PipeLine(const cv::String& device)
	: _input(device)
{
}

void PipeLine::run()
{
	Mat frame;
	if(!_input.isOpened())
		return;

	for(;;)
	{
		_input >> frame;
		for(size_t i = 0; i < _handlers.size(); ++i)
			_handlers[i]->handleFrame(frame);
		if(waitKey(30) >= 0) 
			break;
	}
}

void PipeLine::addHandler(FrameHandler* handler) {
	_handlers.push_back(handler);
}
