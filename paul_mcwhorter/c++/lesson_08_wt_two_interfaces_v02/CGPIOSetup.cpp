// CGPIOSetup.cpp
// d17m02y2023
// Purpose: Class header interface #02
//
// NOTE: This program is a variant of the previous one in
// lesson 08_copy_04. However, unlike the previous, it uses a
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
#include "CGPIOSetup.h"                    // Include file

using std::cout;
using std::cin;
using std::endl;

typedef unsigned long int ULONG;             // typedef defined (See 101.lv)
typedef unsigned short int USHORT;
typedef volatile sig_atomic_t VSIGATM;       // " (see newbieg (2022),
                                            // cplusplus.com)

// Class constructor declaration (See Horton, I (2013), p. 291)
// NOTE: DO NOT initialize definition with default values when and where
// member function is defined separately. Instead, initialize with
// default value in the declaration of fxn prototype (see class header)
// (Courtesy: seeplus, cplusplus.com (2023))
// WARNING: Check GPIO pin is safely connected!
CGPIOSetup::CGPIOSetup(int pnval)   // pnval = pinNumber value
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
