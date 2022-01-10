# -*- coding: utf-8 -*-
"""
Created on Sun Apr 18 17:06:24 2021

@author: Kartikeya Mandhar
"""
import tkinter
import serial

def forwardButton():
    varLabel.set('Forward')
    ser.write((bytes('F','UTF-8')))
def backButton():
    varLabel.set('Backward')
    ser.write((bytes('B','UTF-8')))
def leftButton():
    varLabel.set('Leftward')
    ser.write((bytes('L','UTF-8')))
def rightButton():
    varLabel.set('Rightward')
    ser.write((bytes('R','UTF-8')))
def stopButton():
    varLabel.set('stop')
    ser.write((bytes('S','UTF-8')))
    
ser=serial.Serial('COM9',9600)
tkTop=tkinter.Tk()
tkTop.geometry('300x300')
tkTop.title("Locomaotion Control")
varLabel=tkinter.IntVar()
tkLabel=tkinter.Label(textvariable=varLabel,height=1,bd=5,bg='orange',fg='white',font=("verdana",90))
varLabel.set("Panel")
tkLabel.pack()

forward_button=tkinter.IntVar()
forward_button_state=tkinter.Button(tkTop,text="forward",command=forwardButton,height=1,width=10,bd=5,bg='yellow',fg='blue',font=("verdana",40))
#forward_button_state.pack(ipadx=10,padx=10,pady=15)

back_button=tkinter.IntVar()
back_button_state=tkinter.Button(tkTop,text="backward",command=backButton,height=1,width=8,bd=10,bg='blue',fg='white',font=("verdana",40))
#back_button_state.pack(ipadx=10,padx=10,pady=15)

stop_button=tkinter.IntVar()
stop_button_state=tkinter.Button(tkTop,text="stop",command=stopButton,height=1,width=8,bd=10,bg='black',fg='white',font=("verdana",40))
#stop_button_state.pack(ipadx=10,padx=10,pady=15)


left_button=tkinter.IntVar()
left_button_state=tkinter.Button(tkTop,text="Leftward",command=leftButton,height=1,width=10,bd=5,bg='blue',fg='white',font=("verdana",40))
#left_button_state.pack(ipadx=10,padx=10,pady=15)

right_button=tkinter.IntVar()
right_button_state=tkinter.Button(tkTop,text="Rightward",command=rightButton,height=1,width=10,bd=5,bg='yellow',fg='blue',font=("verdana",40))
#right_button_state.pack(ipadx=10,padx=10,pady=15)

forward_button_state.pack()
back_button_state.pack()
left_button_state.pack()
right_button_state.pack()
stop_button_state.pack()

tkinter.mainloop()
