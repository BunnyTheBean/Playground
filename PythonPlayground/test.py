from dice_distribution import DiceDistribution

distribution = DiceDistribution(8, 8)
print("Probability of Cone of Cold doing X damage or higher:\n")
print("X\tProbability in %")
print("--------------------------")

for i in range (8, 65):
    probability = distribution.probability_of_range(i, 65)
    print(f"{i}:\t{probability * 100:.2f}")