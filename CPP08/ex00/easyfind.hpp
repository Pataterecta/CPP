#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <string>
#include <sstream>

// static std::string toStr(int value)
// {
// 	std::stringstream ss;
// 	ss << value;
// 	std::string value_str;
// 	ss >> value_str;
// 	return (value_str);
// } 

template <typename T>
typename T::iterator easyfind(T& arrayI, int n)
{
    typename T::iterator it = arrayI.begin();
    it = std::find(arrayI.begin(), arrayI.end(), n);
    if (it != arrayI.end()){
        return it;
    }
    std::stringstream ss; // i just wanted to do this with util but no other function def possible on header except for templatitos
	ss << n;
	std::string n_str;
	ss >> n_str;
    const std::string errmsg = "no occurence of -> " + n_str;
    throw errmsg;
}

#endif

// Write a function template easyfind that accepts a type T. It takes two parameters:
// the first one is of type T, and the second one is an integer.
// Assuming T is a container of integers, this function has to find the first occurrence
// of the second parameter in the first parameter.
// If no occurrence is found, you can either throw an exception or return an error value
// of your choice. If you need some inspiration, analyze how standard containers behave.

// https://stackoverflow.com/questions/11275444/c-template-typename-iterator
// exception class types : https://mm5-gnap.tistory.com/42
// https://en.cppreference.com/cpp/algorithm/find