# assg_ls_04_01_d02m09y2022.py

# Import RPI Libary:
import RPi.GPIO as GPIO
# Import time module:
import time

# Setup RPI numbering system as BOARD
GPIO.setmode(GPIO.BOARD)

# Prompt user for Pin number:
pin_num = int(input("Please enter pin number: "))


# Setup RPI to use specified pin as output:
GPIO.setup(pin_num, GPIO.OUT)

# Prompt user for number of blinks:
# num_blinks = int(input("How many times do you want LED to blink for: "))


# Send signal to specified pin to turn on LED:
GPIO.output(pin_num, True)

# Add a time delay (or sleep) for LED to come on for 10 secs
# unless it will blink so fast that you will not see it
#before the program terminates):
time.sleep(10)

# Cleanup pin for next use:
GPIO.cleanup()
