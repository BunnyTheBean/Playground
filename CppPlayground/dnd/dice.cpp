#include "dice.hpp"
#include <iostream>
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

void Dice::printStatSet(list<int> set) {
    int sum = sumOfStatSet(set);
    cout << "(" << sum << ")\t";
    for (auto i = set.begin(); i != set.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

