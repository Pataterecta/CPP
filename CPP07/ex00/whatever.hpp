#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T& n1, T& n2)
{
    T temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

template <typename T>
const T& min(const T& n1, const T& n2)
{
    if (n1 > n2)
        return n2;
    else if (n1 < n2)
        return n1;
    else
        return n2;
}

template <typename T>
const T& max(const T& n1, const T& n2)
{
    if (n1 < n2)
        return n2;
    else if (n1 > n2)
        return n1;
    else
        return n2;
}

#endif