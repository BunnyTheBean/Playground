import tkinter as tk

class MyApp(tk.Frame):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.pack()
        self.createWidgets()
        self.createBindings()
    
    def createWidgets(self):
        self.label = tk.Label(self)
        self.label.pack()
        self.label["text"] = "Bitte sende ein Event"
        self.entry = tk.Entry(self)
        self.entry.pack()
        self.ok = tk.Button(self)
        self.ok.pack()
        self.ok["text"] = "Beenden"
        self.ok["command"] = self.quit

    def createBindings(self):
        self.entry.bind("Entenhausen", self.eventEntenhausen)
        self.entry.bind("<ButtonPress-1>", self.eventMouseClick)
        self.entry.bind("<MouseWheel>", self.eventMouseWheel)

    def eventEntenhausen(self, event):
        self.label["text"] = "Sie kennen das geheime Passwort!"

    def eventMouseClick(self, event):
        self.label["text"] = "Mausklick an Position ({} {})".format(event.x, event.y)

    def eventMouseWheel(self, event):
        if event.delta < 0:
            self.label["text"] = "Bitte bewegen sie das Mausrad in die richtige Richtung."
        else:
            self.label["text"] = "Dankeschön :3"

root = tk.Tk()
root.geometry("300x200+500+100")
app = MyApp(root)
app.mainloop()