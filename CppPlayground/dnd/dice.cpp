#include "dice.hpp"
#include "exactDiceDistribution.hpp"
#include "normalDistribution.hpp"
using namespace std;

Dice::Dice() {
    random_device device;
    this->generator = mt19937(device());
}

int Dice::roll(int times, int sidesOfDie, int modifier) {
    auto distribution = uniform_int_distribution<int>(1, sidesOfDie);
    int sum = modifier;    
    
    for (int i = 0; i < times; i++)
    {
        sum += distribution(this->generator);
    }

    return sum;
}

// TODO: use exact probability for smaller numbers of dice
RollResult Dice::rollWithProbability(int times, int sidesOfDie, int modifier) {
    RollResult result;
    result.result = roll(times, sidesOfDie, modifier);
    
    double possibilities = pow(sidesOfDie, times);
    double intMax = pow(2, 31);

    // Use approximation with normal distribution if there are too many dice for an exact calculation.
    if (possibilities / intMax >= 0.1) {
        double mean = ((double)(sidesOfDie + 1) / 2) * times + modifier;
        double variance = (double)(sidesOfDie * sidesOfDie - 1) / 12 * times;
        double standardDeviation = sqrt(variance);

        auto distribution = NormalDistribution(mean, standardDeviation);
        result.probabilityOfResultOrLower = distribution.cumulativeDensityFunction(result.result + 0.5);
        result.probabilityOfResultOrHigher = 1.0 - distribution.cumulativeDensityFunction(result.result - 0.5);
    } else {
        auto distribution = ExactDiceDistribution(times, sidesOfDie);
        result.probabilityOfResultOrLower = distribution.cumulativeDensityFunction(result.result - modifier);
        result.probabilityOfResultOrHigher = 1.0 - distribution.cumulativeDensityFunction(result.result - modifier - 1);
    }

    return result;
}

int Dice::rollOneStat() {
    int lowestIndex;
    int rolls[4];
    int stat = 0;

    for (int i = 0; i < 4; i++)
    {
        int dieRoll = roll();
        rolls[i] = dieRoll;

        if (i == 0) {
            lowestIndex = 0;
        } else {
            lowestIndex = rolls[i] < rolls[lowestIndex]
                ? i
                : lowestIndex;
        }
    }
    
    for (int i = 0; i < 4; i++) {
        if (i != lowestIndex) {
            stat += rolls[i];
        }
    }

    return stat;
}

int Dice::sumOfStatSet(list<int> set) {
    int sum = 0;
    for (auto i = set.begin(); i != set.end(); i++)
    {
        sum += *i;
    }
    return sum;
}

list<int> Dice::rollStatSet(int min, int max) {
    list<int> set;
    int sum;

    do {
        set = list<int>();
        for (int i = 0; i < 6; i++)
        {
            set.push_back(rollOneStat());
        }
        sum = sumOfStatSet(set);        
    } while (sum < min || sum > max);

    return set;
}

/*
void Dice::printStatSet(list<int> set) {
    int sum = sumOfStatSet(set);
    cout << "(" << sum << ")\t";
    for (auto i = set.begin(); i != set.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}
*/

