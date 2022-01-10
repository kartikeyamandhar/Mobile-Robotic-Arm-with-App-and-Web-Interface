import serial
from tkinter import *
import time

serialPort='COM10'
baudRate=9600
verify1=str(999)
verify2=str(666)
verify3=str(333)
verify4=str(111)

try:
    serialConnection=serial.Serial(serialPort,baudRate)
except:
    print('Cannot connect to port')
    
def ask_quit():
    root.destroy()
    serialConnection.close();
def angle1(int):
    angleData = str(slider1.get())
    print(serialConnection.write((angleData+verify2+'\n').encode()))
def angle2(int):
    angleData = str(slider2.get())
    print(serialConnection.write((angleData+verify1+'\n').encode()))
def angle3(int):
    angleData = str(slider3.get())
    print(serialConnection.write((angleData+verify3+'\n').encode()))
def angle4(int):
    angleData = str(slider4.get())
    print(serialConnection.write((angleData+verify4+'\n').encode()))
    
root=Tk()
root.protocol("WM_DELETE_WINDOW",ask_quit)
root.title('Python-Arduino')

slider1=Scale(root,from_=0,to=180,orient = HORIZONTAL,command=angle1,length=400)
slider2=Scale(root,from_=0,to=180,orient = HORIZONTAL,command=angle2,length=400)
slider3=Scale(root,from_=0,to=180,orient = HORIZONTAL,command=angle3,length=400)
slider4=Scale(root,from_=0,to=180,orient = HORIZONTAL,command=angle4,length=400)

slider1.pack()
slider2.pack()
slider3.pack()
slider4.pack()

root.minsize(500,30)
root.mainloop()