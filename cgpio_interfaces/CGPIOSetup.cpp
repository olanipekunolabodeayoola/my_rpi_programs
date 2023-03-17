// CGPIOSetup.cpp
// d26m01y2023
//
// NOTE: This program is a class implementation and
// still in its developmental phase.
// It contains the function prototypes for running
// the class and objects.
//
// Credits: This work is building off the foundation of
// the python version of this code is courtesy of
// Paul McWhorter (2022), Others are:
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
#include "CGPIOSetup.h"    // Include header files...

using std::cout;
using std::cin;
using std::endl;

typedef unsigned long int ULONG;             // typedef defined (See 101.lv)
// typedef unsigned short int USHORT;
// typedef volatile sig_atomic_t VSIGATM;       // " (see newbieg (2022),
                                            // cplusplus.com)


// ********************************************* //

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
