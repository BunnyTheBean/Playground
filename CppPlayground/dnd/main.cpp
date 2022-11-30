#include "dice.hpp"
#include <iostream>
using namespace std;

int main() {
    auto dice = Dice();

    for (int i = 0; i < 25; i++)
    {    
        dice.printStatSet(dice.rollStatSet(70, 76));
    }
}