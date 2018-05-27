#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>

#include <iostream>            // for standard I/O
#include <string>              // for strings
#include <iomanip>             // for controlling float print precision
#include <sstream>             // string to number conversion
#include <opencv2/core.hpp>    // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/imgproc.hpp> // Gaussian Blur
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp> // OpenCV window I/O

#include "Net.h"
#include "Layer.h"

int gMouseX = 0;
int gMouseY = 0;

void testNN(Net &nn);
int trainByVideo(Net &nn, std::string trainFileName );

const int CHANNEL_INDEX = 2;

const int SPAN_SIZE = 32;

const int LAYER_SIZE = 4;
const int INPUT_LAYER_SIZE = 8;

uint gSpanHistogramBins[INPUT_LAYER_SIZE];
    
void initSpanHistogramBins() {

    for (int n=0 ; n<INPUT_LAYER_SIZE;n++) {
        gSpanHistogramBins[n] = n * (256/INPUT_LAYER_SIZE);
        std::cout << gSpanHistogramBins[n] << std::endl;
    }
}

int main(int argc, char** argv)
{
    time_t t;

    srand((unsigned)time(&t));
    initSpanHistogramBins();

    Net nn;

    VecTopology topology;
    topology.push_back(INPUT_LAYER_SIZE);
    topology.push_back(LAYER_SIZE);
    topology.push_back(LAYER_SIZE);
    topology.push_back(LAYER_SIZE);

    topology.push_back(1);

    nn.init(topology);
    // nn.check();

    //testNN(nn);
    trainByVideo(nn, argv[1]);

    return 0;
}


void CallBackFunc(int event, int x, int y, int flags, void *userdata)
{
    if (event == cv::EVENT_LBUTTONDOWN)
    {
        std::cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
    }
    else if (event == cv::EVENT_RBUTTONDOWN)
    {
        std::cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
    }
    else if (event == cv::EVENT_MBUTTONDOWN)
    {
        std::cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
    }
    else if (event == cv::EVENT_MOUSEMOVE)
    {
        //std::cout << "Mouse move over the window - position (" << x << ", " << y << ")" << std::endl;
        gMouseX = x;
        gMouseY = y;
    }
}

void spanHistogramToLayerInput(uchar span[SPAN_SIZE], VecFloat &feed)
{
    uint bins[INPUT_LAYER_SIZE] = {0};

    for (int n = 0; n < SPAN_SIZE; n++)
    {
        for (int r=1 ; r < INPUT_LAYER_SIZE;r++) {
            if (span[n] < gSpanHistogramBins[r]) {
                bins[r-1]+=1;
                break;
            }
        }
    }

    for (int r=0 ; r < INPUT_LAYER_SIZE;r++) {
        feed.push_back((float)bins[r] / (float)SPAN_SIZE);
    }

}

