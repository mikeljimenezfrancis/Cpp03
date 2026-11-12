#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "--- Construction chaining: ClapTrap first, then FragTrap ---" << std::endl;
	FragTrap	frag("Fraggy");

	std::cout << "\n--- FragTrap actions (100 HP, 100 EP, 30 AD) ---" << std::endl;
	frag.attack("a skag");
	frag.takeDamage(40);
	frag.beRepaired(15);
	frag.highFivesGuys();

	std::cout << "\n--- Copy constructor and assignment ---" << std::endl;
	FragTrap	copy(frag);
	FragTrap	assigned;
	assigned = frag;
	assigned.attack("a mirror");

	std::cout << "\n--- ScavTrap next to FragTrap ---" << std::endl;
	{
		ScavTrap	scav("Serena");
		scav.attack("Fraggy");
		frag.takeDamage(20);
		scav.guardGate();
	}

	std::cout << "\n--- Deleting a FragTrap through a ClapTrap pointer ---" << std::endl;
	ClapTrap	*ptr = new FragTrap("Pointy");
	ptr->attack("someone");
	delete ptr;

	std::cout << "\n--- Killing the FragTrap ---" << std::endl;
	frag.takeDamage(1000);
	frag.attack("anyone");
	frag.highFivesGuys();

	std::cout << "\n--- Destruction chaining: FragTrap first, then ClapTrap ---" << std::endl;
	return (0);
}
