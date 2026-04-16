#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "./convert and then put one input plz";    
        return (0);
    }
    ScalarConvert::doConvert(av[1]);
    
    return (0);
}
