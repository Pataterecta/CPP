#include "iter.hpp"

#include <iostream>

int cry = 0;

void random_cried(int &n)
{
    std::cout << "I cried: " << n << " times." << std::endl;
    std::cout << "idx: " << cry << std::endl;
    cry++;
}

void random_cried(const int &n)
{
    std::cout << "I const cried: " << n << " times." << std::endl;
    std::cout << "idx: " << cry << std::endl;
    cry++;
}

void zero_waste(int &n)
{
    n = 0;
}

int main(void)
{
    
    int array[] = {1, 2, 3};
    const int len = 3;
    iter(array, len, random_cried);
    cry = 0;
    std::cout << "----test-----" << std::endl;
    const int array2[] = {9, 99, 999, 9999};
    const int len2 = 4;
    iter(array2, len2, random_cried); 
    // overloading test, for both case, uncomment debug const called to see better
    std::cout << "----test-----" << std::endl;
    iter(array, len, zero_waste);
    std::cout << array[0] << ", " << array[1] << " and then " << array[2] << std::endl;
    // same uncomment the 1st iter function so to check which is called :)
    return (0);
}