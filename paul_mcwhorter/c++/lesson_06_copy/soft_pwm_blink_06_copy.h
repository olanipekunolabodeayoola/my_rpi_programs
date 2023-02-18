// soft_pwm_blink_06_copy.h
// d27m01y2023
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

