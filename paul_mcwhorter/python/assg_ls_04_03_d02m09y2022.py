# assg_ls_04_03_d02m09y2022.py
# Modify assg_ls_04_02_d02m09y2022.py
# Add a while loop to make user control program flow

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

# Define user prompt:
prompt = 'y'

# Add while loo:
while prompt=='y':
	for blink in range(0, num_blinks):
		GPIO.output(pin_num,1)    # Turn on LED
		time.sleep(1)    # Add a time delay
		GPIO.output(pin_num,0)    #  Turn off LED
		time.sleep(1)    # (ditto, i.e. Wait)
	prompt = input("If you would like to continue, enter 'y' for 'yes' or any other key for 'no': ")

# Cleanup pin for next use:
GPIO.cleanup()
