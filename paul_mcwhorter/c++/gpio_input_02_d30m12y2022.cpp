// gpio_input_02.cpp
// d30m12y2022
//
// NOTE: This program reads GPIO input using a pull down resistor
// and switch.
// The python version of this code is courtesy of Paul McWhorter
// (2022), "Raspberry Pi LESSON 6: Understanding GPIO Inputs,
// Pull Up and Pull Down", YouTube.
// which I then tried to translate into C++ with the help of
// Tavasalkar, D. (2019), "Hands-On Robotics Programming with C++"
//
// Difference: Compare signal handler function header definition
// in this program with that of gpio_input_01.cpp
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
        volatile sig_atomic_t blinkState;                 // Member data
};

// Class constructor declaration (By newbieg):
CleanUpGPIOPin::CleanUpGPIOPin()
{
    blinkState = 0;                 // To properly intialize class member data
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
extern "C" void cleanup(int signalNum)
{
    mtx.lock();             // By newbieg
    Regular.setBlink(1);    // Access class member function through object
                            // and set blinkState, accordingly
    mtx.unlock();         // By newbieg
}


// Main program begins:
int main(void)
{
    signal(SIGINT, cleanup);    // Call signal() fxn to capture
                                // keyboard interrupt

    wiringPiSetup();    // Call wiringPi library and numbering system
    pinMode(29,INPUT);    // Set GPIO pin mode

    int readValue = 1;    // Initialize variable to store measured value

    // Initialize while loop and call class member function
    // which gets blinkState value/condition (which acts as counter)
    while(!Regular.getBlink())
    {
        readValue = digitalRead(29);    // Function to write PWM data to output
                                   // device (in this case, LED)
                                   // (where, duty cycle = 25%)
        cout << readValue << endl;
        delay(1000);               // sleep for 1000ms (1 second)
    }

    return 0;
}
