from pyautogui import *
import pyautogui
import random
import win32api,win32con
import time
import pyperclip as pc
import os 
import keyboard

time.sleep(5)

def click(x,y):
    win32api.SetCursorPos((x,y))
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN, 0, 0)
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP, 0, 0)

# pyautogui.displayMousePosition()
# exit()

# #for 30% zoom
# lis = list(pyautogui.locateAllOnScreen('1smolsolved.png'))
# lis1 = list(pyautogui.locateAllOnScreen('1smolcontinue.png'))

#for 100% zoom
lis = list(pyautogui.locateAllOnScreen('1bsolved.png',grayscale=True,confidence=0.95))
lis1 = list(pyautogui.locateAllOnScreen('1continue.png'))

while keyboard.is_pressed('q')==False:
    for tup in lis:
        x,y,w,h=tup
        x=x+int(w/2)
        y=y+int(h/2)
        click(x,y)
        time.sleep(1.5)
        click(1500,83)
        pyautogui.hotkey('ctrl', 'c')
        time.sleep(1.5)
        url = pc.paste()
        name=url.split('/problems/')[-1]
        name=name+'.cpp'
        if os.path.exists(name):
            pyautogui.hotkey('ctrl', 'w')
            time.sleep(1.5)
            continue
        else:
            f=open(name,'x')
            # #for 33% zoom
            # click(111,157)    #My submissions
            # time.sleep(1.5)
            # click(835,222)    #View
            # time.sleep(1.5)
            # click(1220,158)   #Copy
            # time.sleep(1.5)
            #for 100% zoom
            click(326,268)  # My submissions
            time.sleep(1.5)
            click(865,542)    #View
            time.sleep(1.5)
            click(1727,257)   #Copy
            time.sleep(1.5)
            pyautogui.hotkey('ctrl', 'w')
            time.sleep(1.5)
            text = pc.paste()
            f.write(text)
            f.close()

    for tup in lis1:
        x, y, w, h = tup
        x = x+int(w/2)
        y = y+int(h/2)
        click(x, y)
        time.sleep(1.5)
        click(1500, 83)
        pyautogui.hotkey('ctrl', 'c')
        time.sleep(1.5)
        url = pc.paste()
        name = url.split('/problems/')[-1]
        name = name+'.cpp'
        if os.path.exists(name):
            pyautogui.hotkey('ctrl', 'w')
            time.sleep(1.5)
            continue
        else:
            f = open(name, 'x')
            # #for 33% zoom
            # click(111,157)    #My submissions
            # time.sleep(1.5)
            # click(835,222)    #View
            # time.sleep(1.5)
            # click(1220,158)   #Copy
            # time.sleep(1.5)
            #for 100% zoom
            click(326, 268)  # My submissions
            time.sleep(1.5)
            click(865, 542)  # View
            time.sleep(1.5)
            click(1727, 257)  # Copy
            time.sleep(1.5)
            pyautogui.hotkey('ctrl', 'w')
            time.sleep(1.5)
            text = pc.paste()
            f.write(text)
            f.close()