#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream> // also for abs
#include <vector>
#include <algorithm>
#include <exception>

class Span 
{
    private:
    unsigned int _size;
    unsigned int _resShort;
    std::vector<int> _intos; 

    public:

    Span();
    Span(int N); // cant do unsigned int
    Span(const Span& orig);
    Span& operator=(const Span& orig);
    ~Span();

    void addNumber(int); // subject says integers yeah
    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    unsigned int shortestSpan(void);
    unsigned int longestSpan(void) const;

    class E1_alreadyN : public std::exception
    {
        public: 
        const char* what() const throw();
    };
    class E2_noSpan : public std::exception
    {
        public: 
        const char* what() const throw();
    };
    class overflower : public std::exception
    {
        public: 
        const char* what() const throw();
    };

};

#endif

// Span class, can store a max of N integers(unsigned int variable)
// N only param to the __cpp_delegating_constructors

// member func - addNumber() add a single number to the Span
// are u fake pushback?
// E1) already N elements stored ? then throw an exception 

// member func - shortestSpan() -> ? longestSpan() -> min max
// span = distance between a and d, 3 17 2 -> shortest 1 longest 15
// E2) no member stored or only one ? no span throw an e
// float etc ? 