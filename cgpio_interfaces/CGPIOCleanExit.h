// CGPIOCleanExit.h
// d26m01y2023
//
// NOTE: This program is a class header and still
// in its developmental phase.
// It contains class definition the function prototypes
// for running the class and objects.
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

using std::cout;
using std::cin;
using std::endl;

// typedef unsigned long int ULONG;             // typedef defined (See 101.lv)
// typedef unsigned short int USHORT;
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
