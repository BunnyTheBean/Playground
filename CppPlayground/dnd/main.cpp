#include "dice.hpp"
#include "normalDistribution.hpp"
#include "exactDiceDistribution.hpp"
#include <iostream>
using namespace std;

int main() {
    Dice dice = Dice();

    for (int i = 0; i < 9; i++)
    {
        auto result = dice.roll(10, 4, 20);
        cout << result << endl;
    }
}
