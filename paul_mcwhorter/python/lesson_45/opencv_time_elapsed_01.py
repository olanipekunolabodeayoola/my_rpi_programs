# opencv_time_elapsed_01.py
# d17m10y2023
# Lesson 45 Assignment: Calculate the time elapsed between
# capturing of each frame.
# Courtesy: Paul McWhorter
# Testing OpenCV
# Program that uses camera takes a frame of image and shows a frame:
#
#
import cv2
import time

# Next open library 'picamera2':
from picamera2 import Picamera2

numOfFrames = 0    # Acts like a counter

#Create a camera object:
piCam = Picamera2()

# Set / Assign parameters, calling appropriate methods:
piCam.preview_configuration.main.size = (1280, 720)    # Specify the sixer of the image
piCam.preview_configuration.main.format = "RGB888"   # Specify the format for the video
piCam.preview_configuration.align()    # Specify to OpenCv to select the closest standard format
piCam.configure("preview")                # Apply the configurations
piCam.start()                              # Start camera

# Perorm operation with camera in while loop:
# NOTE: 30 fps
timeBegin = time.time()

while True:
    numOfFrames = numOfFrames + 1
    frame = piCam.capture_array()       # Array is a 2D matrix
    cv2.imshow("piCam", frame)

    if cv2.waitKey(1) == ord('q'):
        break

cv2.destroyAllWindows()

timeElapsed = time.time() - timeBegin    # Compute duration of time elapsed
                                         # between frame capture
fps = numOfFrames / timeElapsed

print("Time Elapsed = ", timeElapsed)
print("Number of Frames captured = ", numOfFrames)
print("Frames per second = ", fps)

