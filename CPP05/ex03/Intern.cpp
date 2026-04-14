#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


Intern::Intern(){

}

Intern::Intern(const Intern& src) {
    (void)src;
}

Intern& Intern::operator=(const Intern &src){
    // void(src); 가 아니고 (void)src; 임 이거 왤케 맨날 틀려!?
    (void)src;
    return (*this);
}

// if not in this way then put statics in Intern's private 
AForm* Intern::makeForm(const std::string formname, const std::string target){

    typedef AForm* (*mF)(const std::string); // AForm* 을 반환하고 std::string 을 인자로 받는 함수의 포인터 타입 mF 는 함수 포인터의 타입 이름
    // 이 타입과 함수가 일치해야 함
    mF fps[3] = 
    {
        // 함수 포인터 3개 배열, 각각은 함수의 주소 즉 포인터 값이 들어간다
        &PresidentialPardonForm::makeForm, &RobotomyRequestForm::makeForm, &ShrubberyCreationForm::makeForm
    };
    std::string names[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    for (int i = 0; i < 3; i++)
    {
        if (names[i] == formname)
            return fps[i](target); // fps[i] 가 가리키는 함수 주소로 가서 target 넣고 실행
    }
    return 0;
}

Intern::~Intern(){

}