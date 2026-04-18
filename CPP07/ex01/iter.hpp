#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

extern int cry;

template <typename T, typename U>
void iter(T *array, const int len, U func) // im so fking general
{
    for (int i = 0; i < len; i++){
        func(array[i]);
        // std::cout << "I will change the type as u want" << std::endl; // success :)
    }
} // more general way when test functions are overloading it doesnt work without precision

// ------ in case of overloading precisions ------

//(1) to use only with (2) not (3)

// template <typename T>
// void iter(T *array, const int len, void(*func)(T&)) // im general
// {
//     for (int i = 0; i < len; i++){
//         func(array[i]);
//         // std::cout << "I will change the value when u want" << std::endl; // success :)
//     }
// }

//(2)

// template <typename T>
// void iter(const T *array, const int len, void(*func)(const T&)) // no value changing function and value
// {
//      for (int i = 0; i < len; i++){
//         func(array[i]);
//         // std::cout << "debug to see const called" << std::endl; // success :)
//     }
// }

//(3)

// template <typename T, typename U> // maybe for the practice this looks better? but iter is void so
// void iter(T *array, const int len, U(*func)(const T&)) // need to think of its use
// {
//     for (int i = 0; i < len; i++){
//         func(array[i]);
//         std::cout << "debug to see second f called" << std::endl;

//     }
// } 
// (1) converts this cuz const function itself can be used in 1st case
// compile error ambiguos overloading

#endif