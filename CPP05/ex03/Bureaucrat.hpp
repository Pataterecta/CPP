#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <exception>

class Bureaucrat {

    private:

    const std::string _name;
    int _grade;


    public:
    Bureaucrat();
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat& operator=(const Bureaucrat &other);
    // std::cout 은 객체(변수), 함수 반환 타입 자리엔 타입이 와야함, 반환도 ostream& 인건 체이닝 때문
    // 레퍼 안쓰면 진짜 변수가 아닌 복사된 값을 가지고 노는거라 문제 생김
    // std::cout << b1 << b2; 가능하도록.. 이건 cout 객체에다가 b1을 넣는다임
    ~Bureaucrat();

    class GradeTooHighException : public std::exception
    {
        public: 
        const char* what() const throw(){
        return "Grade too high";
        }
    };
    class GradeTooLowException : public std::exception
    {
        public:
        const char* what() const throw(){
            return "Grade too low";
        }
    };
    const std::string& getName() const;
    int getGrade() const;
    void setGrade(int note);
    void incGrade(void);
    void decGrade(void);
    void incValGrade(int note);
    void decValGrade(int note);
    void signForm(AForm &f) const; // this 를 바꾸는게 아니라 다른 객체면 const okidoki 임! 이것 때문에 헷갈렸음
    /* This function must
    call AForm::beSigned() to attempt to sign the AForm. If the AForm is signed successfully, it
    will print something like:
    <bureaucrat> signed <AForm>
    Otherwise, it will print something like:
    <bureaucrat> couldn’t sign <AForm> because <reason>. */

    void executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream &o, const Bureaucrat &other);


// what 함수는 std::exception 클래스에서 상속 받은 가상 함수(부모에서 이미 virtual임), 예외 객체애 대한 설명을 문자열로 반환
// const throw : 이 함수가 예외를 던지지 않고 발생시 안전히 호출 될 수 있다 발생 상황 정보 포함
// https://wo-dbs.tistory.com/159

#endif