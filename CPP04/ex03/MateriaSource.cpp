#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_skills[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &orig)
{
	for (int i = 0; i < 4; i++)
		this->_skills[i] = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (orig._skills[i])
			this->_skills[i] = orig._skills[i];
	}
}

MateriaSource & MateriaSource::operator=(const MateriaSource &orig)
{
	if (!(this == &orig))
	{
		for (int i = 0; i < 4; i++)
		{	
			if (this->_skills[i])
				delete _skills[i];
		}
		for (int i = 0; i < 4; i++)
		{
			if (orig._skills[i])
				this->_skills[i] = orig._skills[i]->clone();
			else
				this->_skills[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < 4; i++)
		delete this->_skills[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	// 복제본을 넘긴다
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_skills[i])
		{	
			this->_skills[i] = m->clone();
			delete m;
			return ;
		}
	}
	// std::cout << "every slots * learn * full" << std::endl;
	delete m;
	// 이 m 의 메모리 관리..
	return ;
}


AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_skills[i] && _skills[i]->getType() == type)
			return _skills[i]->clone();
	}
	return 0;
}
