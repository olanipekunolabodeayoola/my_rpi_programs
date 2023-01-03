# rpi_servo_motor_ctrl_03_d21m10y2022.py
# Courtesy ExplainingComputers YouTube channel.
# Modified program as follows:
# 1.) To receive input from user as angle
# (rather than  duty cycle) and,
# 2.) To implement keyboard interruption using
# try exceptions. That way, it can correctly stop
# servo (servo.stop) and free-up GPIO pins (GPIO.cleanup)
# towards next use.
#
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

# Loop to prompt user to set servo angle (0 to 180 degrees)
# using try--finally to allow exit with execution of servo.stop
try:
    while True:
        # Prompts user to enter angle and rotate servo arm:
        angle = float(input('Enter angle between 0 - 180 degrees: '))
        # Convert angle to corresponding duty cycle and pass as
        # parameter in ChangeDutyCycle() member function:
        servo1.ChangeDutyCycle(2+(angle/18))
        time.sleep(0.5)
        servo1.ChangeDutyCycle(0)    # Send '0' (i.e. no signal) to
                                     # stop servo arm from moving

finally:
    print ("\nWait a moment...")
    time.sleep(1)
    servo1.ChangeDutyCycle(2)    # Return back to starting position
    servo1.ChangeDutyCycle(0)    # Stop servo arm moving
    # Stop servo library (instance) and free-up GPIO pins:
    servo1.stop()
    GPIO.cleanup()
    print ("GPIO successfully cleaned")
    print ("Exit program")



#


