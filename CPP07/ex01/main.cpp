#include "iter.hpp"

#include <iostream>

int cry = 0;

void random_cried(int &n)
{
    std::cout << "I cried: " << n << " times." << std::endl;
    std::cout << "idx: " << cry << std::endl;
    cry++;
}

void random_cried2(const int &n)
{
    std::cout << "I const cried: " << n << " times." << std::endl;
    std::cout << "idx: " << cry << std::endl;
    cry++;
}

// for overloading test

// void random_cried(const int &n)
// {
//     std::cout << "I const cried: " << n << " times." << std::endl;
//     std::cout << "idx: " << cry << std::endl;
//     cry++;
// }

void zero_waste(int &n)
{
    n = 0;
}

// no use

// const std::string& zero_waste(int &n) // typename U checked but only for the error message
// {
//     n = 0;
//     return "happy"; if there should have been a return
// }

int main(void)
{
    
    int array[] = {1, 2, 3};
    const int len = 3;
    iter(array, len, random_cried);
    cry = 0;
    std::cout << "----test-----" << std::endl;
    const int array2[] = {9, 99, 999, 9999};
    const int len2 = 4;
    // iter(array2, len2, random_cried); // for commented overloading iter
    iter(array2, len2, random_cried2);

    // overloading test, for both case when using (1) (2), uncomment debug const called blah to see better
    std::cout << "----test-----" << std::endl;
    iter(array, len, zero_waste);
    std::cout << array[0] << ", " << array[1] << " and then " << array[2] << std::endl;
    // same uncomment the 1st iter function so to check which is called :)
    std::cout << "----test-----" << std::endl;
    
    return (0);
}