#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:

    std::string _target;

    public:
    RobotomyRequestForm(std::string targetos);
    RobotomyRequestForm(const RobotomyRequestForm& src);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;
    
    // static AForm* beForm(const std::string &target);
};

#endif

// https://blockdmask.tistory.com/308 random function examples
// https://blockdmask.tistory.com/236 static cast