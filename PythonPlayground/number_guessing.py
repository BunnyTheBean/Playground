import random

def main():
    correct_number = random.randint(1, 200)

    while True:
        guess = input("Guess a number: ")

        try:
            guess = int(guess)
        except:
            print("That wasn't a valid number!")
            continue

        if guess == correct_number:
            print(f"Yay, you did it! The correct number is {correct_number}!")
            break

        if guess < correct_number:
            print("Your guess was too low!")

        if guess > correct_number:
            print("Your guess was too high!")


if __name__ == "__main__": 
    main()