import machine
import time

led1 = machine.Pin(15, machine.Pin.OUT)
led2 = machine.Pin(16, machine.Pin.OUT)

delay = 1.0
x = False
y = True
led1.value(int(x))
led2.value(int(y))

while True:
    led1.value(int(x))
    print("led1: " + str(x))
    x = y
    y = not y
    time.sleep(delay)
  
    srt = "delay = "
    
    print(srt + str(delay))
