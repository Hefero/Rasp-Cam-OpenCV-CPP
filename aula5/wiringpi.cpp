//pwm1.cpp
//compila pwm1 -c -w
#include "MotorH/MotorH.cpp"
#include <wiringPi.h>
#include <softPwm.h>
int main () {
    motorH motorH;
    while(1){
        motorH.motorDir(1,100);
        motorH.motorEsq(1,100);
    }

}
