class ImprovedDiceDistribution {
    public:
        int number;
        int sides;
        double possibilities;

        ImprovedDiceDistribution(int number, int sides);
        double binomialCoefficient(int n, int k);
        double permutations(int sum);
        double probability(int sum);
        double probability(int lower, int upper);
        double cumulativeProbability(int upper);
};