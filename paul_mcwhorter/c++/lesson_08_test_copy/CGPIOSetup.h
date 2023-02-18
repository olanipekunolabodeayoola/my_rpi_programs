// CGPIOSetup.h
// d26m01y2023
//
// NOTE: This program is a class header and still
// in its developmental phase.
// It contains class definition and function prototypes
// for running the class and objects.
//
// Credits: This work is building off the foundation of
// the python version of this code is courtesy of
// Paul McWhorter (2022). Others are:
// (1.) Tavasalkar, D. (2019), "Hands-On Robotics
// Programming with C++"
// (2.) WiringPi Library online documentation (See link:
//  http://wiringpi.com/reference/core-functions/)
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
// typedef unsigned short int USHORT;
// typedef volatile sig_atomic_t VSIGATM;       // " (see newbieg (2022),
                                            // cplusplus.com)

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


// ****************************************** //
