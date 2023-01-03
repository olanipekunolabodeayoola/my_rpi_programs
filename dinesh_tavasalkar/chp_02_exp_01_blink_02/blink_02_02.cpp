// blink_02_02.cpp
// Modification of blink in Example 1
//

#include <iostream>
#include <wiringPi.h>
#include <signal.h>

// Function prototype:
void cleanup(int &b);

int main(void)
{
    int blink = 1;          // Initialize blink counter for while loop
    signal(SIGINT, cleanup);     // To capture keyboard interrupt

    wiringPiSetup();    // Call wiringPi library and numbering system
    pinMode(15, OUTPUT);    // Set GPIO pin mode

    while(blink)
    {
        digitalWrite(15, HIGH);    // Turn on LED
        delay(1000);     // sleep for 1000ms (1 second)
        digitalWrite(15, LOW);
        delay(1000);
    }

    // Clean up and reset wiringPi pin (not to be confused with GPIO pin)
    digitalWrite(15, LOW);    // Ensure LED is turned off
    pinMode(15, INPUT);    // Reset wiringPi pin to INPUT

    return 0;
}

// Function definition:
void cleanup(int &rsignal, int &rblink)
{
    int blink = 0;
    std::cout << "\ncleanup starts..." << std::endl;
    rblink = blink;
    std::cout << "cleanup ends..." << std::endl;
}
