#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <exception>
#include <limits>
#include <utility>

template <typename T>
class Array
{
    private:
    T* _sth;

    unsigned int _howmany;

    public:
    Array() : _sth(NULL), _howmany(0)
    {
        // create an empty array
    }

    Array(unsigned int n) 
    {
        // an array of n elements initialized
        if (n == 0){
            _sth = NULL;
            _howmany = 0;
            return ;
        }
        _howmany = n;
        _sth = new T[n]();
    }

    Array(const Array& orig) 
    {
        _sth = NULL;
        _howmany = orig._howmany;
        if (_howmany == 0)
            return ;
        _sth = new T[_howmany]();
        for (unsigned int i = 0; i < _howmany; i++){
            _sth[i] = orig._sth[i];
        }
    }

    Array& operator=(const Array& orig)
    {
        if (this != &orig)
        {
            Array temp(orig); // deep copy first
            std::swap(_sth, temp._sth); // swap adress
            std::swap(_howmany, temp._howmany);
        }
        return (*this);
    }

    // swap(_Tp& __a, _Tp& __b)
    // _GLIBCXX_NOEXCEPT_IF(__and_<is_nothrow_move_constructible<_Tp>,
	// 			is_nothrow_move_assignable<_Tp>>::value)

    // not good new protection so changed..

        // if (this != &orig)
        // {
        //     this->_howmany = orig._howmany;
        //     delete[] _sth;
        //     _sth = NULL;
           
            
        //     if (_howmany > 0)
        //     {
        //         _sth = new T[_howmany]; // and with the default initialization trace
        //         for (unsigned int i = 0; i < _howmany; i++)
        //         {   
        //             this->_sth[i] = orig._sth[i];
        //         }
        //     }
        // }
        // return (*this);
    

    T& operator[](unsigned int idx) // const Array<int> x; x[0] = 99; 쓰기도
    {
        if (idx >= _howmany)
            throw IIOB();
        return _sth[idx];
    }

    const T& operator[](unsigned int idx) const // const Array<int> b; b[0] 읽기만
    {
        if (idx >= _howmany)
            throw IIOB();
        return _sth[idx];
    }

    class IIOB : public std::exception // numbers[-2] = 0; etc detection
    {
        public:
        const char* what() const throw(){
            return "Index Is Out of Bounds";
        }
    };

    unsigned int size() const
    {
        return _howmany;
    }
    
    ~Array()
    {
        delete[] _sth;
    }

};

#endif

// copy constructor and ass operator
// modifying either the original array or its copy 
// musn't affect the other array

// operator new[] preventive allocation is forbidden
// never access non allocated memory

// elements can be accessed through the subscript op[]
// idx out of bounds? std::exception is thrown

// -> two diff [], create and access

// size() returns the n of elements in the array

//  Creates an array of n elements
// initialized by default.
// Tip: Try to compile int * a = new int(); then display *a.

// value initialization : new T[n]();
// default initialization : new T[n];
// !!! BUT !!! its also a tricky 42 way writing + its "array" which is the simplest "vector" implementation practice
// so Im doing the value initialization : by "initializing it" "by default" and not doint the "default initialization"
// https://stackoverflow.com/questions/8106016/c-default-initialization-and-value-initialization-which-is-which-which-is-ca
// https://en.cppreference.com/cpp/language/default_initialization

 /** @file bits/move.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{utility}
 */