#ifndef CHARACTER_HPP
#define CHARACTER_HPP

// class ICharacter; : 상속시엔 전방 선언 안됨 incomplete type not allowed
#include "AMateria.hpp"

class Character : public ICharacter {

	private:
	std::string _Name;
	AMateria* _slots[4];

	public:

	Character();
	Character(std::string Name);
	Character(const Character &orig);
	Character &operator=(const Character &orig);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

};

#endif