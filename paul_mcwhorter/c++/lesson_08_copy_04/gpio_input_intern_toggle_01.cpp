// gpio_input_internal_01...cpp
// d17m02y2023
// Purpose: Source code for client code
//
// NOTE: This program is a variant of the previous one in
// lesson 09. However, unlike the previous, it uses a
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
#include <iostream>
#include <wiringPi.h>
#include <signal.h>
#include "CGPIOCleanExit.h"    // Include files
#include "CGPIOSetup.h"

using std::cout;
using std::cin;
using std::endl;

typedef unsigned long int ULONG;             // typedef defined (See 101.lv)
typedef unsigned short int USHORT;
typedef volatile sig_atomic_t VSIGATM;       // " (see newbieg (2022),
                                            // cplusplus.com)
// ****************************************** //

// Declare instance of global class object (Recall this is more secure
// than using regular global variable, although still in search for
// alternative that would not involve use of global entities however,
// will support future maintenance of program in future devs.):
CGPIOCleanExit Regular;


// Declare signal handling fxn:
void cKeyboardInterrupt(int signalNum)
{
  //CGPIOCleanExit Regular;
    Regular.setBlink(1);    // Access class member function through object
                            // and set blinkState, accordingly
}


// Main program begins:
int main(void)
{
    signal(SIGINT, cKeyboardInterrupt);    // Call signal() fxn to capture
                                           // keyboard interrupt

    wiringPiSetup();    // Call wiringPi library and numbering system
    //CGPIOCleanExit Regular;
    //Regular.setBlink(0);
    //cout << Regular.getBlink() << endl;


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

    pullUpDnControl(pin1, PUD_UP);    // Set GPIO pin to pull-up resistor
                                        // (See wiringpi.com for more details)
    // Initialize variable to store measured value:
    // NOTE: 'readValue' in previous code has been replaced
    // by 'buttonState':
    USHORT buttonState = 1, buttonStateOld = 1, LEDState = 0;

    // Initialize while loop and call class member function
    // which gets blinkState value/condition (which acts as counter)
    while(!Regular.getBlink())
    {
        buttonState = digitalRead(pin1);    // Read value from pin specified
        cout << buttonState << endl;      // Print read value to screen
        // If statments:
	// Check previous and current state:
        if ((buttonState == 1) && (buttonStateOld == 0))
        {
	    if (LEDState == 0)         // Recall, relation operators
	    {
	        LEDState = 1;    // return 1 (true) or 0 (false) (See 101.lv/learn/C
		// The next line is another place where the magic happens!:
	        // See where 'LEDState' from previous line is passed as
	        // an argument:
                digitalWrite(pin2,LEDState);       // Turn ON/OFF depending on
	                                           // 'LEDState'
	    }
	    else
	    {
	        LEDState = 0;
		digitalWrite(pin2,LEDState);
	    }
	    
        }

	buttonStateOld = buttonState;      // Update previous state of
	                                   // button
        delay(100);                // sleep for 100ms (0.1 second)
    }

    return 0;
}
