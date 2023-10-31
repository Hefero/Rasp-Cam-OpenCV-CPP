//mouse.cpp
#include <cekeikon.h>
#include <sys/ioctl.h>
#include <stdio.h>
void onMouse(int event, int x, int y, int flags, void* userdata)
{
 if (event==EVENT_LBUTTONDOWN) {
 cout << "Apertou botao esquerda - posicao ("
 << x << ", " << y << ")" << endl;
 } else if (event==EVENT_RBUTTONDOWN) {
 cout << "Apertou botao direita - posicao (" 
 << x << ", " << y << ")" << endl;
 } else if ( event == EVENT_MOUSEMOVE ) {
 cout << "Mouse moveu na janela - posicao (" 
 << x << ", " << y << ")" << endl;
 }
}
int main(int argc, char** argv) 
{ 
printf("Mouse: Captura webcam e mostra eventos do mouse.\n");
VideoCapture w(0);
if (!w.isOpened()) erro("Erro: Abertura de webcam 0.");
w.set(CV_CAP_PROP_FRAME_WIDTH,640);
w.set(CV_CAP_PROP_FRAME_HEIGHT,480);
Mat_<COR> a;
namedWindow("janela");
setMouseCallback("janela", onMouse);
    while (true) {
        w >> a; // get a new frame from camera
        imshow("janela",a);
        int ch=(signed char)(waitKey(30)); // E necessario (signed char)
        if (ch>=0) break;
    }
}