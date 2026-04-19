#include "Span.hpp"
#include <climits>
int main()
{
     try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----------test----\n";
    try
    {
        Span sp = Span(-1);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----------test----\n";
    try
    {
        Span sp = Span(3);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
     catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----------test----\n";
    try
    {
        Span sp = Span(3);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----------test----\n";
    try
    {
        Span sp = Span(3);
        // sp.addNumber(INT_MAX);
        // sp.addNumber(INT_MIN);
        sp.addNumber(-2147483648);
        sp.addNumber(2147483647);
        sp.addNumber(17);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----------test----\n";
    try
    {
        int array[] = {9, 99, 999 ,9999};
        std::vector<int> rangeto(array, array + 4);
        Span sp = Span(50);
        sp.addNumber(rangeto.begin(), rangeto.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----------test----\n";

      try
    {
        int array[] = {9, 99, 999 ,9999};
        std::vector<int> rangeto(array, array + 4);
        Span sp = Span(3);
        sp.addNumber(rangeto.begin(), rangeto.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
