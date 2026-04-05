#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Form {

    private:

    const std::string _name;
    bool _signed; // A boolean indicating whether it is signed (at construction, it is not)
    const int _gradeToS;
    const int _gradeToE;

    public:

    void beSigned(Bureaucrat &bc);
    /*it changes the form’s status to signed if the bureaucrat’s grade is high enough
    (greater than or equal to the required one). Remember, grade 1 is higher than grade 2.
    If the grade is too low, throw a Form::GradeTooLowException */

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


};

#endif