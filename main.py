import time
import serial
import pyautogui as pag
import webbrowser
import matplotlib.pyplot as plt

ser = serial.Serial(
    port='COM3',\
    baudrate=9600,\
    parity=serial.PARITY_NONE,\
    timeout=1)


webbrowser.open("https://www.crazygames.com/game/knife-hit")
pag.moveTo(1000, 500,duration=2)
pag.click()
pag.moveTo(760,320,duration=3)
pag.click()
print("connected to: " + ser.portstr)
count=1
string = "1"
while True:
    bla = ser.readline()
    if(bla.decode('utf-8') == ''):
        continue
    else:
        if bla.decode('utf-8').strip() == "1":
            pag.click()
        else:

            continue


ser.close()