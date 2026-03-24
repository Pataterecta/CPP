#include "Cure.hpp"

// Cure::Cure() : _type("cure")
// {
// } 이러지마 제발~ >>> 문제 상황! 
// 안좋은 설계 :
// getType 은 AMateria 쪽 상태만 보기에 부모 부분을 생성시 제대로 초기화 했어야
// 이 경우로 갔으면 getType 을 바로 못써서 getType 이 Ice 인지 Cure 인지 다운캐스트 판독기가 됨;
// 1) 부모가 자식 다운캐스트 판별 2) 자식마자 getType 오버라이드;;;

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure&orig) : AMateria(orig)
{
}

Cure& Cure::operator=(const Cure &orig)
{
	(void)orig;
	return (*this);
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; // ' 확인하기~
}


