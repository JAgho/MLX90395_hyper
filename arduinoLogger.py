# Read Arduino Serial Output
# also see: projecthub.arduino.cc/ansh2919/serial-communication-between-python-and-arduino-663756

# >>pip install pyserial 
import serial
import time
from datetime import datetime
import numpy as np

arduino = serial.Serial(port='COM4', baudrate=115200, timeout=0.1)
pollingDelay = 0.05 # time between polling Arduino

N = 1000
data = np.zeros(N)

for i in range(N):
    time.sleep(pollingDelay)
    dataPoint = arduino.readline()
    data[i] = ((datetime.now(), dataPoint))
    print(dataPoint)
