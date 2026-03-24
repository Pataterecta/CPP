#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

// Ice::Ice(const Ice&orig) : _type("ice")
// {
//		(void)orig;
// } -> Ice instances always as "ice" but it needs a overriding getType so dont do..

Ice::Ice(const Ice&orig) : AMateria(orig)
{
}
// why not Ice(orig) -> 자신의 복사 생성자를 또 호출, 재귀 모순
// AMateria 가 _type 을 관리하니까 구현도 책임도 AMateria 가

Ice& Ice::operator=(const Ice &orig)
{
	(void)orig;
	return (*this);
}

Ice::~Ice()
{
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}


AMateria* Ice::clone() const
{
	return new Ice(*this);
}
