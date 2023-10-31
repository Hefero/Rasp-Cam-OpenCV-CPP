
#include "Mygui/Mygui.cpp"
#include <opencv2/opencv.hpp>
#include "cekeikon.h"
#include "Receiver/Receiver.cpp"

Mygui gui;

void onMouseGui(int event, int x, int y, int flags, void* userdata)
{ 
    Mouse* mouse=(Mouse*)userdata;
    if (event==EVENT_LBUTTONDOWN || event==EVENT_LBUTTONUP) {
        (*mouse).clicou=true; (*mouse).x=x; (*mouse).y=y;
    }
}

int main(int argc, char** argv)
{
Receiver rec(argc, argv);

Mat img = Mat::zeros(480 , 640, CV_8UC3);
Mat concatImg = Mat::zeros(480+480 , 640, CV_8UC3);

namedWindow("janela");
setMouseCallback("janela", onMouseGui, &gui.mouse);
    
 while (waitKey(30)<0) {
    gui.guiLoop();    
    if (rec.waitConnection() > 0){
        try{
            img = imdecode(rec.buffer,1);
        }
        catch(exception ex){
            continue;
        }
    }
    concatImg = grudaH(gui.a,img);
    imshow("janela",concatImg);
 }
}
