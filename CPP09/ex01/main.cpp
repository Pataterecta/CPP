#include "RPN.hpp"
#include <list>
#include <iostream>

// int main(int ac, char **av)
// {
//     if (ac != 2)
//         return (0);
    
//     return (0);
// }

int main(void)
{
    char array[] = {'9', '8', '*'};
    std::list<char> L(array, array + 3);
    std::cout << *(L.begin()) << std::endl;

    return (0);
}

// 스트링으로 받는다 파싱을 한다.. 
// 괄호나 소수는 처리 안해도 된다
// verted Polish mathematical expression as an argument.
// always be less than 10 (i take it as 0 to 9)
//  handle "+ - / *"

// Lorsque je regarde les definitions sur le Reverse Polish Notation original on ne peux pas avoir de valeur negative
// Site pour calculer --> https://www.dcode.fr/reverse-polish-notation

// Il y a aussi ...
// https://paodayag.dev/reverse-polish-notation-js-parser/converter.html
// Qui semble plus permissif sur certains points
// Ou plutôt : https://paodayag.dev/reverse-polish-notation-js-parser/index.html
// qui prendra les valeurs négatives
// et valeurs à virgule