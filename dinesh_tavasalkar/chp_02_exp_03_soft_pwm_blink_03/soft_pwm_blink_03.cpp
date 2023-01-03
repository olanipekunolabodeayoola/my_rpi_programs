// soft_pwm_blink_03.cpp
// d27m12y2022
// Blinking led with PWM signal
// NOTE: This implements a cleanup of wiringPi pin used
// and reset of the same at the end of the program, using
// snippet of code courtesy of M Heidenreich (2021), Rasp-
// berry Pi Beginner Guide, YouTube.
// Other helpful resources:
// Tutorialspoint.com (2022), 'Signals and Signal Handling'
// (See web archive for online article)
// Tutorialspoint.com (2022, 'Signal Handling in C++'
// (See web archive for online article)
// Also, the contributions of newbieg (including implementing mutex class)
// is acknowledged. (See citation below:)
// newbieg, ayoesquire, cplusplus.com (2022), 'Implementation of simple class
// for raspberry pi pwm blink program' (See web archive for online forum
// thread).
// (Other links are cited within the following code)
//
#include <iostream>
#include <wiringPi.h>
#include <signal.h>
#include <softPwm.h>
#include <mutex>

using std::cout;
using std::cin;
using std::endl;
using std::mutex;        // (See cplusplus.com, 'Mutex class' reference)


class CleanUpGPIOPin
{
    public:
        // (See Teach Yourself C++ in 21 days, www.101.lv/learn/C++/htm/):
        CleanUpGPIOPin();               // Constructor prototype
        ~CleanUpGPIOPin();              // Destructor "
        bool getBlink ();               // Member access fxn prototype
        void setBlink (int signal);     // "
    private:
        int blinkState;                 // Member data
};

// Class constructor declaration (By newbieg):
CleanUpGPIOPin::CleanUpGPIOPin()
{
    blinkState = 1;                 // To properly intialize class member data
}

// Class destructor declaration:
CleanUpGPIOPin::~CleanUpGPIOPin()
{
    // destruction process no action other than its intended purpose
}

// Class public methods declaration (See Horton, I., (2013) p.305):
bool CleanUpGPIOPin::getBlink()
{
    return blinkState;
}

void CleanUpGPIOPin::setBlink(int b)
{
    blinkState = b;    // Set blinkState, in this case, '0' reps 'False'

    // Clean up and reset wiringPin
    cout << "\n Commence clean up process..." << endl;
    digitalWrite(15, LOW);     // Ensure LED is turned off
    pinMode(15, INPUT);        // Reset wiringPi pin to INPUT (that is, IN)
    cout << "Clean up process complete!" << endl;
}

// Declare instance of global class object (Recall this is more secure
// than using regular global variable, although still in search for
// alternative that would not involve use of global entities however,
// will support future maintenance of program in future devs.):
CleanUpGPIOPin Regular;
mutex mtx;                  // Similarly, instantiate a mutex object
                            // on global scope

// Declare signal handling fxn:
void cleanup(int signalNum)
{
    mtx.lock();             // By newbieg
    Regular.setBlink(0);    // Access class member function through object
                            // and set blinkState to zero (0)
    mtx.unlock();         // By newbieg
}


// Main program begins:
int main(void)
{
    signal(SIGINT, cleanup);    // Call signal() fxn to capture
                                // keyboard interrupt

    wiringPiSetup();    // Call wiringPi library and numbering system
    softPwmCreate(15,0,100);    // Call function to create PWM pin

    // Initialize while loop and call class member function
    // which gets blinkState value/condition (which acts as counter)
    while(Regular.getBlink())
    {
        softPwmWrite(15, 25);    // Function to write PWM data to output
                                 // device (in this case, LED)
                                 // (where, duty cycle = 25%)

        delay(1000);             // sleep for 1000ms (1 second)
        softPwmWrite(15, 0);     // (ditto...)
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

    return 0;
}
