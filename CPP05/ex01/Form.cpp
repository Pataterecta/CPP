#include "Form.hpp"


Form::Form(const std::string name, int gradeS, int gradeE) : _name(name), _gradeToS(gradeS), _gradeToE(gradeE)
{
    this->_signed = false;
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _gradeToS(other._gradeToS), _gradeToE(other._gradeToE)
{

}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
}

Form::~Form(void)
{

}

const std::string& Form::getName() const
{
    return this->_name;
}

void Form::beSigned(const Bureaucrat &bc)
{
    if (this->_gradeToS < bc.getGrade())
        bc.signForm(*this);
    if 
}
