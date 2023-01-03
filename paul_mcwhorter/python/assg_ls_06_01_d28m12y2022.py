# assg_ls_06_01_d28m12y2022.py
# GPIOInput
#
# Import GPIO library as alias:
import RPi.GPIO as GPIO

# Set pin numbering mode (in this case BOARD numbering
# system otherwise known as the physical numbering
# system, NOT BCM):
GPIO.setmode(GPIO.BOARD)

inputPinNum = 40                     # set pin variable
GPIO.setup(inputPinNum, GPIO.IN)     # set GPIO pin

# Read value from pin and assign to variable:
readVal = GPIO.input(inputPinNum)

# Print value read from pin:
print(readVal)

# Cleanup GPIO pin:
GPIO.cleanup()
