class ImprovedDiceDistribution {
    public:
        int number;
        int sides;
        long long possibilities;

        ImprovedDiceDistribution(int number, int sides);
        double binomialCoefficient(int n, int k);
        double permutations(int sum);
        double probability(int result);
        double probability(int lower, int upper);
        double cumulativeProbability(int result);
};