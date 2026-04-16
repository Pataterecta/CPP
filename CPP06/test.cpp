#include <iostream>
#include <cstdlib>

int main(void)
{
    const std::string test1 = "42.00010f";
    const std::string test2 = "62";
    const std::string test3 = "a";

    char* end;
    double braw = std::strtod(test1.c_str(), &end);
    std::cout << braw << std::endl;

    std::cout << "\n-------------test-----\n";
    float fval = static_cast <float>(braw);
    std::cout << fval << std::endl;

    std::cout << "\n-------------test-----\n";
    braw = std::strtod(test2.c_str(), &end);
    std::cout << braw << std::endl;
    fval = static_cast <float>(braw);
    std::cout << fval << std::endl;

    std::cout << "\n-------------test-----\n";
    braw = std::strtod(test3.c_str(), &end);
    std::cout << braw << std::endl;
    char cval;
    cval = static_cast <char>(braw);
    std::cout << cval << std::endl;


    return (0);
}