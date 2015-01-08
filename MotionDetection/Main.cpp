#include "MotionDetecter.h"
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>
#include "PipeLine.h"
#include "VideoViewer.h"
#include "VideoSaver.h"

using namespace cv;

int main(int argc, char* argv[])
{
	//"http://1:1@192.168.1.110:8888/videostream.asf"

	PipeLine pipeline("http://1:1@192.168.1.110:8888/videostream.asf");
	pipeline.addHandler(new MotionDetecter);
	pipeline.addHandler(new VideoViewer);
	pipeline.addHandler(new VideoSaver("out.avi", VideoWriter::fourcc('D', 'I', 'V', 'X'), 15, 
										Size(640, 480)));
	pipeline.run();

	return 0;
}