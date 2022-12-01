class ExactDiceDistribution {
    private:
        int numberOfDice;
        int sidesOfDice;
        int minRoll;
        int maxRoll;
        int possibilities;
        int* absoluteRollFrequencies;
        void initializeAbsoluteRollFrequencies();
    public:
        ExactDiceDistribution(int number, int sides);
        ~ExactDiceDistribution();
        double cumulativeDensityFunction(int x);
        double probability(int lower, int upper);
};