import tkinter as tk
from dice_distribution import DiceDistribution

class DiceRollGui:
    

    def __init__(self):
        self.root = tk.Tk()
        self.root.title("Bunny's Rusty Ol' Rollin' Machine")
        self.create_widgets()
        self.create_bindings()
        self.configure_fonts()
        self.configure_layout()
        self.configure_geometry()
        self.root.mainloop()
    
    def create_widgets(self):
        self.dice_label_frame = tk.LabelFrame(master=self.root, text="Dice:", padx=4, pady=4)
        self.dice_frame = tk.Frame(master=self.dice_label_frame)
        self.dice_count = tk.StringVar(value="3")
        self.dice_count_entry = tk.Entry(master=self.dice_frame, width=4, justify="right", textvariable=self.dice_count)
        self.d_label = tk.Label(master=self.dice_frame, text="d", padx=4)
        self.dice_sides = tk.StringVar(value="6")
        self.dice_sides_entry = tk.Entry(master=self.dice_frame, width=4, justify="left", textvariable=self.dice_sides)
        self.roll_button = tk.Button(master=self.dice_frame, text="Roll!")

        self.results_label_frame = tk.LabelFrame(master=self.root, text="Results:")
        self.results_frame = tk.Frame(master=self.results_label_frame)
        self.result_label = tk.Label(master=self.results_frame, text="Result: ...")
        self.higher_probability_label = tk.Label(master=self.results_frame, text="Chance of ... or higher: ...%")
        self.lower_probability_label = tk.Label(master=self.results_frame, text="Chance of ... or lower: ...%")
    
    def create_bindings(self):
        self.roll_button["command"] = self.roll_the_dice
        self.root.bind("<Control-MouseWheel>", self.zoom)

    def configure_fonts(self):
        self.small_text_widgets = [
            self.dice_label_frame, self.roll_button, self.results_label_frame, 
            self.higher_probability_label, self.lower_probability_label
        ]

        self.big_text_widgets = [
            self.dice_count_entry, self.d_label, self.dice_sides_entry, self.result_label
        ]
        
        for widget in self.small_text_widgets:
            widget.configure(font=("Arial", 12))

        for widget in self.big_text_widgets:
            widget.configure(font=("Arial", 14))        

    def configure_layout(self):
        self.dice_label_frame.pack(fill="x", padx=20)
        self.dice_frame.pack()
        self.dice_count_entry.pack(side="left")
        self.d_label.pack(side="left")
        self.dice_sides_entry.pack(side="left")
        self.roll_button.pack(side="left", padx=8)

        self.results_label_frame.pack(fill="x", padx=20)
        self.results_frame.pack()
        self.result_label.pack(pady=4)
        self.lower_probability_label.pack()
        self.higher_probability_label.pack()
    
    def configure_geometry(self):
        self.root.geometry("400x300+700+100")
    
    def roll_the_dice(self):
        try:
            count = int(self.dice_count.get())
            sides = int(self.dice_sides.get())
            distribution = DiceDistribution(count, sides)
            result = distribution.roll()
            lower_probability = distribution.probability_of_range(count, result)
            higher_probability = distribution.probability_of_range(result, count * sides)            

            self.result_label["text"] = f"Result: {result}"
            self.lower_probability_label["text"] = f"Chance of {result} or lower: {lower_probability * 100:.2f}%"
            self.higher_probability_label["text"] = f"Chance of {result} or higher: {higher_probability * 100:.2f}%"
        except:
            self.result_label["text"] = "Please only enter positive integers!"
            self.lower_probability_label["text"] = "..."
            self.higher_probability_label["text"] = "..."
    
    def zoom(self, event):
        change = 0
        if event.delta < 0:
            change = -1
        else:
            change = +1
        
        for widget in self.small_text_widgets:
            font = widget.cget("font")
            font_size = int(font.split(" ")[1])
            widget.configure(font=("Arial", font_size + change))

        for widget in self.big_text_widgets:
            font = widget.cget("font")
            font_size = int(font.split(" ")[1])
            widget.configure(font=("Arial", font_size + 2*change))

def main():
    DiceRollGui()

if __name__ == "__main__":
    main()