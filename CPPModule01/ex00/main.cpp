#include "Zombie.hpp"

int main()
{
	randomChump("Efe");
	Zombie* zombie = newZombie("Mete");
	if (!zombie)
	{
		std::cerr << "Allocation error!" << std::endl;
		return 1;
	}

	(*zombie).announce();
	delete(zombie);
	return 0;
}