import random

class DiceDistribution:
    number: int
    sides: int
    possibilities: int
    #modifier: int TODO

    def __init__(self, number_of_dice: int, sides_of_dice: int):
        self.number = number_of_dice
        self.sides = sides_of_dice
        self.possibilities = self.sides ** self.number
    
    def binomial_coefficient(n: int, k: int) -> int:
        k = (n - k) if (n - k) < k else k
        total = 1
        i = 0
        while i < k:
            total = total * (n - i) / (k - i)
            i += 1
        return int(round(total))

    def permutations_for_result(self, result: int) -> int:
        total = 0
        imax = (result - self.number) / self.sides
        i = 0

        while i <= imax:
            sign = 1 if i % 2 == 0 else -1
            factor1 = DiceDistribution.binomial_coefficient(self.number, i)
            factor2 = DiceDistribution.binomial_coefficient(result - self.sides * i - 1, result - self.sides * i - self.number)
            total += sign * factor1 * factor2
            i += 1
        
        return int(round(total))
    
    def probability_of_result(self, result: int) -> float:
        return self.permutations_for_result(result) / self.possibilities

    def probability_of_range(self, lower: int, upper: int) -> float:
        if lower > upper:
            lower, upper = upper, lower

        probability: float = 0.0
        for i in range (lower, upper+1):
            probability += self.probability_of_result(i)
        return probability
    
    def roll(self) -> int:
        result = 0
        for i in range(self.number):
            result += random.randint(1, self.sides)
        return result

def main():
    dist = DiceDistribution(8, 6)
    
    prob = dist.probability_of_range(8, 15)
    print(f"8-15:\t{round(prob * 100, 2)}%")

    prob = dist.probability_of_range(15, 48)
    print(f"15-48:\t{round(prob * 100, 2)}%")

if __name__ == "__main__":
    main()