#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "----extra mstack rbegin rend, empty test\n"; 

    MutantStack<int>::reverse_iterator it2 = mstack.rbegin(); // the last element so 0
    std::cout << *it2 << std::endl;
    MutantStack<int>::reverse_iterator it3 = mstack.rend();
    std::cout << *(it3 - 1) << std::endl; // next element so the first element 5

    if (!mstack.empty())
        std::cout << "im not empty\n";
    
    std::cout << "----extra mstack rbegin rend, empty test end\n";

    std::stack<int> s(mstack);

    std::cout << "-----------------test list-----\n";

    std::list<int> listito;
    listito.push_back(5);
    listito.push_back(17);
    std::cout << listito.back() << std::endl;
    listito.pop_back();
    std::cout << listito.size() << std::endl;
    listito.push_back(3);
    listito.push_back(5);
    listito.push_back(737);
    
    listito.push_back(0);
    std::list<int>::iterator l_it = listito.begin();
    std::list<int>::iterator l_ite = listito.end();
    ++l_it;
    --l_it;
    while (l_it != l_ite)
    {
        std::cout << *l_it << std::endl;
        ++l_it;
    }

    std::cout << "----extra list rbegin rend empty\n"; 

    std::list<int>::reverse_iterator l_it2 = listito.rbegin(); // the last element so 0
    std::cout << *l_it2 << std::endl;
    std::list<int>::reverse_iterator l_it3 = listito.rend();
    std::cout << *(--l_it3) << std::endl; 
    // -- for the linked list next element so the first element 5
    // cant do random accesss, means not saved successively on the memory

    if (!listito.empty())
        std::cout << "im not empty\n";
    
    std::cout << "----extra list rbegin rend empty test end\n";

    return 0;
}

// do some more test baboya