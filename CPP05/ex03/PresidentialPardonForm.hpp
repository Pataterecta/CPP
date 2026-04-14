#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>
class Bureaucrat;

class PresidentialPardonForm : public AForm // 상속은 어쨌든 이렇지..
{
    private:

    std::string _target;

    public:
    PresidentialPardonForm(std::string targetos);
    PresidentialPardonForm(const PresidentialPardonForm& src);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const & executor) const;

    static AForm* makeForm(const std::string target);

    //!!!!! no need AForm level rule!!!!
    // class GradeTooHighException : public std::exception
    // {
    //     public: 
    //     const char* what() const throw(){
    //     return "Grade too high";
    //     }
    // };
    // class GradeTooLowException : public std::exception
    // {
    //     public:
    //     const char* what() const throw(){
    //         return "Grade too low";
    //     }
    // };
};

#endif
