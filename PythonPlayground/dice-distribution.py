def binomial_coefficient(n: int, k: int) -> int:
    k = (n - k) if (n - k) < k else k
    total = 1
    i = 0
    while i < k:
        total = total * (n - i) / (k - i)
        i += 1
    return int(round(total))

def roll_permutations_for_sum(sum: int, number_of_dice: int, sides_of_dice: int) -> int:
    total = 0
    imax = (sum - number_of_dice) / sides_of_dice
    i = 0

    while i <= imax:
        sign = 1 if i % 2 == 0 else -1
        first_factor = binomial_coefficient(number_of_dice, i)
        second_factor = binomial_coefficient(sum - sides_of_dice * i - 1, sum - sides_of_dice * i - number_of_dice)
        total += sign * first_factor * second_factor
        i += 1
    
    return int(round(total))

def probability_of_result(result: int, number_of_dice: int, sides_of_dice: int) -> int:
    possibilities = sides_of_dice ** number_of_dice
    return roll_permutations_for_sum(result, number_of_dice, sides_of_dice) / possibilities

def main():
    number = 8
    sides = 6
    for i in range (number, number*sides+1):
        p = round(probability_of_result(i, number, sides) * 100, 2)
        print(f"{i}\t{p}%")

if __name__ == "__main__":
    main()