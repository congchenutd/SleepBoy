#include "CameraPage.h"
#include "MotionDetecter.h"
#include "MySettings.h"
#include "PipeLine.h"
#include "VideoSaver.h"
#include "VideoViewer.h"

#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>

CameraPage::CameraPage(QWidget *parent) :
    QWidget(parent)
{
    ui.setupUi(this);

    //"http://1:1@192.168.1.110:8888/videostream.asf"
    MySettings settings;
    _pipeLine.openDevice(0);
    _pipeLine.addHandler(new MotionDetecter);
    _pipeLine.addHandler(new VideoViewer(ui.label));
    _pipeLine.addHandler(new VideoSaver("out.avi",
                                        VideoWriter::fourcc('D', 'I', 'V', 'X'),
                                        settings.getFPS(),
                                        Size(640, 480)));
    _pipeLine.start(1000 / settings.getFPS());
}
