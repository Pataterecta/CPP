#include "Utils.hpp"

int main(void)
{
    Base *mom = generate();
    identify(mom);
    Base &dad = *mom;
    identify(dad);
    std::cout << "why i chose to name it like this while the action comes after is..\n";
    delete mom;
    return (0);
}