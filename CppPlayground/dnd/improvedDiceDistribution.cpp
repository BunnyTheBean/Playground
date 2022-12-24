#include <math.h>
#include "improvedDiceDistribution.hpp"

ImprovedDiceDistribution::ImprovedDiceDistribution(int number, int sides) {
    this->number = number;
    this->sides = sides;
    this->possibilities = pow(sides, number);
}

double ImprovedDiceDistribution::binomialCoefficient(int n, int k) {
    //return factorial(n) / (factorial(n - k) * factorial(k));
    // Let's not use factorials, but instead let's optimize this a bit and use doubles that are finally cast back to long long
    // for example: n over k = 50!/(30! * 20!) can instead be calculated as (50*49*...*31)/(20*19*...*1) after simplification
    // To avoid very large numbers (and thus loss of precision), let's switch between multiplying and dividing
    
    k = (n-k) < k ? n-k : k;

    double total = 1;
    for (int i = 0; i < k; i++) {
        total = total * (n - i) / (k - i);
    }
    return total;
}

double ImprovedDiceDistribution::permutations(int sum) {
    // Calculates the possible permutations of dice rolls that add up to a given sum
    // The formula that is used was taken from Luca M on this here forum post:
    // https://math.stackexchange.com/questions/794981/how-many-permutations-of-die-rolls-add-up-to-a-fixed-total
    // k = sum, n = number, replace 6 in the formula with sides
    
    double total = 0;
    int imax = (sum - number) / sides;
    for (int i = 0; i <= imax; i++) {
        int sign = i % 2 == 0 ? 1 : -1;
        double bc1 = binomialCoefficient(number, i);
        double bc2 = binomialCoefficient(sum - sides*i - 1, sum - sides*i - number);
        total += sign * bc1 * bc2;
    }
    return total;
}

double ImprovedDiceDistribution::probability(int sum) {
    // Calculates P(X==result)
    
    return permutations(sum) / possibilities;
}

double ImprovedDiceDistribution::probability(int lower, int upper) {
    // Calculates P(lower <= X <= upper)
    double result = 0;
    for (int i = lower; i <= upper; i++) {
        result += probability(i);
    }
    return result;
}

double ImprovedDiceDistribution::cumulativeProbability(int upper) {
    // Calculates P(result <= X)
    double result = 0;
    for (int i = number; i <= upper; i++) {
        result += probability(i);
    }
    return result;
}