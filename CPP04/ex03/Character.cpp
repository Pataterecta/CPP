#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
		this->_slots[i] = NULL;
	// _slots 는 이미 배열이라 포인터 아니니 관리 필요 없고
	// 각각 내용물은 clone 으로 들어올거니까 포인터만 칸에 맞춰 NULL 해두면 됨
}

Character::Character(std::string Name) : _Name(Name)
{
	for (int i = 0; i < 4; i++)
		this->_slots[i] = NULL;
	// _slots 는 이미 배열이라 포인터 아니니 관리 필요 없고
	// 각각 내용물은 clone 으로 들어올거니까 포인터만 칸에 맞춰 NULL 해두면 됨
}

Character::Character(const Character &orig) : _Name(orig._Name)
{
	for (int i = 0; i < 4; i++)
		this->_slots[i] = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (orig._slots[i])
			this->_slots[i] = orig._slots[i];
	}
}

Character& Character::operator=(const Character &orig)
{
	// 기존 자원 정리 후 새 자원 복사 흐름으로 NULL 체크도 해야
	// 원본은 읽어서 복사만, 건드리지 말기
	if (!(this == &orig))
	{
		this->_Name = orig._Name;
		for (int i = 0; i < 4; i++)
		{	
			if (this->_slots[i])
				delete _slots[i];
		}
		for (int i = 0; i < 4; i++)
		{
			if (orig._slots[i])
				this->_slots[i] = orig._slots[i]->clone();
			else
				this->_slots[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	for(int i = 0; i < 4; i++)
		delete this->_slots[i];
	// delete nullptr does nth so its fine
}

std::string const & Character::getName() const
{
	return (this->_Name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_slots[i] == NULL)
		{	
			// std::cout << "materia equipped" << std::endl;
			this->_slots[i] = m;
			return ;
		}
	}
	// std::cout << "all slots are equipped no *equip* action \n";
	// 여기서 m idx 넘어가는 경우 값 관리를 어케할꼬..
	return ;
}

void Character::unequip(int idx)
{
	if (!(0<= idx && idx < 4))
	{
		// std::cout << idx << " is out of idx to (unequip)" << std::endl;
		return ;
	}
	// std::cout << idx << " slot is unequipped" << std::endl;
	this->_slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (!(0<= idx && idx < 4))
	{	
		// std::cout << idx << " is out of idx to (use)" << std::endl;
		return ;
	}
	if (_slots[idx])
		_slots[idx]->use(target);
}
