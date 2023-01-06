import tkinter as tk

class InnerFrame(tk.Frame):
    pass

# class MiddleFrame(tk.Frame):
#     def __init__(self, parent):
#         super().__init__(master=parent)
#         self.configure(background="red")
#         self.label1 = tk.Label(master=self, text="AAAH!!", foreground="red")
#         self.label1.pack()

class MiddleFrame(tk.Frame):
    def __init__(self, parent):
        super().__init__(master=parent)
        self.rowconfigure(index=0)
        self.rowconfigure(index=1)
        self.rowconfigure(index=2)
        self.columnconfigure(index=0)
        self.columnconfigure(index=1)
        self.columnconfigure(index=2)
        for i in range(3):
            for j in range(3):
                label = tk.Label(master=self, background=f"#{i*2}{j*2}0")
                label.grid(row=i, column=j, ipadx=25, ipady=22)

class OuterFrame(tk.Frame):
    def __init__(self, parent):
        super().__init__(master=parent)
        self.pack()
        self.rowconfigure(index=0)
        self.rowconfigure(index=1)
        self.rowconfigure(index=2)
        self.columnconfigure(index=0)
        self.columnconfigure(index=1)
        self.columnconfigure(index=2)
        for i in range(3):
            for j in range(3):
                if i == 1 and j == 1:
                    middleframe = MiddleFrame(parent=self)
                    middleframe.grid(row=i, column=j)
                else:
                    label = tk.Label(master=self, background=f"#{i*3}{j*3}c")
                    label.grid(row=i, column=j, ipadx=100, ipady=100)


root = tk.Tk()
frame = OuterFrame(root)
root.mainloop()