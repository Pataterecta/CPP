#include "Bureaucrat.hpp"
// throw 문제 종류를 들고 던짐
// catch 그 종류 보고 맞는 처리 실행 - 예외 객체의 타입을 보고 맞는 처리 코드
// catch 를 reference 로 받는다 
// catch (std::exception) 경우는 모든 예외 한 번에 처리 가능

int main(void)
{
    Form f("construction approval", 99, 50);
    Form f0("happy cure contract", 1, 1);
    Form contracto("intern contract", 150, 150);
    try
    {
        Form contratito("tosign", 999, 999);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // try
    // {
        Bureaucrat bc("sosohappy", 1);
        bc.decValGrade(100);
        std::cout << bc;
        bc.signForm(f0);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // just to show that as try and catch is inside of the function, it doesnt need 
    // to be on the main caller side
    // but it can try and catch constructor out range cases
    try
    {
        Bureaucrat bc2("fonctionnaire", 151);
        bc2.signForm(f);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Bureaucrat bc3("intern", 150);
    std::cout << f;
    bc3.signForm(f);
    bc3.signForm(contracto);
    return (0);
}

