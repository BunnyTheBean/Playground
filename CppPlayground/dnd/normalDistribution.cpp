#include "normalDistribution.hpp"
#include <cmath>
using namespace std;

NormalDistribution::NormalDistribution(double mean, double standardDeviation) {
    this->mean = mean;
    this->standardDeviation = standardDeviation;
}

// Returns F(x) = P(X <= x) of the normal distribution with the given mean and std. deviation
double NormalDistribution::standardCumulativeDensityFunction(double x) {
    return erfc(-x / sqrt(2)) / 2;
}

double NormalDistribution::cumulativeDensityFunction(double x) {
    x = (x - this->mean) / this->standardDeviation;
    return standardCumulativeDensityFunction(x);
}

double NormalDistribution::probability(double lower, double upper) {
    return cumulativeDensityFunction(upper) - cumulativeDensityFunction(lower);
}