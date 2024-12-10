import machine
import time

led1 = machine.Pin(15, machine.Pin.OUT)
button = machine.Pin(0, machine.Pin.IN)

delay = 0.5

x = True
led1.on()


while True:
    if (button.value() != 1):
        if (x == True):
            x = False
            led1.value(int(x))
            print("On")
    else:
        if (x != True):
            x = True
            led1.value(int(x))
            print("Off")


    