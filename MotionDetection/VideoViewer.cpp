#include "VideoViewer.h"
#include <opencv2\highgui.hpp>

using namespace cv;

VideoViewer::VideoViewer()
{
	namedWindow("Frame");
}

void VideoViewer::handleFrame(cv::Mat& frame)
{
	imshow("Frame", frame);
}
