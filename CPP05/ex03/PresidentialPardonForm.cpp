#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string targetos) :AForm("PresidentialPardonForm", 25, 5) {

    _target = targetos;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), _target(src._target) {

    // 부모 먼저 초기화 하는게 내부 순서이니 맞게 써주기
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src){

    if (this != &src)
    {
        this->_target = src._target;
    }
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
    if (this->getSigned() == false)
        throw NoSignE();
    if (executor.getGrade() > getGradeE())
        throw GradeTooLowException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

// AForm* PresidentialPardonForm::beForm(const std::string &target){
//     return new PresidentialPardonForm(target);
// }


PresidentialPardonForm::~PresidentialPardonForm(){

}