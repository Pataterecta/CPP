#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default_form"), _gradeToS(150), _gradeToE(150)
{
    // i can actually just put the prototype only on the .hpp and not define it but for the canonical form..
}

Form::Form(const std::string name, int gradeS, int gradeE) : _name(name), _gradeToS(gradeS), _gradeToE(gradeE)
{
    if (gradeS < 1 || gradeE < 1)
        throw GradeTooHighException();
    if (gradeS > 150 || gradeE > 150)
        throw GradeTooLowException(); // 위에다 저리 써놓고 여기다 엑셉션 넣어도 먹히나? yes
    _signed = false;
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
    return (*this);
}

Form::~Form(void)
{

}

// getters 

const std::string& Form::getName() const
{
    return this->_name;
}

bool Form::getSigned() const
{
    return this->_signed;
}

int Form::getGradeS() const
{
    return this->_gradeToS;
}

int Form::getGradeE() const
{
    return this->_gradeToE;
}

//

void Form::beSigned(const Bureaucrat &bc)
{
    if (this->_gradeToS >= bc.getGrade())
    {   
        _signed = true;
        return ;
    }
    throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream &o, const Form &other)
{
    std::string res;
    if (other.getSigned() == true)
        res = "yes";
    if (other.getSigned() == false)
        res = "no";
    o << other.getName() << ", grade needed to sign " << other.getGradeS() << ", grade needed to execute " << other.getGradeE() << " is it signed " << res << " ." << std::endl;
    return (o);
}