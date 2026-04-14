#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <fcntl.h>


ShrubberyCreationForm::ShrubberyCreationForm(std::string targetos) :AForm("ShrubberyCreationForm", 145, 137) {

    _target = targetos;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), _target(src._target) {

    // 부모 먼저 초기화 하는게 내부 순서이니 맞게 써주기
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src){

    if (this != &src)
    {
        this->_target = src._target;
    }
    return (*this);
}

const std::string& ShrubberyCreationForm::getTarget() const{
    return _target;
}

void ShrubberyCreationForm::plantTree() const{
    std::fstream fs;
    std::string name = _target + "_shrubbery";
    // fs.open(name.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
    fs.open(name.c_str(), std::fstream::out);
    fs << "       _-_\n" << "    /~~   ~~\\\n" << " /~~         ~~\\\n" << "{               }\n" << " \\  _-     -_  /\n" << "   ~  \\\\ //  ~\n" <<  "_- -   | | _- _\n" << "  _ -  | |   -_\n" << "      // \\\\\n";
    fs.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
    if (this->getSigned() == false)
        throw NoSignE();
    if (executor.getGrade() > getGradeE())
        throw GradeTooLowException();
    plantTree();
}

AForm* ShrubberyCreationForm::makeForm(const std::string target){
    return new ShrubberyCreationForm(target);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){

}