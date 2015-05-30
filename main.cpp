#include <iostream>
#include <string>

#include "Calculator.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: exercise1 N [-b|i]" << std::endl;
        return -1;
    }

    try
    {
        const long long n = std::stoll(argv[1]);
        
        std::unique_ptr<Calculator> calculator;
        if (argc >= 3)
        {
            if (const bool bruteForce = (std::string(argv[2]) == "-b"))
                calculator = CreateBruteForceCalculator();
            else if (const bool iterative = (std::string(argv[2]) == "-i"))
                calculator = CreateIterativeCalculator();
        }

        if (!calculator)
            calculator = CreateOptimiziedCalculator();

        std::cout << calculator->f(n) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}
