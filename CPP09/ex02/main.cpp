#include "PmergeMe.hpp"



int main(int ac, char **av)
{
    PmergeMe pm;

    if (ac < 2)
    {
        std::cerr << "error: put more input\n";
        return 1;
    }
    try
    {
        pm.inputParse(ac, av);
        pm.calTime();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}