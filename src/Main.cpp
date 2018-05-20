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
int trainByVideo(Net &nn);

int SPAN_SIZE = 8;
int RBG_LAYER_SIZE = SPAN_SIZE * 3;
int PIXEL_BIAS = 128.0f;

int main(void)
{
    time_t t;

    srand((unsigned)time(&t));

    std::cout << "NN" << std::endl;
    Net nn;

    VecTopology topology;
    topology.push_back(RBG_LAYER_SIZE);
    topology.push_back(RBG_LAYER_SIZE);
    topology.push_back(RBG_LAYER_SIZE);
    topology.push_back(RBG_LAYER_SIZE);

    topology.push_back(1);

    nn.init(topology);
    // nn.check();

    testNN(nn);
    //trainByVideo(nn);

    return 0;
}

void testNN(Net &nn) {

    VecFloat target;
    target.push_back(1.0);

    VecFloat feedTrain;
    for (int n = 0; n < RBG_LAYER_SIZE; n++)
    {
        float v = ((float)rand() / (float)(RAND_MAX >> 1)) - 1.0f;
        feedTrain.push_back(v);
    }

   
    
    int count = 0;
    while (nn.avgError() > 0.001)
    {
        nn.feedForward(feedTrain);
        nn.backProp(target);
        std::cout << "Avg error [" << count << "] : " << nn.avgError() << std::endl;
        count++;
    }

    nn.debug();

    int countSimilar = 0;
    int TEST_SIZE = 1000000;

    for (int t=0;t<TEST_SIZE ; t++) {
        VecFloat feed;
        for (int n = 0; n < RBG_LAYER_SIZE; n++)
        {
            float v = ((float)rand() / (float)(RAND_MAX >> 1)) - 1.0f;
            //std::cout << v <<std::endl;

            feed.push_back(v);
        }
        nn.feedForward(feed);
        float out = nn.getLayers().back()->getNode(0)->getOutput();
        //std::cout << out <<std::endl;

        if (1.0f - out < 0.001f) {
            countSimilar++;
        }
    }

    std::cout << "Similar: " << countSimilar << " and Diff: " << (TEST_SIZE - countSimilar) << std::endl;

   
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

cv::Mat edgeDetect(cv::Mat & src) {
    cv::Mat gray, edge, draw;
    cv::cvtColor(src, gray, CV_BGR2GRAY);
 
    cv::Canny( gray, edge, 50, 150, 3);
 
    edge.convertTo(draw, CV_8U);
    return draw;
}

int trainByVideo(Net &nn)
{

    VecFloat target;
    target.push_back(1.0f);
    // target.push_back(0.0f);
    // target.push_back(0.0f);
    // target.push_back(0.0f);

    std::string trainFileName = "/home/dc/Videos/2018_0418_140633_002.MOV";
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

    capVideo >> frameOrg;

    bool train_working = false;

    for (;;) //Show the image captured in the window and repeat
    {

        frameOrg.copyTo(frameDisp);

        for (int y = 0; y < videoSize.height; y += 16)
        {
            for (int x = 0; x < videoSize.width; x += SPAN_SIZE)
            {

                VecFloat feed;

                for (int n = 0; n < SPAN_SIZE; n++)
                {
                    cv::Vec3b intensity = frameOrg.at<cv::Vec3b>(y, x + n);
                    float blue = (float)intensity.val[0] / 255.0f + PIXEL_BIAS;
                    float green = (float)intensity.val[1] / 255.0f + PIXEL_BIAS;
                    float red = (float)intensity.val[2] / 255.0f + PIXEL_BIAS;

                    feed.push_back(blue);
                    feed.push_back(green);
                    feed.push_back(red);

                    //std::cout << blue << "," << green << "," << red << std::endl;
                }

                nn.feedForward(feed);
                float out0 = nn.getLayers().back()->getNodes()[0]->getOutput();
                //std::cout << out0 << ",";

                for (int n = 0; n < SPAN_SIZE; n++)
                {
                    cv::Vec3b intensity = frameOrg.at<cv::Vec3b>(y, x + n);
                    
                    //if (out0 > 0.999) {
                    //    frameDisp.at<cv::Vec3b>(y, x + n) = 0.0;
                    //} 

                    frameDisp.at<cv::Vec3b>(y, x + n) = cv::Vec3b( 255.0f * out0, 255.0f * out0, 255.0f * out0 );
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
                    //     frameDisp.at<cv::Vec3b>( y, x+n) = cv::Vec3b(255,0,0);
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

        if (c == 't')
        {
            train_working = !train_working;
        }
        
        if (train_working) {
            VecFloat feed;

            for (int n = 0; n < SPAN_SIZE; n++)
            {
                cv::Vec3b intensity = frameOrg.at<cv::Vec3b>(gMouseY, gMouseX + n);
                float blue = (float)intensity.val[0] / 255.0f + PIXEL_BIAS;
                float green = (float)intensity.val[1] / 255.0f + PIXEL_BIAS;
                float red = (float)intensity.val[2] / 255.0f + PIXEL_BIAS;

                feed.push_back(blue);
                feed.push_back(green);
                feed.push_back(red);
                
                //std::cout << blue << "," << green << "," << red << std::endl;
            }

            //std::cout << gMouseY << " " << gMouseX << std::endl;

            nn.feedForward(feed);
            nn.backProp(target);
            std::cout << "Avg error: " << nn.avgError() << std::endl;
        }

        if (c == 'q')
        {
            VecNode &outputNodes = nn.getLayers().back()->getNodes();
            for (int n = 0; n < outputNodes.size(); n++)
            {
                std::cout << outputNodes[n]->getOutput() << " ";
            }
            std::cout << std::endl;
        }

        if (c == ' ')
        {
            capVideo >> frameOrg;

            if (frameDisp.empty())
            {
                std::cout << " < < <  No frameDisp  > > > ";
                break;
            }

            ++frameNum;
            std::cout << "Frame: " << frameNum << "# ";
        }
    }

    return 0;
}
