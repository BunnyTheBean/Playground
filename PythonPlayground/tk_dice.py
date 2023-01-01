import tkinter as tk
import random
from dice_distribution import DiceDistribution

class DiceFrame(tk.Frame):
    def __init__(self, parent):
        super().__init__(parent)
        self.createWidgets()
    
    def createWidgets(self):
        self.countLabel = tk.Label(text="count:")
        self.countLabel.pack()
        self.count = tk.StringVar(value="3")
        self.countEntry = tk.Entry(textvariable=self.count)
        self.countEntry.pack()

        self.sidesLabel = tk.Label(text="sides:")
        self.sidesLabel.pack()
        self.sides = tk.StringVar(value="6")
        self.sidesEntry = tk.Entry(textvariable=self.sides)
        self.sidesEntry.pack()

        self.rollButton = tk.Button(text="Roll!")
        self.rollButton["command"] = self.roll
        self.rollButton.pack()

        self.result = tk.StringVar(value="result: ...")
        self.resultLabel = tk.Label(textvariable=self.result)
        self.resultLabel.pack()

        self.resultOrLower = tk.StringVar(value="... or lower: ...%")
        self.resultOrLowerLabel = tk.Label(textvariable=self.resultOrLower)
        self.resultOrLowerLabel.pack()
        
        self.resultOrHigher = tk.StringVar(value="... or higher: ...%")
        self.resultOrHigherLabel = tk.Label(textvariable=self.resultOrHigher)
        self.resultOrHigherLabel.pack()

    def roll(self):
        try:
            count = int(self.count.get())
            sides = int(self.sides.get())
            distribution = DiceDistribution(count, sides)

            result = distribution.roll()
            self.result.set(f"result: {result}")

            lowerProbability = distribution.probability_of_range(count, result)
            higherProbability = distribution.probability_of_range(result, count * sides)
            self.resultOrLower.set(f"Chance of {result} or lower: {round(lowerProbability * 100, 2)}%")
            self.resultOrHigher.set(f"Chance of {result} or higher: {round(higherProbability * 100, 2)}%")
        except:
            self.result.set("INVALID INPUTS!")
            self.resultOrLower.set("Please make sure to")
            self.resultOrHigher.set("only input integer numbers!")

def main():
    root = tk.Tk()
    frame = DiceFrame(root)
    frame.mainloop()

if __name__ == "__main__":
    main()
