#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

// 생성과 사용을 분리하여 생성은 MateriaSource 가 사용은 Character 가
// pure virtual 함수 하나라도 구현 안하면 얘도 abstract class 되기에
// 상속 받은 애는 싹다 구현하라! (컴파일러가 강제함)
class MateriaSource : public IMateriaSource {

	private:
	AMateria* _skills[4];
	public:

	MateriaSource();
	MateriaSource(const MateriaSource &orig);
	MateriaSource &operator=(const MateriaSource &orig);
	~MateriaSource();

	void learnMateria(AMateria* m);
	// virtual void learnMateria(AMateria*) = 0; 왜 얘는 m 이 없지? 변수 이름은 시그니처에 포함 안됨!
	// virtual AMateria* createMateria(std::string const & type) = 0; 얜 그래도 타입이 있는데
	// void foo(int) 같은 경우 안에서 인트 안써도 경고 방지용이래 흠 신기허군.. unused param 경고 안 뜬 다네
	AMateria* createMateria(std::string const & type);
};

#endif