#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <memory>

class Calculator
{
public:
    virtual ~Calculator() {}

    virtual long long f(long long n) = 0;
};

std::unique_ptr<Calculator> CreateBruteForceCalculator();
std::unique_ptr<Calculator> CreateOptimiziedCalculator();

#endif
