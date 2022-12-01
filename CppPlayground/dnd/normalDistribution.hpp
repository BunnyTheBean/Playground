class NormalDistribution {
    private:
        double mean;
        double standardDeviation;
    public:
        NormalDistribution(double mean = 0, double standardDeviation = 1);
        double standardCumulativeDensityFunction(double x);
        double cumulativeDensityFunction(double x);
        double probability(double lower, double upper);
};