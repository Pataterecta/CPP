#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default_Form"), _gradeToS(150), _gradeToE(150)
{
    // i can actually just put the prototype only on the .hpp and not define it but for the canonical AForm..
}

AForm::AForm(const std::string name, int gradeS, int gradeE) : _name(name), _gradeToS(gradeS), _gradeToE(gradeE)
{
    if (gradeS < 1 || gradeE < 1)
        throw GradeTooHighException();
    if (gradeS > 150 || gradeE > 150)
        throw GradeTooLowException(); // 위에다 저리 써놓고 여기다 엑셉션 넣어도 먹히나?
    _signed = false;
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _gradeToS(other._gradeToS), _gradeToE(other._gradeToE)
{

}

AForm& AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return (*this);
}

AForm::~AForm(void)
{

}

// getters 

const std::string& AForm::getName() const
{
    return this->_name;
}

bool AForm::getSigned() const
{
    return this->_signed;
}

int AForm::getGradeS() const
{
    return this->_gradeToS;
}

int AForm::getGradeE() const
{
    return this->_gradeToE;
}

//

void AForm::beSigned(const Bureaucrat &bc)
{
    if (this->_gradeToS >= bc.getGrade())
    {   
        _signed = true;
        return ;
    }
    throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream &o, const AForm &other)
{
    std::string res;
    if (other.getSigned())
        res = "yes";
    else
        res = "no";
    o << other.getName() << ", grade needed to sign " << other.getGradeS() << ", grade needed to execute " << other.getGradeE() << " is it signed " << res << " ." << std::endl;
    return (o);
}
