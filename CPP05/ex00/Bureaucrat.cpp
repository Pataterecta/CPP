#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        // *(const_cast<std::string*>(&_name)) = other._name;
        this->_grade = other._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{   
}

const std::string& Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::setGrade(int note)
{
    if (note > 150)
        throw GradeTooLowException();
    else if (note < 1)
        throw GradeTooHighException();
    this->_grade = note;
    
}

void Bureaucrat::incGrade(void)
{
    if (this->_grade - 1 < 1)
        throw GradeTooHighException();
    _grade = _grade - 1;
}

void Bureaucrat::decGrade(void)
{
    if (this->_grade + 1 > 150)
        throw GradeTooLowException();
    _grade = _grade + 1;
}

void Bureaucrat::incValGrade(int note)
{
    if (this->_grade - note < 1)
        throw GradeTooHighException();
    _grade = _grade - note;
}

void Bureaucrat::decValGrade(int note)
{
    if (this->_grade + note > 150)
        throw GradeTooLowException();
    _grade = _grade + note;
}

std::ostream& operator<<(std::ostream &o, const Bureaucrat &other)
{
    o << other.getName() << ", bureaucrat grade " << other.getGrade() << "." << std::endl;
    return (o);
}
// 멤버 연산자면 안돼 왜냐면 왼쪽 피연산자가 그 클래스일 때만 호출되기 때문임!
// 그래서 이것 땜시 getter 가 필요한거임.. 멤버 함수가 아니라서..
