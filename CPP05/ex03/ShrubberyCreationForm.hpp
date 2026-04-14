#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:

    std::string _target;
    void plantTree() const;

    public:
    ShrubberyCreationForm(std::string targetos);
    ShrubberyCreationForm(const ShrubberyCreationForm& src);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
    ~ShrubberyCreationForm();

    const std::string& getTarget() const;

    void execute(Bureaucrat const & executor) const;

    static AForm* makeForm(const std::string target);

};

#endif