int trainByVideo(Net &nn, std::string trainFileName )
{

    VecFloat target;
    target.push_back(1.0f);
    // target.push_back(0.0f);
    // target.push_back(0.0f);
    // target.push_back(0.0f);

    cv::VideoCapture capVideo(trainFileName);

    if (!capVideo.isOpened())
    {
        std::cout << "Could not open video file " << trainFileName << std::endl;
        return -1;
    }

    cv::Size videoSize = cv::Size((int)capVideo.get(cv::CAP_PROP_FRAME_WIDTH),
                                  (int)capVideo.get(cv::CAP_PROP_FRAME_HEIGHT));

    const char *WINID = "train";

    //Create a window
    cv::namedWindow(WINID);
    cv::moveWindow(WINID, videoSize.width, videoSize.height);

    //set the callback function for any mouse event
    cv::setMouseCallback(WINID, CallBackFunc, NULL);

    int frameNum = 0;
    cv::Mat frameDisp;
    cv::Mat frameOrg;
    cv::Mat frameCap;

    capVideo >> frameCap;
    cv::cvtColor(frameCap, frameOrg, cv::COLOR_BGR2HSV);

    cv::Mat channels[3];
    cv::split(frameOrg, channels);
    frameOrg = channels[CHANNEL_INDEX];

    bool span_checking = false;
    bool span_training = false;
    bool play_video = false;

    for (;;) //Show the image captured in the window and repeat
    {

        frameOrg.copyTo(frameDisp);

        for (int y = 0; y < videoSize.height; y += 16)
        {
            for (int x = 0; x < videoSize.width; x += SPAN_SIZE)
            {

                VecFloat feed;

                uchar span[SPAN_SIZE];
                for (int n = 0; n < SPAN_SIZE; n++)
                {
                    uchar intensity = frameOrg.at<uchar>(y, x + n);
                    //float value = (float)intensity / 128.0f  - 1.0f;
                    //feed.push_back(value);

                    span[n] = intensity;
                }

                spanHistogramToLayerInput(span, feed);

                nn.feedForward(feed);
                float out0 = nn.getLayers().back()->getNodes()[0]->getOutput();
                //std::cout << out0 << ",";

                for (int n = 0; n < SPAN_SIZE; n++)
                {

                    if (out0 > 0.95)
                    {
                        frameDisp.at<uchar>(y, x + n) = 0; //uchar( 255.0f * out0, 255.0f * out0, 255.0f * out0 );
                    }
                }
                /* 
                float out1 = nn.getLayers().back()->getNodes()[1]->getOutput();
                float out2 = nn.getLayers().back()->getNodes()[2]->getOutput();
                float out3 = nn.getLayers().back()->getNodes()[3]->getOutput();
                */

                // if (out0 > 0.8f &&
                //      out1 < 0.05f &&
                //      out2 < 0.05f &&
                //      out3 < 0.05f
                //      )
                {
                    // for (int n = 0; n < SPAN_SIZE; n++)
                    // {
                    //     frameDisp.at<uchar>( y, x+n) = uchar(255,0,0);
                    // }

                    // std::cout << x << "," << y << ": ";
                    // VecNode &outputNodes = nn.getLayers().back()->getNodes();
                    // for (int n = 0; n < outputNodes.size(); n++)
                    // {
                    //     std::cout << outputNodes[n]->getOutput() << " ";
                    // }
                    // std::cout << std::endl;
                }
            }
        }

        // std::cout << std::endl;

        cv::imshow(WINID, frameDisp);
        char c = (char)cv::waitKey(1);

        if (c == 27)
            break;

        if (c == 'p')
        {
            play_video = !play_video;
        }

        if (c == 't')
        {
            span_training = !span_training;
        }

        if (c == 'r')
        {
            nn.reset();
        }

        if (c == 'c')
        {
            span_checking = !span_checking;
        }

        if (span_training || span_checking)
        {
            VecFloat feed;
            uchar span[SPAN_SIZE];

            for (int n = 0; n < SPAN_SIZE; n++)
            {
                uchar intensity = frameOrg.at<uchar>(gMouseY, gMouseX + n);
                span[n] = intensity;
            }

            spanHistogramToLayerInput(span, feed);
           
            //std::cout << gMouseY << " " << gMouseX << std::endl;

            nn.feedForward(feed);

            if (span_training)
            {
                nn.backProp(target);
                //std::cout << "Avg error: " << nn.avgError() << std::endl;
            }

            if (span_checking)
            {

                for (int n = 0 ; n<feed.size() ; n++) {
                    std::cout << feed[n] << ",";
                }
                std::cout << std::endl;

                float out0 = nn.getLayers().back()->getNodes()[0]->getOutput();
                //std::cout << "Out: " << out0 << std::endl;
            }
        }

        if (c == 'q')
        {
            VecNode &outputNodes = nn.getLayers().back()->getNodes();
            for (uint n = 0; n < outputNodes.size(); n++)
            {
                std::cout << outputNodes[n]->getOutput() << " ";
            }
            std::cout << std::endl;
        }

        if (c == ' ' || play_video)
        {
            capVideo >> frameCap;
            cv::cvtColor(frameCap, frameOrg, cv::COLOR_BGR2HSV);

            cv::Mat channels[3];
            cv::split(frameOrg, channels);
            frameOrg = channels[CHANNEL_INDEX];

            if (frameDisp.empty())
            {
                std::cout << " < < <  No frameDisp  > > > ";
                break;
            }

            ++frameNum;
            //std::cout << "Frame: " << frameNum << std::endl;
        }
    }

    return 0;
}
