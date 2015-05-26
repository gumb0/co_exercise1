#include <iostream>
#include <string>

#include "Calculator.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: exercise1 N [-b]" << std::endl;
        return -1;
    }

    try
    {
        const long long n = std::stoll(argv[1]);

        const bool bruteForce = (argc >= 3 && std::string(argv[2]) == "-b");
        std::unique_ptr<Calculator> calculator(bruteForce ? CreateBruteForceCalculator() : CreateOptimiziedCalculator());

        std::cout << calculator->f(n) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}
