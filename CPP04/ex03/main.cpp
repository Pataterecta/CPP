#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* her = new Character("Aerith");

	AMateria* tmp;
	tmp = src->createMateria("ice"); // 직접 new 하지 말고 문자열로 요청해서 생성하기
	her->equip(tmp);
	tmp = src->createMateria("cure"); // 내부 구현을 몰라도 되는 좋은 점임
	her->equip(tmp);

	ICharacter* bob = new Character("Valentine");
	her->use(0, *bob);
	her->use(1, *bob);
	her->use(1, *bob);
	std::cout << "****no equip try*****" << std::endl;
	bob->use(0, *her);
	bob->use(5, *her);
	std::cout << "*****************" << std::endl;
	// bob->equip(tmp); -> 같은 포인터 줘서 나중에 세그폴트
	AMateria* tmp2;
	tmp2 = src->createMateria("ice");
	bob->equip(tmp2);
	tmp2 = src->createMateria("ice");
	bob->equip(tmp2);
	tmp2 = src->createMateria("ice");
	bob->equip(tmp2);
	tmp2 = src->createMateria("ice");
	bob->equip(tmp2);

	bob->use(0, *her);
	bob->use(1, *her);
	bob->use(2, *her);
	bob->use(3, *her);
	bob->use(4, *her);
	std::cout << "*********for dont do a thing 5th create*** nth and caller to handle" << std::endl;
	tmp2 = src->createMateria("ice");
	bob->equip(tmp2);
	delete tmp2;
	std::cout << "*******caller test ok******" << std::endl;
	
	std::cout << "******unequip test********" << std::endl;
	// tmp deepcopy from createMateria on AMateria pointer
	her->unequip(1);
	AMateria* tmp3;
	tmp3 = src->createMateria("cure");
	her->equip(tmp3);
	delete tmp;
	std::cout << "******unequip test ok********" << std::endl;
	delete bob;
	delete her;
	delete src;
	return 0;
}

/*

IMateriaSource = 규약
MateriaSource = 실제 구현, 공장
learnMateria() = 이 타입을 기억해라
createMateria() = 요청하면 clone으로 새로 만들어라

*/