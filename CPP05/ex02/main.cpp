#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>
// throw 문제 종류를 들고 던짐
// catch 그 종류 보고 맞는 처리 실행 - 예외 객체의 타입을 보고 맞는 처리 코드
// catch 를 reference 로 받는다 
// catch (std::exception) 경우는 모든 예외 한 번에 처리 가능


int main(void)
{
    srand(static_cast<unsigned int>(time(NULL)));
    PresidentialPardonForm f_pardon("voleur de nourriture");
    ShrubberyCreationForm f_tree("flower tree");
    ShrubberyCreationForm f_fruitTree("FRUIIIIIT tree");
    RobotomyRequestForm f_robo("considered crazy person");

    Bureaucrat bc1("Monsieur KIM", 1);

    bc1.signForm(f_pardon);
    bc1.executeForm(f_pardon);
    bc1.signForm(f_tree);
    bc1.executeForm(f_tree);
    bc1.signForm(f_robo);
    bc1.executeForm(f_robo);

    Bureaucrat bc2("random civil", 150);
    bc2.signForm(f_pardon);
    bc2.executeForm(f_pardon);
    bc2.signForm(f_tree);
    bc2.executeForm(f_tree);
    bc2.signForm(f_robo);
    bc2.executeForm(f_robo);

    Bureaucrat bc3("Haut fonctionnaire", 25);
    bc3.signForm(f_pardon);
    bc3.executeForm(f_pardon);

    Bureaucrat bc4("mid fonctionnaire", 72);
    bc4.signForm(f_fruitTree);
    bc4.executeForm(f_fruitTree);
    bc4.signForm(f_robo);
    bc4.executeForm(f_robo);

    return (0);
}

