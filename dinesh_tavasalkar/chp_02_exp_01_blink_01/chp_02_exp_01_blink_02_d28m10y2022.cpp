// chpt_02_exp_01_blink_02_d28m10y2022.cpp
// Example 01: blink.cpp
// Code to make LED turn on and off until keyboard
// is interrupted
//

//#include<iostream>
#include<wiringPi.h>

int main(void)
{
    wiringPiSetup();    // wiringPi library funtion to initialize wiringPi numbering scheme
    pinMode(15,OUTPUT);    // Setup wiringPi GPIO pin as output pin.

    for(;;)
    {
        digitalWrite(15,HIGH);    // We write a HIGH signal on the LED
        delay(1000);        // delay for 1000ms (=1 secs)
        digitalWrite(15,LOW);
        delay(1000);
    }
    return 0;
}

