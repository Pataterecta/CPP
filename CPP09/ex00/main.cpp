#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
    BitcoinExchange bito;

    if (ac != 2)
    {    
        // std::cerr << "Error: could not open file. _ no input\n";
        std::cerr << "Error: could not open file.\n";
        return 1;
    }
    std::ifstream givenCsv("data.csv");
    if (!givenCsv)
    {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }
    bito.parseCsv(givenCsv); // parse and put on the map container its result



    std::ifstream ref(av[1]);
    if (!ref)
    {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }
    bito.treatInf(ref);
    
    return 0;
}
