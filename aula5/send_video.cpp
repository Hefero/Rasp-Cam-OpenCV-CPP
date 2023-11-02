/**
 * OpenCV video streaming over TCP/IP
 * Client: Receives video from server and display it
 * by Steve Tuenkam
 */

#include "opencv2/opencv.hpp"
#include <sys/socket.h> 
#include <chrono>
#include <arpa/inet.h>
#include <unistd.h>
#include "Transmitter/Transmitter.cpp"
#include "MotorH/MotorH.cpp"
#include <wiringPi.h>
#include <softPwm.h>

using namespace cv;

int capDev = 0;
VideoCapture cap(capDev); // open the default camera

int main(int argc, char** argv)
{
    if (argc < 3) {
           std::cerr << "Usage: cv_video_cli <serverIP> <serverPort> " << std::endl;
    }

    Transmitter rec(argc, argv);

    Mat img;
    img = Mat::zeros(480 , 640, CV_8UC3);
    vector<unsigned char> vb;
    vector<int> param{CV_IMWRITE_JPEG_QUALITY,80};    
    
    while(1){        
        try{
            cap >> img;
            imencode(".jpg",img,vb,param);
            rec.sendBytes(vb);
            int bytesRec;
            /*
            rec.recvInt(bytesRec);
            if (bytesRec == vb.size()){
                std::cout << "Received confirmation of bytes: " << bytesRec << std::endl;
            }
            string command;
            int bytesCommand = rec.recvString(command);
            if(bytesCommand > 0){
                std::cout << "receive command" << command << std::endl;
                //motorH.execute(command);
            }
            */
        }
        catch(cv::Exception ex){
            std::cout << "encoding error " << ex.msg << std::endl;
            continue;
        }
    }

    return 0;
}
