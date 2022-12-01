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
        double cumulativeDensityFunction(double x);
        double probability(double lower, double upper);
};