// CGPIOCleanExit.cpp
// d26m01y2023
//
// NOTE: This program is a class implementation and
// still in its developmental phase.
// It contains the function prototypes for running
// CGPIOSetup class and objects.
//
// Credits: This is work is building off the foundation of
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
#include "CGPIOCleanExit.h"    // Include header files...

using std::cout;
using std::cin;
using std::endl;

// typedef unsigned long int ULONG;             // typedef defined (See 101.lv)
// typedef unsigned short int USHORT;
// typedef volatile sig_atomic_t VSIGATM;       // " (see newbieg (2022),
                                            // cplusplus.com)

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

// ****************************************** //
