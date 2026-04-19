#include <iostream>
#include "Array.hpp"

// initialization test

// int main(void)
// {
//     Array<int> numbers(3);
//     int* hello = new int[3]();
//     int* bye = new int[3]; // without init
//     for (int i = 0; i < 3; i++)
//     {
//         std::cout << "numbers: " << numbers[i] << std::endl;
//         std::cout << "hello: " << hello[i] << std::endl;
//         std::cout << "bye no init: " << bye[i] << std::endl;
//         // check init value
//     }
//     delete[](hello);
//     delete[](bye);
//     return (0);
// }

// explicit test -> test with explicit to check compile error 
int main(void)
{
    Array<int> charle = 3; // same as Array<int> charle(3);
    for (unsigned int i = 0; i < charle.size(); i++)
    std::cout << charle[0] <<std::endl; 
    std::cout << "grammer test" <<std::endl;
    Array<int> charlotte(4);
    for (unsigned int i = 0; i < charlotte.size(); i++)
    std::cout << charlotte[0] <<std::endl; 
    std::cout << "grammer test end" <<std::endl;

    std::cout << "op[] overloading test uncomment the debug" <<std::endl;
    
    std::cout << "non const op cases" <<std::endl;
    
    charlotte[0] = 32; // T& operator[](unsigned int idx)
    std::cout << charlotte[0] << std::endl; // T& operator[](unsigned int idx)
    const int a = 33;
    charlotte[1] = a;
    std::cout << charlotte[1] << std::endl;

    Array<const int> chica(1); 
    // T = const int, 객체 타입은 Array<const int> 객체 자체는 non-const
    // qksghksguddms  const int& 이지만 객체는  const 정의가 아님
    std::cout << chica[0] << std::endl;

    std::cout << "const op case" <<std::endl;
    const Array<const int> chico(2);
    std::cout << chico[0] << std::endl;

    // grammar size(chico) is not correct
    // only use it when instance is there, like a.size() of containers
    return (0);
}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[10] = 0;
//         std::cout << "I'm not gonna throw cuz kind idx\n";
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }