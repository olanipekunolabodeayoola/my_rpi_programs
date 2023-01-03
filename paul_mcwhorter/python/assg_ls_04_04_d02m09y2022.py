# assg_ls_04_04_d02m09y2022.py
# Modify assg_ls_04_02_d02m09y2022.py
# Add a while loop to make user control program flow

# Import RPI Libary:
import RPi.GPIO as GPIO
# Import time module:
import time

# Setup RPI numbering system as BOARD
GPIO.setmode(GPIO.BOARD)

# Prompt user for Pin number:
# pin_num = int(input("Please enter pin number: "))

# Prompt user for number of blinks:
# num_blinks = int(input("How many times do you want LED to blink for: "))
num_blinks = 1

# Setup RPI to use specified pin(s) as output:
GPIO.setup(10, GPIO.OUT)
GPIO.setup(12, GPIO.OUT)
GPIO.setup(13, GPIO.OUT)
GPIO.setup(15, GPIO.OUT)
GPIO.setup(11, GPIO.OUT)

# Define user prompt:
# prompt = 'y'

# Add while loo:
# while prompt=='y':
for blink in range(0, num_blinks):
	# Number 1:
	GPIO.output(10,0)    # Turn off LED
	GPIO.output(12,0)
	GPIO.output(13,0)
	GPIO.output(15,0)
	GPIO.output(11,1)    # Turn on LED
	time.sleep(1)    # Add a time delay
	# Number 2:
	GPIO.output(10,0)    #  Turn off LED
	GPIO.output(12,0)
	GPIO.output(13,0)
	GPIO.output(15,1)
	GPIO.output(11,0)
	time.sleep(1)    # (ditto, i.e. Wait)
	# Number 3:
	GPIO.output(10,0)
	GPIO.output(12,0)
	GPIO.output(13,0)
	GPIO.output(15,1)
	GPIO.output(11,1)
	time.sleep(1)
	# Number 4:
	GPIO.output(10,0)
	GPIO.output(12,0)
	GPIO.output(13,1)
	GPIO.output(15,0)
	GPIO.output(11,0)
	time.sleep(1)
	# Number 5:
	GPIO.output(10,0)
	GPIO.output(12,0)
	GPIO.output(13,1)
	GPIO.output(15,0)
	GPIO.output(11,1)
	time.sleep(1)

# Cleanup pin for next use:
GPIO.cleanup()
