
#include "Mygui/Mygui.cpp"
#include <opencv2/opencv.hpp>
#include "cekeikon.h"
#include "Receiver/Receiver.cpp"

Mygui gui;

void onMouseGui(int event, int x, int y, int flags, void* userdata)
{ 
    Mouse* mouse=(Mouse*)userdata;
    if (event==EVENT_LBUTTONDOWN) {
        (*mouse).clicou=true; (*mouse).x=x; (*mouse).y=y;  (*mouse).up=false;
    }
    if (event==EVENT_LBUTTONUP) {
        (*mouse).clicou=true; (*mouse).x=x; (*mouse).y=y; (*mouse).up=true;
    }
    
}

int main(int argc, char** argv)
{
Receiver rec(argc, argv);

Mat img = Mat::zeros(480 , 640, CV_8UC3);
Mat concatImg = Mat::zeros(480+480 , 640, CV_8UC3);

namedWindow("janela");
setMouseCallback("janela", onMouseGui, &gui.mouse);
int key = 0;
    
 while (key != 'q') {
    try{
        gui.guiLoop();    
        if (rec.waitConnection() > 0){
            img = imdecode(rec.buffer,1);
        }
        concatImg = grudaH(gui.a,img);
        imshow("janela",concatImg);
    }
    catch(cv::Exception ex){
            continue;
    }
    if (key = cv::waitKey(1) >= 0) break;
 }
}
