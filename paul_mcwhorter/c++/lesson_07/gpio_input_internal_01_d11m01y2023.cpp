// gpio_input_pullup_08.cpp
// d31m12y2022
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
// (1.) Further modification of CGPIOSetup class
//
// (2.) Included user-defined default values for CGPIOSetup constructor
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

// ****************************************** //

// Declare instance of global class object (Recall this is more secure
// than using regular global variable, although still in search for
// alternative that would not involve use of global entities however,
// will support future maintenance of program in future devs.):
CGPIOCleanExit Regular;

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

    const int totalPins {2};    // Total number of pins. NOTE:
                              // without modifier const, that compiler will
                             // issue an error while trying to initialize
                             // array in the next line

    // CGPIOSetup Pins[2];
    CGPIOSetup Pins[totalPins - 1];       // Declare array of size =
                                          // number of elements - 1
    Pins[0].setInputPin(29);        // Initialize element of array
    Pins[1].setInputPin(28);        //  with appropriate pin number

    int pin1 = Pins[0].getInputPin();    // Define and initialize pin
    int pin2 = Pins[1].getInputPin();    // with appropriate pin number

    pinMode(pin1,INPUT);    // Set GPIO pin mode
    pinMode(pin2,OUTPUT);

    USHORT readValue = 1;    // Initialize variable to store
                                         // measured value

    // Initialize while loop and call class member function
    // which gets blinkState value/condition (which acts as counter)
    while(!Regular.getBlink())
    {
        readValue = digitalRead(pin1);    // Read value from pin specified
        cout << readValue << endl;      // Print read value to screen
        // If statments:
        if (readValue == 1)             // Check if switch is open
        {
            digitalWrite(pin2,LOW);       // Turn LED OFF
            delay(100);                // sleep for 100ms (0.1 second)
        }
        if (readValue == 0)             // Check if switch is closed
        {
            digitalWrite(pin2,HIGH);     // Turn LED ON
            delay(100);                // sleep for 0.1 sec.
        }
    }

    return 0;
}
