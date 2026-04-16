#include <cmath>
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
    std::cout << "\n-------------test-----\n";
    double x = 1.0;
    double div = 0.0;
    double mod;
    mod = std::modf(x, &div);
    std::cout << "나는 디브: " << div << " 나머지 mod: " << mod << std::endl;

    double x2 = 2;
    double div2 = 0.0;
    double mod2;
    mod2 = std::modf(x2, &div2);
    std::cout << "나는 디브: " << div2 << " 나머지 mod: " << mod2 << std::endl;

    double x3 = 1.234;
    double div3 = 0.0;
    double mod3;
    mod3 = std::modf(x3, &div3);
    std::cout << "나는 디브: " << div3 << " 나머지 mod: " << mod3 << std::endl;

    return (0);
}

