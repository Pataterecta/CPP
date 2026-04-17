#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

extern int cry;

template <typename T, typename U>
void iter(T *array, const int len, U(*func)(T&)) // im so general
{
    for (int i = 0; i < len; i++){
        func(array[i]);
        // std::cout << "I will change the value when u want" << std::endl; // success :)
    }
}

// template <typename T, typename U>
// void iter(T *array, const int len, U(*func)(const T&)) // need to think of its use
// {
//     for (int i = 0; i < len; i++){
//         func(array[i]);
//         std::cout << "debug to see second f called" << std::endl;

//     }
// } 
// 1 converts this cuz const function itself can be used in 1st case
// compile error ambiguos overloading

template <typename T, typename U>
void iter(const T *array, const int len, U(*func)(const T&)) // no value changing function and value
{
     for (int i = 0; i < len; i++){
        func(array[i]);
        // std::cout << "debug to see const called" << std::endl; // success :)
    }
}

#endif