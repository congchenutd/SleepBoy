#include "MainWindow.h"
#include "MotionDetecter.h"
#include "PipeLine.h"
#include "VideoSaver.h"
#include "VideoViewer.h"
#include <QApplication>

#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

    //"http://1:1@192.168.1.110:8888/videostream.asf"

//    PipeLine pipeline(0);
//    pipeline.addHandler(new MotionDetecter);
//    pipeline.addHandler(new VideoViewer);
//    pipeline.addHandler(new VideoSaver("out.avi", VideoWriter::fourcc('D', 'I', 'V', 'X'), 15,
//                                       Size(640, 480)));
//    pipeline.run();

//    return 0;
}
