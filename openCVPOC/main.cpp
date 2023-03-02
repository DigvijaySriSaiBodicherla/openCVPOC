#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cv::VideoCapture video(0);
    if (!video.isOpened()) return -1;

    cv::Mat frame;
    int frameNumber;
    int frameWidth = video.get(cv::CAP_PROP_FRAME_WIDTH);
    int frameHeight = video.get(cv::CAP_PROP_FRAME_HEIGHT);

    cv::VideoWriter output("output.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, cv::Size(frameWidth, frameHeight));


    bool rflag = 0;

    while (video.read(frame))
    {
        cv::imshow("Video feed", frame);

        output.write(frame);

        if (cv::waitKey(25) == 's')
        {
            cv::Mat frame2;
            frame2 = frame.clone();
            //cv::CAP_PROP_POS_FRAMES
            //frameNumber = output.get(cv::CAP_PROP_POS_FRAMES);
            //cv::capture.get(CV_CAP_PROP_POS_FRAMES);
            //string frameNum = to_string(frameNumber);
            time_t now = time(0);
            string frameNum = to_string(now);
            string fileNumber = frameNum + ".png";
            //cv::imshow(frameNum, frame2);
            cv::imwrite(fileNumber, frame2);
            //cv::imshow("Captured frame", frame2);
        }

        if (cv::waitKey(25) == 'd')
        {
            break;
        }
    }

    output.release();
    video.release();

    cv::destroyAllWindows();



    return 0;
}