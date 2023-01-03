# rpi_servo_motor_ctrl_01_d21m10y2022.py
# Courtesy ExplainingComputers YouTube channel:
#
# Import Libraries:
import RPi.GPIO as GPIO
import time

# Set GPIO numbering mode:
GPIO.setmode(GPIO.BOARD)

# Set pin 11 as an output, and set servo1 as pin 11 as PWM
GPIO.setup(11,GPIO.OUT)
servo1 = GPIO.PWM(11,50)

# Start PWM running, but with value of 0 (pulse off)
servo1.start(0)
print ("Waiting for 2 seconds")
time.sleep(2)

# Proceed to move servo1:
print ("Rotating servo arm 180 degrees in 10 steps")

# Define variable for duty cycle:
duty = 1

# Loop for duty values from 2 to 12%
# which corresponds to (0 to 180 degrees):
while duty <= 12:
    servo1.ChangeDutyCycle(duty)
    time.sleep(1)
    duty = duty + 1

# Wait a couple of seconds:
time.sleep(2)

# Turn back to 90 degrees:
print("Turning back to 90 degrees for 2 seconds")
servo1.ChangeDutyCycle(7)
time.sleep(2)

# Turn back to 0 degrees:
print("Turning back to 0 degrees")
servo1.ChangeDutyCycle(2)
time.sleep(0.5)
servo1.ChangeDutyCycle(0)    # Not sure what this parameter "0"
			     # does or if it is neccessary.
			     # Update: It is to stop servo arm from
                             # moving by sending '0' signal.

# Stop library and clear GPIO ready for next use:
servo1.stop()
GPIO.cleanup()
print("GPIO successfully cleaned")



#
