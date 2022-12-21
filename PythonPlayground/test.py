def isPrime(number: int) -> int:
    if number == 0 or number == 1:
        return False
    if number == 2:
        return True
    
    i: int = 2
    while i <= number / 2:
        if number % i == 0:
            return False
        i += 1

    return True

for i in range(200):
    if isPrime(i):
        print(f"{i} yes")
    else:
        print(f"{i} no")


