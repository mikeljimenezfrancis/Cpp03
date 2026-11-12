#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "--- Construction chaining: ClapTrap first, then ScavTrap ---" << std::endl;
	ScavTrap	scav("Serena");

	std::cout << "\n--- ScavTrap actions (100 HP, 50 EP, 20 AD) ---" << std::endl;
	scav.attack("a bandit");
	scav.takeDamage(30);
	scav.beRepaired(10);
	scav.guardGate();

	std::cout << "\n--- Copy constructor and assignment ---" << std::endl;
	ScavTrap	copy(scav);
	ScavTrap	assigned;
	assigned = scav;
	copy.attack("a copy target");

	std::cout << "\n--- Plain ClapTrap still works (10 HP, 10 EP, 0 AD) ---" << std::endl;
	{
		ClapTrap	clap("Clappy");
		clap.attack("Serena");
	}

	std::cout << "\n--- Deleting a ScavTrap through a ClapTrap pointer ---" << std::endl;
	ClapTrap	*ptr = new ScavTrap("Pointy");
	ptr->attack("someone");
	delete ptr;

	std::cout << "\n--- Running out of energy (50 points) ---" << std::endl;
	for (int i = 0; i < 50; i++)
		scav.beRepaired(0);
	scav.attack("nobody");

	std::cout << "\n--- Destruction chaining: ScavTrap first, then ClapTrap ---" << std::endl;
	return (0);
}
