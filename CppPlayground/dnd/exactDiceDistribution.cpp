#include "exactDiceDistribution.hpp"
#include <cmath>
#include <iostream>
using namespace std;

ExactDiceDistribution::ExactDiceDistribution(int number, int sides) {
    this->numberOfDice = number;
    this->sidesOfDice = sides;
    this->minRoll = number;
    this->maxRoll = number * sides;
    this->possibilities = pow(sidesOfDice, numberOfDice);
    initializeAbsoluteRollFrequencies();
}

ExactDiceDistribution::~ExactDiceDistribution() {
    delete[] this->absoluteRollFrequencies;
}

void ExactDiceDistribution::initializeAbsoluteRollFrequencies() {
    /*
    To initialize the frequencies of possible rolls, we need to loop through all possible
    dice rolls. This is done by incrementing a number that is interpreted as a base 6
    number, where each base 6 digit represents the value of one die.

    Example for 3d6:
    DECIMAL     BASE6   die1    die2    die3
    0           000     1       1       1
    3           003     4       1       1
    6           010     1       2       1
    13          021     2       3       1
    199         531     2       4       6
    215         555     6       6       6
    */    

    this->absoluteRollFrequencies = new int[maxRoll + 1] { 0 };

    for (int i = 0; i < this->possibilities; i++)
    {
        int current = i;
        int sum = 0;
        for (int j = 0; j < numberOfDice; j++)
        {
            sum += current % 6 + 1;
            current /= 6;
        }
        absoluteRollFrequencies[sum]++;
    }
}

double ExactDiceDistribution::cumulativeDensityFunction(double x) {
    double probability = 0;
    int total = pow(sidesOfDice, numberOfDice);
    for (int i = 0; i <= x; i++)
    {
        probability += (double)absoluteRollFrequencies[i] / possibilities;
    }
    return probability;
}

/*
class exactDiceDistribution {
    private:
        int numberOfDice;
        int sidesOfDice;
        int modifier;
        int absoluteFrequencies[];
    public:
        exactDiceDistribution();
        double cumulativeDensityFunction(double x);
        double probability(double lower, double upper);
};
*/