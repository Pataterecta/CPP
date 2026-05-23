#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& orig) : _stacks(orig._stacks)
{
}

RPN& RPN::operator=(const RPN& orig)
{
    if (this != &orig)
    {
        this->_stacks = orig._stacks;
    }
    return *this;
}

RPN::~RPN()
{
}

bool RPN::validNum(const std::string& str)
{
    return (str.size() == 1 && std::isdigit(static_cast<unsigned char>(str[0])));
}

bool RPN::validOp(const std::string& str)
{
    return (str == "+" || str == "-" || str == "*" || str == "/");
}

void RPN::parseCal(const std::string& str)
{
    std::stringstream ss(str);
    std::string token;

    while (_stacks.empty() == false) // cleaning cuz _stacks is member 변수 and depends on the caller..
        _stacks.pop();

    while (ss >> token) // taking "+9" as invalid(cuz i dont take 12 as 1 and 2 and to not take number as +9 itself or + 9 no intention guessing), "+    9" as valid cuz isspace is evident to tokenize
    {
        if (validNum(token))
            _stacks.push(token[0] - '0');
        else if (validOp(token))
        {
            if (_stacks.size() < 2)
            {
                std::cerr << "Error\n";
                return ;
            }
          
            long long stackedAfter = _stacks.top();
            _stacks.pop();
            long long stackedBefore = _stacks.top();
            _stacks.pop();

            long long res; // result overflow check safe guard
           
            if (token == "+")
                res = stackedBefore + stackedAfter;
            else if (token == "-")
                res = stackedBefore - stackedAfter;
            else if (token == "*")
                res = stackedBefore * stackedAfter;
            else
            {
                if (stackedAfter != 0)
                    res = stackedBefore / stackedAfter;
                else
                {
                    std::cerr << "Error\n";
                    return ;
                }
            }

            if (res > std::numeric_limits<int>::max() || res < std::numeric_limits<int>::min())
            {
                std::cerr << "Error\n";
                return ;
            }

            _stacks.push(static_cast<int>(res));

        }
        else
        {
            std::cerr << "Error\n";
            return ;
        }
    }
    if (_stacks.size() != 1)
    {
        std::cerr << "Error\n";
        return ;
    }
    std::cout << _stacks.top() << "\n";
}


// $> ./RPN "1 2 * 2 / 2 * 2 4 - +"
// 0
// 1 -> 1
// 2 -> 1 2
// * _ (1 * 2) = 2 -> 2
// 2 -> 2 2
// / _ (2 / 2) = 1 -> 1
// 2 -> 1 2
// * _ (1 * 2) = 2 -> 2
// 2 -> 2 2
// 4 -> 2 2 4
// - _ 2 - 4 = - 2 -> 2 -2
// + _ 2 + (-2) = 0 -> 0
// 계산하는 순간 스택에 값이 충분한가를 따진다 개별적인 순간임

// stack <Data Type, container type> 변수 이름;
// stack<int, list<int>> st;

// stack 내부 컨테이너 바꾸기 https://blockdmask.tistory.com/100