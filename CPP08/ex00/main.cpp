#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <exception>

int main(void)
{
    std::vector<int> listos;
    listos.push_back(1);
    listos.push_back(2);
    listos.push_back(3);


    int n1 = 1;
    int n2 = 2;
    int n3 = 3;
    int n99 = 99;

    try
    {
        std::cout << "first occurence of n's adress: " << &(*(easyfind(listos, n1))) << std::endl;
        std::cout << "first occurence of n's value: " << *(easyfind(listos, n1)) << std::endl;
        std::cout << "first occurence of n's adress: " << &(*(easyfind(listos, n2))) << std::endl;
        std::cout << "first occurence of n's value: " << *(easyfind(listos, n2)) << std::endl;
        std::cout << "first occurence of n's adress: " << &(*(easyfind(listos, n3))) << std::endl;
        std::cout << "first occurence of n's value: " << *(easyfind(listos, n3)) << std::endl;
        std::cout << "first occurence of n's adress: " << &(*(easyfind(listos, n99))) << std::endl;
        std::cout << "first occurence of n's value: " << *(easyfind(listos, n99)) << std::endl;
    }
    catch(const std::string e)
    {
        std::cerr << e << " you got caught bro\n";
    }

    return (0);
}