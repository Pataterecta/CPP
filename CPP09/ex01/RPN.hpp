#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <string>
#include <stack>
#include <sstream>
#include <iostream>
#include <math.h>

class RPN
{
    private:
    std::stack<int, std::list<int> > _stacks;

    bool validNum(const std::string& str);
    bool validOp(const std::string& str);


    public:
    RPN();
    RPN(const RPN& orig);
    RPN& operator=(const RPN& orig);
    ~RPN();

    void parseCal(const std::string& str);

};

#endif