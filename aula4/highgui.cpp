//Lampada08.cpp
//Cria classe Mouse.
#include <opencv2/opencv.hpp>
using namespace cv;
struct Mouse {
 bool clicou=true;
 int x,y;
};
void onMouse(int event, int x, int y, int flags, void* userdata)
{ Mouse* mouse=(Mouse*)userdata;
 if (event==EVENT_LBUTTONDOWN || event==EVENT_LBUTTONUP) {
 (*mouse).clicou=true; (*mouse).x=x; (*mouse).y=y;
 } 
}
class Botao {
 public:
 Point p,q;
 string st0,st1;
 bool ligado,primeiraVez;
 Botao(Point _p, Point _q, string _st0, string _st1="", bool _ligado=false);
 void testaDesenha(Mat_<Vec3b>& a, Mouse mouse);
};
Botao::Botao(Point _p, Point _q, string _st0, string _st1, bool _ligado)
{ p=_p; q=_q; st0=_st0; 
 if (_st1!="") st1=_st1; else st1=_st0;
 ligado=!_ligado; primeiraVez=true; 
}
void Botao::testaDesenha(Mat_<Vec3b>& a, Mouse mouse)
{ if (primeiraVez || (p.x<=mouse.x && mouse.x<=q.x && p.y<=mouse.y && mouse.y<=q.y)) {
 if (ligado) {
 ligado=false;
 rectangle(a, p,q, Scalar(192,192,192), CV_FILLED);
 line(a, p, Point(p.x,q.y), Scalar(255,255,255), 4);
 line(a, p, Point(q.x,p.y), Scalar(255,255,255), 4);
 line(a, q, Point(p.x,q.y), Scalar(0,0,0), 4);
 line(a, q, Point(q.x,p.y), Scalar(0,0,0), 4);
 putText(a, st0, Point(p.x+5,(p.y+q.y)/2), FONT_HERSHEY_SIMPLEX, 1, Scalar(0,0,0), 2);
 } else {
 ligado=true;
 rectangle(a, p,q, Scalar(128,255,255), CV_FILLED);
 line(a, p, Point(p.x,q.y), Scalar(0,0,0), 4);
 line(a, p, Point(q.x,p.y), Scalar(0,0,0), 4);
 line(a, q, Point(p.x,q.y), Scalar(255,255,255), 4);
 line(a, q, Point(q.x,p.y), Scalar(255,255,255), 4);
 putText(a, st1, Point(p.x+5,(p.y+q.y)/2), FONT_HERSHEY_SIMPLEX, 1, Scalar(0,0,0), 2);
 }
 primeiraVez=false;
 }
}
int main()
{ printf("Sai do programa apertando uma tecla.\n");
 printf("Liga e desliga os botoes com click.\n");
 Mat_<Vec3b> a(480,640,Vec3b(192,192,192));
 namedWindow("janela");
 Mouse mouse;
 setMouseCallback("janela", onMouse, &mouse);
 imshow("janela",a);
 Botao b1(Point(70, 60),Point(160,160),"BO1");
 Botao b3(Point(70,180),Point(160,280),"BO3");
 Botao b5(Point(70,300),Point(160,410),"BO5");

 Botao b2(Point(270, 60),Point(360,160),"BO2"); 
 Botao b4(Point(270,180),Point(360,280),"BO4"); 
 Botao b6(Point(270,300),Point(360,410),"BO6");


 Botao b7(Point(470, 60),Point(560,160),"BO7");
 Botao b8(Point(470,180),Point(560,280),"BO8");
 Botao b9(Point(470,300),Point(560,410),"BO9");

 while (waitKey(30)<0) {
 if (mouse.clicou) {
 b1.testaDesenha(a,mouse);
 b2.testaDesenha(a,mouse);
 b3.testaDesenha(a,mouse);
 b4.testaDesenha(a,mouse);
 b5.testaDesenha(a,mouse);
 b6.testaDesenha(a,mouse);
 b7.testaDesenha(a,mouse);
 b8.testaDesenha(a,mouse);
 b9.testaDesenha(a,mouse);
 imshow("janela",a);
 mouse.clicou=false;
 }
 }
}
