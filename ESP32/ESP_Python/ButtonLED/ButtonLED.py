'''
Name        : ButtonLED.py
Date        : 25/Apr/2023
Brief       : Turn on onboard LED when onboard button is pressed.
Tested      : OK
Developer   : Rohit Akurdekar
'''

from machine import Pin     # module for board methods

'''
Name    : ledOnbuttonPress()
Params  : LED pin number, BUTTON pin number
Default : led = 2 , button = 0
Brief   : Turn on onboard LED when onboard button is pressed.
Tested  : OK
'''
def ledOnbuttonPress(led=2,button=0):
    LED = Pin(led,Pin.OUT)
    BUTTON = Pin(button,Pin.IN)
    if BUTTON.value() == 0:
        LED.value(1)
        print("Button pressed and LED turned ON")
    else:
        LED.value(0)


if __name__ == "__main__":
    while True:
        ledOnbuttonPress()