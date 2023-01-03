# assg_ls_04_01_d02m09y2022.py

# Import RPI Libary:
import RPi.GPIO as GPIO
# Import time module:
import time

# Setup RPI numbering system as BOARD
GPIO.setmode(GPIO.BOARD)

# Prompt user for Pin number:
pin_num = int(input("Please enter pin number: "))

# Prompt user for number of blinks:
num_blinks = int(input("How many times do you want LED to blink for: "))

# Setup RPI to use specified pin as output:
GPIO.setup(pin_num, GPIO.OUT)

for blink in range(0, num_blinks):
	GPIO.output(pin_num,1)    # Turn on LED
	time.sleep(1)    # Add a time delay
	GPIO.output(pin_num,0)    #  Turn off LED
	time.sleep(1)    # (ditto, i.e. Wait)

# Cleanup pin for next use:
GPIO.cleanup()
