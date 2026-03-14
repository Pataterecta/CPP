#include "Zombie.hpp"

int	main(void)
{
	Zombie stack("stackombie");
	stack.announce();
	Zombie *heap = newZombie("heapster");
	heap->announce();
	// == (*heap).announce();
	randomChump("rcstackombie");
	delete(heap);
	return 0;
}