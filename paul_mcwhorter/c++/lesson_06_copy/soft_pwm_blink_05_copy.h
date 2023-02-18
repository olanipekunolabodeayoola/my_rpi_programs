// soft_pwm_blink_05_copy.h
// d27m01y2023
// Purpose: Class header interface and implementation
//
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
        int getBlink ();               // Member access function
        void setBlink ();    // Member access function
    private:
        int blinkState;            // Member data
};


// Implement class method:
int CleanUpGPIOPin::getBlink()
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
