#include <list>
#include <random>
using namespace std;

class Dice {
    private:
        mt19937 generator;
    public:
        Dice();
        int roll(int times = 1, int sidesOfDie = 6, int modifier = 0);
        int rollOneStat();
        int sumOfStatSet(list<int> set);
        list<int> rollStatSet(int min = 18, int max = 108);
        void printStatSet(list<int> set);
};