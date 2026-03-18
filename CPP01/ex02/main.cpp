// • A string variable initialized to "HI THIS IS BRAIN".
// • stringPTR: a pointer to the string.
// • stringREF: a reference to the string.
// Your program must print:
// • The memory address of the string variable.
// • The memory address held by stringPTR.
// • The memory address held by stringREF.
// And then:
// • The value of the string variable.
// • The value pointed to by stringPTR.
// • The value pointed to by stringREF.

#include <iostream>

int	main(void)
{
	std::cout << "Salut c'est pour montrer seulement.. pas de zombies.." << std::endl << std::endl;
	std::string htib = "HI THIS IS BRAIN";
	std::string *htib_ptr = &htib;
	std::string &htib_ref = htib;

	std::cout << "*first_for the memory addresses" << std::endl;
	std::cout << "The memory address of the string variable: " << &htib << std::endl;
	std::cout << "The memory address held by stringPTR: " << htib_ptr << std::endl;
	std::cout << "The memory address not held by stringPTR: " << &htib_ptr << std::endl; // pas pareil
	std::cout << "The memory address held by stringREF: " << &htib_ref << std::endl;
	
	std::cout << std::endl << "*second_for the values" <<std::endl;
	std::cout << "The value of the string variable: " << htib << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *htib_ptr << std::endl;
	std::cout << "The value pointed to by stringREF: " << htib_ref << std::endl;

	return 0;
}