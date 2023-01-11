// gpio_input_pullup_03.cpp
// d30m12y2022
//
// NOTE: This program controls another circuit with an LED
// by reading from the GPIO input of the previous circuit
// using a pull up resistor and switch.
// The python version of this code is courtesy of Paul McWhorter
// (2022), "Raspberry Pi LESSON 6: Understanding GPIO Inputs,
// Pull Up and Pull Down", YouTube.
// which I then tried to translate into C++ with the help of
// Tavasalkar, D. (2019), "Hands-On Robotics Programming with C++"
//
// Difference(s):
// (1.) Changed name of the other class from 'CleanUpGPIOPin'
// to 'CleanupGPIOPin' (NOTE: letter 'U' in upper case apart
// from letter 'u' lower case)
//
// (2.)
//
//
//
#include <iostream>
#include <wiringPi.h>
#include <signal.h>

using std::cout;
using std::cin;
using std::endl;


class CleanupGPIOPin
{
    public:
        // (See Teach Yourself C++ in 21 days, www.101.lv/learn/C++/htm/):
        CleanupGPIOPin();               // Constructor prototype
        ~CleanupGPIOPin();              // Destructor "
        bool getBlink ();               // Member access fxn prototype
        void setBlink (int signal);     // "
    private:
        volatile sig_atomic_t blinkState;                 // Member data
};

// Class constructor declaration (By newbieg):
CleanupGPIOPin::CleanupGPIOPin()
{
    blinkState = 0;                 // To properly intialize class member data
}

// Class destructor declaration:
CleanupGPIOPin::~CleanupGPIOPin()
{
    // destruction process no action other than its intended purpose
}

// Class public methods declaration (See Horton, I., (2013) p.305):
bool CleanupGPIOPin::getBlink()
{
    return blinkState;
}

void CleanupGPIOPin::setBlink(int b)
{
    blinkState = b;    // Set blinkState, in this case, '0' reps 'False'

    // Clean up and reset wiringPin
    cout << "\nCommence clean up process..." << endl;
    digitalWrite(29, LOW);     // Ensure LED is turned off
    pinMode(29, INPUT);        // Reset wiringPi pin to INPUT (that is, IN)
    digitalWrite(28, LOW);     // ditto
    pinMode(28, INPUT);        // ditto
    cout << "Clean up process complete!" << endl;
}

// Declare instance of global class object (Recall this is more secure
// than using regular global variable, although still in search for
// alternative that would not involve use of global entities however,
// will support future maintenance of program in future devs.):
CleanupGPIOPin Regular;

// Declare signal handling fxn:
void cKeyboardInterrupt(int signalNum)
{
    Regular.setBlink(1);    // Access class member function through object
                            // and set blinkState, accordingly
}


// Main program begins:
int main(void)
{
    signal(SIGINT, cKeyboardInterrupt);    // Call signal() fxn to capture
                                           // keyboard interrupt

    wiringPiSetup();    // Call wiringPi library and numbering system
    pinMode(29,INPUT);    // Set GPIO pin mode
    pinMode(28,OUTPUT);

    unsigned short int readValue = 1;    // Initialize variable to store
                                         // measured value

    // Initialize while loop and call class member function
    // which gets blinkState value/condition (which acts as counter)
    while(!Regular.getBlink())
    {
        readValue = digitalRead(29);    // Read value from pin specified
        cout << readValue << endl;      // Print read value to screen
        // If statments:
        if (readValue == 1)             // Check if switch is open
        {
            digitalWrite(28,LOW);       // Turn LED OFF
            delay(100);                // sleep for 100ms (0.1 second)
        }
        if (readValue == 0)             // Check if switch is closed
        {
            digitalWrite(28,HIGH);     // Turn LED ON
            delay(100);                // sleep for 0.1 sec.
        }
    }

    return 0;
}
