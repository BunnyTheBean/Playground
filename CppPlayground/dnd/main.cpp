#include "dice.hpp"
#include "normalDistribution.hpp"
#include "exactDiceDistribution.hpp"
#include "improvedDiceDistribution.hpp"
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {    
    cout << fixed;
    cout << setprecision(15);
    
    ImprovedDiceDistribution dist {60, 6};

    cout << dist.probability(200, 240) << endl;
    
}
