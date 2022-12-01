#include "dice.hpp"
#include "normalDistribution.hpp"
#include "exactDiceDistribution.hpp"
#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

int main() {
    auto dist = ExactDiceDistribution(2, 6);
    cout << dist.cumulativeDensityFunction(11) << endl;
    cout << dist.cumulativeDensityFunction(12) << endl;
}