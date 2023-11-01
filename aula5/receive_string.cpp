/**
 * OpenCV video streaming over TCP/IP
 * Client: Receives video from server and display it
 * by Steve Tuenkam
 */

#include "opencv2/opencv.hpp"
#include <sys/socket.h> 
#include <arpa/inet.h>
#include <unistd.h>
#include "Receiver/Receiver.cpp"

using namespace cv;

int main(int argc, char** argv)
{
    if (argc < 3) {
           std::cerr << "Usage: cv_video_cli <serverIP> <serverPort> " << std::endl;
    }
    
    Receiver rec(argc, argv);
    string recv;
    while(1){
        //rec.sendString("Envio de String");
        rec.waitConnection();
    }

    return 0;
}
