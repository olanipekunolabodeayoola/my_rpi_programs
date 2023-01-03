// blink_02_03.cpp
// Modification of blink in Example 1
// Modification of blink_02_02.cpp
//

#include <iostream>
#include <wiringPi.h>
#include <signal.h>

// Initialize global variable:
// int blink = 1;

// Function prototype:
int cleanup(int signal);

int main(void)
{
    int blink = cleanup(0);          // Initialize blink counter for while loop
    signal(SIGINT, cleanup);     // To capture keyboard interrupt

    wiringPiSetup();    // Call wiringPi library and numbering system
    pinMode(15, OUTPUT);    // Set GPIO pin mode

    while(blink)
    {
        digitalWrite(15, HIGH);    // Turn on LED
        delay(1000);     // sleep for 1000ms (1 seconds)
        digitalWrite(15, LOW);
        delay(1000);
    }

    // Clean up and reset GPIO pin
    digitalWrite(15, LOW);    // Ensure LED is turned off
    pinMode(15, INPUT);    // Reset GPIO pin to INPUT

    return 0;
}

// Function definition:
int cleanup(int signal)
{
    int blink = 0;
    std::cout << "\ncleanup starts..." << std::endl;
    std::cout << "cleanup ends..." << std::endl;
    return blink;
}
