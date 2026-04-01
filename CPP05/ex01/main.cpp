#include "Bureaucrat.hpp"
// throw 문제 종류를 들고 던짐
// catch 그 종류 보고 맞는 처리 실행 - 예외 객체의 타입을 보고 맞는 처리 코드
// catch 를 reference 로 받는다 
// catch (std::exception) 경우는 모든 예외 한 번에 처리 가능

int main(void)
{

    Bureaucrat bc("happy", 12);
    try
    {
        bc.incGrade(11);
        std::cout << bc << std::endl;
        Bureaucrat bc2("sad", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        bc.incGrade(11);
        std::cout << bc << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat bc3("sosohappy", 1);
        bc3.decGrade(100);
        std::cout << bc3;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat bc4("lol", -1);
        bc4.decGrade(100);
        std::cout << bc4;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
