# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
	private:
	std::string name;

	public:
	Zombie(std:: string name);
	~Zombie(void);
	void	announce(void);
	// 좀비를 만들고 이름짓고 리턴한다 그래서 밖에서도 쓰라고
	// 좀비를 만들고 이름짓고 스스로 선언하게 한다..??
	// 좀비를 언제 allocate 스택 or 힙 위한 것
	// 필요 없어진 좀비들은 destroy 해라
	// destructor 는 좀비의 이름을 디버깅을 위해 프린트해야함
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif