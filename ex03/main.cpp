#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "--- Construction: ClapTrap only ONCE ---" << std::endl;
	DiamondTrap	diamond("Shiny");

	std::cout << "\n--- Identity ---" << std::endl;
	diamond.whoAmI();

	std::cout << "\n--- Stats: HP 100 (Frag), EP 50 (Scav), AD 30 (Frag) ---" << std::endl;
	diamond.attack("a bandit");
	diamond.takeDamage(99);
	diamond.beRepaired(9);

	std::cout << "\n--- Special abilities of both parents ---" << std::endl;
	diamond.guardGate();
	diamond.highFivesGuys();

	std::cout << "\n--- Copy constructor and assignment ---" << std::endl;
	DiamondTrap	copy(diamond);
	copy.whoAmI();
	DiamondTrap	assigned;
	assigned.whoAmI();
	assigned = diamond;
	assigned.whoAmI();

	std::cout << "\n--- Energy: 50 points, two already used ---" << std::endl;
	for (int i = 0; i < 48; i++)
		diamond.beRepaired(0);
	diamond.attack("nobody");

	std::cout << "\n--- Deleting a DiamondTrap through a ClapTrap pointer ---" << std::endl;
	ClapTrap	*ptr = new DiamondTrap("Pointy");
	ptr->attack("someone");
	delete ptr;

	std::cout << "\n--- Destruction: reverse order, ClapTrap last and once ---" << std::endl;
	return (0);
}
