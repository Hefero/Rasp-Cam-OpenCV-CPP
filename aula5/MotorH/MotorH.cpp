#include "MotorH.h"
#include <iostream>


#define velDir 100
#define velEsq 100

#define LEFT_TURN_DISTANCE 10000
#define RIGHT_TURN_DISTANCE 10000


motorH::motorH()

{
   wiringPiSetup();
   softPwmCreate(22, 0, 100);
   softPwmCreate(23, 0, 100);
   softPwmCreate(24, 0, 100);
   softPwmCreate(25, 0, 100);
}

void motorH::moveForward()
{
    moving = true;
    motorDir(1, velDir); 
    motorEsq(1, velEsq);
}
void motorH::moveBackwards()
{
    moving = true;
    motorDir(1, velDir); 
    motorEsq(1, velEsq);
}

void motorH::stop(void)
{
    moving = false;
    motorDir(0, 0); // inicia os motores em ponto morto
    motorEsq(0, 0); // inicia os motores em ponto morto
   
}

void motorH::hardStop(void)
{
    moving = false;
    motorDir(2, 0); // trava os motores
    motorEsq(2, 0); // trava os motores    
}

void motorH::turnLeft(void)
{
    std::cout << "Virando para esquerda" << std::endl;
    moving = true;
    int i = 0;
    while(i < LEFT_TURN_DISTANCE)
    {
        moving = true;
        motorDir(1, velDir);
        motorEsq(-1, velEsq);
        i++;
    }
}

void motorH::turnRight(void)
{
    std::cout << "Virando para direita" << std::endl;
    moving = true;
    int i = 0;
    while(i < RIGHT_TURN_DISTANCE)
    {
        moving = true;
        motorDir(-1, velDir);
        motorEsq(1, velEsq);
        i++;
    }
}   

void motorH::motorDir(int command, int duty)
{
    switch(command) 
    {
    case 0: // ponto morto
        softPwmWrite(22, 0);
        softPwmWrite(23, 0);
        break;
    case 1: // move forward
        softPwmWrite(22, 0);
        softPwmWrite(23, duty);
        break;
    case -1: // move backwards
        softPwmWrite(22, duty);
        softPwmWrite(23, 0);
        break;
    case 2: // hard break
        softPwmWrite(22, 100);
        softPwmWrite(23, 100);
        break;
    }
}

void motorH::motorEsq(int command, int duty)
{
    switch(command) 
    {
    case 0: // ponto morto
        softPwmWrite(24, 0);
        softPwmWrite(25, 0);
        break;
    case 1: // move forward
        softPwmWrite(24, 0);
        softPwmWrite(25, duty);
        break;
    case -1: // move backwards
        softPwmWrite(24, duty);
        softPwmWrite(25, 0);
        break;
    case 2: // hard break
        softPwmWrite(24, 100);
        softPwmWrite(25, 100);
        break;
    }
}

void motorH::execute(char rxData[8])
{
}

void motorH::debug(void)  // debug function
{
    //_serial.printf("\n\resq:%d dir%d dist:%dmm",pulsoEsq,pulsoDir,getSonicDistance());
}
