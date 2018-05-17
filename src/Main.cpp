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

int trainByVideo(Net &nn);

int SPAN_SIZE = 24;

int main(void)
{
    time_t t;

    srand((unsigned)time(&t));

    std::cout << "NN" << std::endl;
    Net nn;

    VecTopology topology;
    topology.push_back(SPAN_SIZE);
    topology.push_back(SPAN_SIZE);
    topology.push_back(1);

    nn.init(topology);
    // nn.check();

    VecFloat target;
    target.push_back(1.0);

    VecFloat feed;
    for (int n=0;n<SPAN_SIZE ; n++){
        feed.push_back(0);
    }

    nn.feedForward(feed);        
    nn.backProp(target);

    std::cout << "Avg error: " << nn.avgError() << std::endl;
   
    int trainCount = 100;
    while (nn.avgError() > 0.01)
    {

        nn.feedForward(feed);
        nn.backProp(target);

        std::cout << "Avg error: " << nn.avgError() << std::endl;
    }

    // VecNode &outputNodes = nn.getLayers().back()->getNodes();
    // for (int n = 0; n < outputNodes.size(); n++)
    // {
    //     std::cout << outputNodes[n]->getOutput() << " ";
    // }

    //nn.debug();

    //trainByVideo(nn);
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
    
    for (;;) //Show the image captured in the window and repeat
    {

        frameOrg.copyTo(frameDisp);

        for(int y= videoSize.height-1 ; y < videoSize.height; y+=1) {
            for (int x=0; x < videoSize.width ; x+=SPAN_SIZE ) {

                VecFloat feed;

                for (int n = 0; n < SPAN_SIZE; n++)
                {
                    cv::Vec3b intensity = frameOrg.at<cv::Vec3b>(y, x + n);
                    float blue = (float)intensity.val[0] / 255.0f;
                    float green = (float)intensity.val[1] / 255.0f;
                    float red = (float)intensity.val[2] / 255.0f;

                    feed.push_back( 0.0);//*(blue+green+red)/3.0f);
                   
                    //std::cout << blue << "," << green << "," << red << std::endl;
                }

                nn.feedForward(feed);
                float out0 = nn.getLayers().back()->getNodes()[0]->getOutput();
                //std::cout << out0 << ",";

                for (int n = 0; n < SPAN_SIZE; n++)
                {
                    cv::Vec3b intensity = frameOrg.at<cv::Vec3b>(y, x + n);
                    // float blue = (float)intensity.val[0];
                    // float green = (float)intensity.val[1];
                    // float red = (float)intensity.val[2];
                    intensity=out0 * 255;
                    frameDisp.at<cv::Vec3b>(y, x + n) = intensity;
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

        std::cout << std::endl;

        cv::imshow(WINID, frameDisp);
        char c = (char)cv::waitKey();

        if (c == 27)
            break;

        if (c == 't')
        {
            VecFloat feed;

            for (int n = 0; n < SPAN_SIZE; n++)
            {
                cv::Vec3b intensity = frameOrg.at<cv::Vec3b>(gMouseY, gMouseX + n);
                float blue = (float)intensity.val[0] / 255.0f;
                float green = (float)intensity.val[1] / 255.0f;
                float red = (float)intensity.val[2] / 255.0f;

                feed.push_back( (blue+green+red)/3.0f);

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
