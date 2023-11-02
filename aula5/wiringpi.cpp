//pwm1.cpp
//compila pwm1 -c -w
#include "MotorH/MotorH.cpp"
#include <wiringPi.h>
#include <softPwm.h>
int main () {
    motorH motor;
    motor.moveForward();
}
