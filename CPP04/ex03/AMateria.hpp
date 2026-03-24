#ifndef AMATERIA_HPP
#define AMATERIA_HPP

class ICharacter;
// #include "ICharacter.hpp"
#include <iostream>
//pure abstract class
// 공통 에러 처리 등.. 추상 클래스
class AMateria
{
	protected:

	std::string _type;

	public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& orig);
	AMateria& operator=(const AMateria &orig);
	virtual ~AMateria();

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0; // 꼭 다르게 구현해라!
	virtual void use(ICharacter& target); // 공통 기본 동작
};

#include "ICharacther.hpp"

#endif