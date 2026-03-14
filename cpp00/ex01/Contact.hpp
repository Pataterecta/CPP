#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <iomanip>

class Contact {
	private :
	std::string prenom;
	std::string surnom;
	std::string nicknom;
	std::string p_num;
	std::string dsecret;

	public :
	void	set_con();
	void	show_table();
	void	show_con();
};

#endif