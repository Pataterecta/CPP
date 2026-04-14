#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

class AForm;
class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

class Intern
{
    private:
    
    public:
    Intern();
    Intern(const Intern& src);
    Intern& operator=(const Intern &src);
    ~Intern();

    AForm* makeForm(const std::string formname, const std::string target);

};

#endif

// 일반 멤버 함수 = 비정적 멤버 함수는 객체 없이 호출할 수 없음 객체가 필요해서 일반 함수 포인터에 못 넣음
// 스태틱 멤버 함수 : 객체가 필요 없어서 일반 함수처럼 함수 포인터에 넣을 수 있음
// 즉 this 가 필요한 함수냐 아니냐.. (스태틱은 필요 없지예)