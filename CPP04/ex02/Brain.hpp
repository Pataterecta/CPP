#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
// #include <stdexcept>
#include <sstream>

class Brain {

	private:

	std::string ideas[100];

	public:
	Brain();
	Brain (const Brain &orig);
	Brain &operator=(const Brain &orig);
	~Brain();

	const std::string &getIdea(int idx) const;
	void setIdea(int idx, std::string input);
};

#endif