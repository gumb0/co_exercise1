#include "Calculator.h"

#include <unordered_map>

class BruteForceCalculator : public Calculator
{
public:
    virtual long long f(long long n)
    {
        if (n == 0 || n == 1)
            return 1;

        if (n % 2)
        {
            const long long t = (n - 1) / 2;
            return f(t) + f(t - 1);
        }
        else
            return f(n / 2);
    }
};

std::unique_ptr<Calculator> CreateBruteForceCalculator()
{
    return std::unique_ptr<Calculator>(new BruteForceCalculator);
}

class OptimizedCalculator : public Calculator
{
public:
    virtual long long f(long long n)
    {
        if (n == 0)
            return 1;

        while (n % 2 == 0)
            n /= 2;

        if (n == 1)
            return 1;

        std::unordered_map<long long, long long>::const_iterator it = mCache.find(n);
        if (it != mCache.end())
            return it->second;

        const long long t = (n - 1) / 2;
        const long long res = f(t) + f(t - 1);
        mCache[n] = res;
        return res;
    }

private:
    std::unordered_map<long long, long long> mCache;
};

std::unique_ptr<Calculator> CreateOptimiziedCalculator()
{
    return std::unique_ptr<Calculator>(new OptimizedCalculator);
}
