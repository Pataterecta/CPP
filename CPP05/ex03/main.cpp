#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <ctime>
// throw 문제 종류를 들고 던짐
// catch 그 종류 보고 맞는 처리 실행 - 예외 객체의 타입을 보고 맞는 처리 코드
// catch 를 reference 로 받는다 
// catch (std::exception) 경우는 모든 예외 한 번에 처리 가능


int main(void)
{
    srand(static_cast<unsigned int>(time(NULL)));

    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    Bureaucrat bc("happy fonctionnaire", 20);
    bc.signForm(*rrf);
    bc.executeForm(*rrf);
    // delete(rrf); without virtual // error: delete called on 'AForm' that is abstract but has non-virtual destructor [-Werror,-Wdelete-abstract-non-virtual-dtor]
    // delete(dynamic_cast<RobotomyRequestForm*>(rrf)); // error: delete called on non-final 'RobotomyRequestForm' that has virtual functions but non-virtual destructor [-Werror,-Wdelete-non-abstract-non-virtual-dtor]
    // virtual ~AForm(); 부모 포인터로 자식 객체를 지울 수 있도록 로보토미->에이폼 순서로 delete
    delete(rrf);

    AForm* rrf2;
    rrf2 = someRandomIntern.makeForm("presidential pardon", "Prisoner");
    bc.signForm(*rrf2);
    bc.executeForm(*rrf2);
    delete(rrf2); // without this of course leak

    rrf2 = someRandomIntern.makeForm("shrubbery creation", "dancing tree");
    bc.signForm(*rrf2);
    bc.executeForm(*rrf2);
    delete(rrf2);

    return (0);
}

