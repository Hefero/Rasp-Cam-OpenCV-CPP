#ifndef MOTORH_H
#define MOTORH_H

#include <wiringPi.h>
#include <softPwm.h>


class motorH
{
    public:
        motorH();
        void motorDir(int command, int duty);
        void motorEsq(int command, int duty);
        void moveForward();
        void moveBackwards();
        void turnLeft();
        void turnRight();
        void stop();
        void hardStop();
        void execute(char rxData[8]);
        void debug();
        bool moving = false;
};
#endif