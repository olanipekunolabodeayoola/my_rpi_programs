// soft_pwm_blink_01.cpp
// d20m12y2022
// Blinking led with PWM signal
// NOTE: This implements a cleanup of wiringPi pin used
// and reset of the same at the end of the program, using
// snippet of code courtesy of M Heidenreich (2021), Rasp-
// berry Pi Beginner Guide, YouTube.
//
#include <iostream>
#include <wiringPi.h>
#include <signal.h>
#include <softPwm.h>

using std::cout;
using std::cin;
using std::endl;


class CleanUpGPIOPin
{
    public:
        bool getBlink ();               // Member access function
        void setBlink (int signal);    // Member access function
    private:
        int blinkState;            // Member data
};


// Implement class method (See Horton I (2013) p.305):
bool CleanUpGPIOPin::getBlink()
{
    return blinkState;
}

void CleanUpGPIOPin::setBlink(int b)
{
    blinkState = b;    // Set blinkState to 0 that is, false

    // Clean up and reset wiringPin
    cout << "\n Commence clean up process..." << endl;
    digitalWrite(15, LOW);     // Ensure LED is turned off
    pinMode(15, INPUT);        // Reset wiringPi pin to INPUT (that is, IN)
    cout << "Clean up process complete!" << endl;
}

void cleanup(int signal)
{
    CleanUpGPIOPin Regular;
    Regular.setBlink(0);
}


// Main program
int main(void)
{


    //cleanup = Regular.setBlink(1);

    signal(SIGINT, cleanup);    // To capture keyboard interrupt

    wiringPiSetup();    // Call wiringPi library and numbering system
    softPwmCreate(15,0,100);    // Call function to create PWM pin

    CleanUpGPIOPin Regular;
    //Regular.setBlink(1);
    cout << Regular.getBlink() << endl;
    //bool blink = Regular.getBlink();

    while(!Regular.getBlink())
    {
        softPwmWrite(15, 25);    // Function to write PWM data to output
                                 // device (in this case, LED)
                                 // (where, duty cycle = 25%)

        delay(1000);    // sleep for 1000ms (1 second)
        softPwmWrite(15, 0);
        delay(1000);
        softPwmWrite(15, 50);
        delay(1000);
        softPwmWrite(15, 0);
        delay(1000);
        softPwmWrite(15, 100);
        delay(1000);
        softPwmWrite(15, 0);
        delay(1000);
    }

    // Clean up and reset wiringPin (not to be confused with GPIO pin)
    digitalWrite(15, LOW);    // Ensure LED is turned off
    pinMode(15, INPUT);       // Reset wiringPi pin to INPUT (that is, IN)

    return 0;
}
