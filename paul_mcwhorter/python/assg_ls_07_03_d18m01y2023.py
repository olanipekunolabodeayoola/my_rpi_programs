# assg_ls_07_03_d18m01y2023.py
# GPIOInput Internal (Built-in) pullup
# Assignment for lesoson 07
# Attempt #2:
# Used correction by Paul McWhorter lesson 08:
# Modify previous code to change push button into
# toggle switch such that it
#
# Import time module for delay:
from time import sleep

# Import GPIO library as alias:
import RPi.GPIO as GPIO
# Set pin numbering mode (in this case BOARD numbering
# system otherwise known as the physical numbering
# system, NOT BCM):
GPIO.setmode(GPIO.BOARD)

# Initialize variables:
delay = 0.1                         # Time delay (in seconds)

inPinNum = 40                     # set pin variable
outPinNum = 38                     # "

LEDState = 0                  # Initialize to zero
                              # NOTE: In C++, be
buttonState = 1               # careful to use binary
buttonStateOld = 1            # "

GPIO.setup(outPinNum, GPIO.OUT)     # set GPIO output pin

GPIO.setup(inPinNum, GPIO.IN, pull_up_down = GPIO.PUD_UP)       # set GPIO input pin

try:
    while True:
        # Read value from pin and assign to variable:
        buttonState = GPIO.input(inPinNum)   # This way,
                             # we can track whether button
                             # has been pressed or note
        print(buttonState)
        # If statements:
        if buttonState == 1 and buttonStateOld == 0:
            LEDState = not LEDState    # Switch value;
                                # Alternatively, you could
                                # if statements. Also for
                                # C**, use binary type
            # Next, line is another place where magic
            # happens with the passing of 'LEDState'
            # as an argument:
            GPIO.output(outPinNum, LEDState)

        buttonStateOld = buttonState    # Update previous
                                # state of button
        sleep(delay)            # Add delay
except KeyboardInterrupt:
    GPIO.cleanup()                 # Release GPIO pins
    print("\nGPIO pins are cleaned and released!")
