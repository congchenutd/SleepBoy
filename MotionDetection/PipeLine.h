#pragma once

#include <opencv2/opencv.hpp>
class FrameHandler;

class PipeLine
{
public:
	PipeLine(int device);
	PipeLine(const cv::String& device);
	void addHandler(FrameHandler* handler);
	void run();

private:
	cv::VideoCapture _input;
	std::vector<FrameHandler*> _handlers;
};

