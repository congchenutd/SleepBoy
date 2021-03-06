#include "MotionDetecter.h"
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include <vector>

using namespace cv;
using namespace std;
	   
MotionDetecter::MotionDetecter()
{
	setSizeThreshold(100, 100);
	_substractor = createBackgroundSubtractorMOG2();
}

void MotionDetecter::setSizeThreshold(int width, int height)
{
	_widthThreshold  = width;
	_heightThreshold = height;
}

void MotionDetecter::handleFrame(Mat& frame)
{
	const Scalar color = Scalar(0, 0, 255);
	vector<vector<Point> > contours;

	_substractor->apply(frame, _foreground);
	erode (_foreground, _foreground, Mat());
	dilate(_foreground, _foreground, Mat());
	findContours(_foreground, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

	for(size_t i = 0; i < contours.size(); i++)
	{
		// Approximate contours to polygons
		vector<Point> polygon;
		approxPolyDP(Mat(contours[i]), polygon, 3, true);

		// Draw bounding rectangle
		Rect boundRect = boundingRect(Mat(polygon));
		if (boundRect.width > _widthThreshold || boundRect.height > _heightThreshold)
			rectangle(frame, boundRect.tl(), boundRect.br(), color, 2, 8, 0);
	}
}


