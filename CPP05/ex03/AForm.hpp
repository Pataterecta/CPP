#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>

class Bureaucrat;

class AForm {

    private:

    const std::string _name;
    bool _signed; // A boolean indicating whether it is signed (at construction, it is not)
    const int _gradeToS;
    const int _gradeToE;

    public:
    AForm();
    AForm(const std::string name, int gradeS, int gradeE);
    AForm(const AForm &other);
    AForm& operator=(const AForm &other);
    virtual ~AForm(void);

    const std::string& getName() const;
    bool getSigned() const;
    int getGradeS() const;
    int getGradeE() const;

    void beSigned(const Bureaucrat &bc);
    /*it changes the AForm’s status to signed if the bureaucrat’s grade is high enough
    (greater than or equal to the required one). Remember, grade 1 is higher than grade 2.
    If the grade is too low, throw a AForm::GradeTooLowException */

    virtual void execute(Bureaucrat const & executor) const = 0;

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
    class NoSignE : public std::exception
    {
        public:
        const char* what() const throw(){
            return "!!!Not Signed FORM!!!";
        }
    };


};

std::ostream& operator<<(std::ostream &o, const AForm &other);

#endif