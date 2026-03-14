#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <cstdlib>
#include <cctype>

class PhoneBook {
	private:

	Contact contacts[8];
	int		idx;
	int		new_pos;
	std::string	asked;

	public:
	
	PhoneBook();
	void	do_add();
	void	do_search();
};

#endif