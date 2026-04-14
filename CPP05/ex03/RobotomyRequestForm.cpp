#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string targetos) :AForm("RobotomyRequestForm", 72, 45) {

    _target = targetos;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), _target(src._target) {

    // 부모 먼저 초기화 하는게 내부 순서이니 맞게 써주기
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src){

    if (this != &src)
    {
        this->_target = src._target;
    }
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
    if (this->getSigned() == false)
        throw NoSignE();
    if (executor.getGrade() > getGradeE())
        throw GradeTooLowException();
   
    std::cout <<"(drrrrrrrrrrrrkrr): " << _target;
    // srand(static_cast<unsigned int>(time(NULL))); -> to main
    // rand() uses global state so to not reset each time calling this function..
    int num = rand();
    int result = num % 2;
    result == 1 ? (std::cout << " has been robotomized." << std::endl) : (std::cout << "'s robotomy failed." <<std::endl);
}

AForm* RobotomyRequestForm::makeForm(const std::string target){
    return new RobotomyRequestForm(target);
}


RobotomyRequestForm::~RobotomyRequestForm(){

}