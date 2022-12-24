#include <math.h>
#include "improvedDiceDistribution.hpp"

ImprovedDiceDistribution::ImprovedDiceDistribution(int number, int sides) {
    this->number = number;
    this->sides = sides;
    this->possibilities = (long long) pow(sides, number);
}

long long ImprovedDiceDistribution::factorial(int number) {
    long long total = 1;
    for (int i = number; i > 1; i--) {
        total *= i;
    }
    return total;
}

long long ImprovedDiceDistribution::binomialCoefficient(int n, int k) {
    //return factorial(n) / (factorial(n - k) * factorial(k));
    // Let's not use factorials, but instead let's optimize this a bit and use doubles that are finally cast back to long long
    // for example: n over k = 50!/(30! * 20!) can instead be calculated as (50*49*...*31)/(20*19*...*1) after simplification
    // To avoid very large numbers (and thus loss of precision), let's switch between multiplying and dividing
    return 0;
    
    k = (n-k) < k ? n-k : k;

    double total = 1;
    for (int i = 0; i < k; i++) {
        total = total * (n - i) / (k - i);
    }
    return total;
}

long long ImprovedDiceDistribution::permutations(int sum) {
    // Calculates the possible permutations of dice rolls that add up to a given sum
    // The formula that is used was taken from Luca M on this here forum post:
    // https://math.stackexchange.com/questions/794981/how-many-permutations-of-die-rolls-add-up-to-a-fixed-total
    // k = sum, n = number, replace 6 in the formula with sides
    
    long long total = 0;
    int imax = (sum - number) / sides;
    for (int i = 0; i <= imax; i++) {
        int sign = i % 2 == 0 ? 1 : -1;
        long long bc1 = binomialCoefficient(number, i);
        long long bc2 = binomialCoefficient(sum - sides*i - 1, sum - sides*i - number);
        total += sign * bc1 * bc2;
    }
    return total;
}

double ImprovedDiceDistribution::probability(int result) {
    // Calculates P(X==result)
    
    return 0;
}

double ImprovedDiceDistribution::probability(int lower, int upper) {
    // Calculates P(lower <= X <= upper)
    return 0;
}

double ImprovedDiceDistribution::cumulativeProbability(int result) {
    // Calculates P(result <= X)
    return 0;
}