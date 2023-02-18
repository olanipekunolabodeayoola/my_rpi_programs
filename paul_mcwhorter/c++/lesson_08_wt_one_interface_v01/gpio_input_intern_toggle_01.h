// gpio_input_internal_01...h
// d27m01y2023
// Purpose: Class header interface
//
// NOTE: This program is a variant of the previous one in
// lesson 07. However, unlike the previous, it uses a
// toggle switch, as opposed to push button, as well as an
// internal (built-in) pull up resistor to control
// the other circuit with an LED by reading from the GPIO
// input of the previous circuit.
//
// Again, the python version of this code is courtesy of
// Paul McWhorter (2022), "Raspberry Pi LESSON 8: Using
// a button as a Toggle Switch for LED Control", YouTube.
// which I then tried to translate into C++ with help from
// (1.) Tavasalkar, D. (2019), "Hands-On Robotics
// Programming with C++"
// (2.) WiringPi Library online documentation (See link:
//  http://wiringpi.com/reference/core-functions/) and
// function 'void pullUpDnControl(int pin, int pud);'
//
//
//
#include <iostream>
#include <wiringPi.h>
#include <signal.h>

using std::cout;
using std::cin;
using std::endl;

typedef unsigned long int ULONG;             // typedef defined (See 101.lv)
typedef unsigned short int USHORT;
typedef volatile sig_atomic_t VSIGATM;       // " (see newbieg (2022),
                                            // cplusplus.com)

class CGPIOCleanExit
{
    public:
        // (See Teach Yourself C++ in 21 days, www.101.lv/learn/C++/htm/):
        CGPIOCleanExit();                 // Constructor prototype
        ~CGPIOCleanExit();                // Destructor "
        bool getBlink ();                 // Member access fxn prototype
        void setBlink (int signal);       // " (aka public accessor method)
    private:
        // Member data:
        VSIGATM m_BlinkState;            // blink status/condition
};

// Class constructor declaration (See Horton, I (2013), p. 291)
CGPIOCleanExit::CGPIOCleanExit()
{
    cout << "CGPIOCleanExit constructor initialized...\n";
    m_BlinkState = 0;              // To properly intialize class member data
}

// Class destructor declaration:
CGPIOCleanExit::~CGPIOCleanExit()
{
    // destruction process no action other than its intended purpose
    cout << "CGPIOCleanExit destructor initialized...\n";
}

// Class public methods declaration (For fxn type, 'bool'
// see sample in Horton, I., (2013), p.305):
bool CGPIOCleanExit::getBlink()
{
    return m_BlinkState;
}

void CGPIOCleanExit::setBlink(int b)
{
    m_BlinkState = b;    // Set m_BlinkState, in this case, '0' reps 'False'

    // Clean up and reset wiringPin
    cout << "\nCommence clean up process..." << endl;
    digitalWrite(29, LOW);     // Reset pin to zero (0)
    pinMode(28, INPUT);        // Reset pin to INPUT (that is, IN)
    digitalWrite(28, LOW);     // ditto
    pinMode(28, INPUT);        // ditto
    cout << "Clean up process complete!" << endl;
}


// ********************************************* //
// Class for GPIO:
class CGPIOSetup
{
    public:
        // (See Teach Yourself C++ in 21 days, www.101.lv/learn/C++/htm/):
        CGPIOSetup(int pnval);                 // Constructor prototype
        ~CGPIOSetup();                // Destructor "
        // Member access fxn prototype
        // " (aka public accessor method)
        ULONG getInputPin() const;       // A constant member function
                   // takes no argument and does not change member data of class
                   // thus, const modifier (See Array Listing 11.4 and
                   // Classes Listing 06 101.lv/learn/C++)
        void setInputPin(int pinNumber);     // "
    private:
        // Member data:
        int m_PinNumber;                // pin number
};

// Class constructor declaration (See Horton, I (2013), p. 291)
// Initialized with default values (where,
// pnval = 29 corresponds to GPIO wiringPi pin #29)
// WARNING: Check GPIO pin is safely connected!
CGPIOSetup::CGPIOSetup(int pnval = 29)   // pnval = pinNumber value
{
    cout << "CGPIOSetup constructor initialized...\n";
    m_PinNumber = pnval;            // To properly intialize class member data
}

// Class destructor declaration:
CGPIOSetup::~CGPIOSetup()
{
    // destruction process no action other than its intended purpose
    cout << "CGPIOSetup destructor initialized...\n";
}

// Class public methods declaration (For fxn type, 'bool'
// see sample in Horton, I., (2013), p.305):
// getInputPin public accessor fxn defn:
ULONG CGPIOSetup::getInputPin() const
{
    return m_PinNumber;
}

// setOutputPin public accessor fxn defn:
void CGPIOSetup::setInputPin(int pinNumber)
{
    m_PinNumber = pinNumber;    // Initialize with value passed
}

