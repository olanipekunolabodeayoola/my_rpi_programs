# assg_ls_07_01_d15m01y2023.py
# GPIOInput Internal (Built-in) pullup
# 
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

GPIO.setup(outPinNum, GPIO.OUT)     # set GPIO output pin

GPIO.setup(inPinNum, GPIO.IN, pull_up_down = GPIO.PUD_UP)       # set GPIO input pin

try:
    while True:
        # Read value from pin and assign to variable:
        readVal = GPIO.input(inPinNum)
        print(readVal)
        # If statements:
        if readVal == 1:
            GPIO.output(outPinNum, 0)
        if readVal == 0:
            GPIO.output(outPinNum, 1)
        # Add a time delay:
        sleep(delay)
except KeyboardInterrupt:
    GPIO.cleanup()                 # Release GPIO pins
    print("\nGPIO pins are cleaned and released!")
