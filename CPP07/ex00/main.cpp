#include "whatever.hpp"

int main(void)
{
    int a = 1;
    int b = 2;
    swap(a, b);
    std::cout << a << std::endl;
    std::cout << "-----test-----" << std::endl;
    double ad = 2.05;
    // float bd = 2.01; -> u can uncomment this to see that two types should be the same
    // std::cout << min(ad, bd) << std::endl;
    double cd = 1.0008;
    std::cout << min(ad, cd) << std::endl;
    std::cout << "-----test-----" << std::endl;
    std::cout << max(ad, cd) << std::endl;
    std::cout << "-----test-----" << std::endl;
    char ac = 42;
    char bc = 42;
    std::cout << min(ac, bc) << std::endl;
    std::cout << min(ac, bc) << std::endl;

    return (0);
}