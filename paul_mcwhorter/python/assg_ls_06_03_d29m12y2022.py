# assg_ls_06_03_d29m12y2022.py
# GPIOInput
#
# Import GPIO library as alias:
import RPi.GPIO as GPIO
# From time library, import sleep module, thus
# instead of writing time.sleep(), you can write
# sleep():
from time import sleep

# Set pin numbering mode (in this case BOARD numbering
# system otherwise known as the physical numbering
# system, NOT BCM):
GPIO.setmode(GPIO.BOARD)

inputPinNum = 40                     # set pin variable
GPIO.setup(inputPinNum, GPIO.IN)     # set GPIO pin
counter = 1

# Implement try-except block:
try:
    while counter:
        readVal = GPIO.input(inputPinNum)    # Read value from pin
        print(readVal)    # Print value read from pin
        sleep(1) # Add 1 second delay before next reading
except KeyboardInterrupt:
    GPIO.cleanup()    # Cleanup GPIO pin
    print("\n")         # Print newline
