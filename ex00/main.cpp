#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "--- Construction ---" << std::endl;
	ClapTrap	clap("Clappy");
	ClapTrap	copy(clap);
	ClapTrap	assigned;
	assigned = clap;

	std::cout << "\n--- Basic actions ---" << std::endl;
	clap.attack("a target dummy");
	clap.takeDamage(3);
	clap.beRepaired(2);

	std::cout << "\n--- Running out of energy (10 points) ---" << std::endl;
	for (int i = 0; i < 9; i++)
		clap.attack("a wall");
	clap.attack("a wall");
	clap.beRepaired(1);

	std::cout << "\n--- Running out of hit points ---" << std::endl;
	copy.takeDamage(25);
	copy.takeDamage(1);
	copy.attack("anyone");
	copy.beRepaired(5);

	std::cout << "\n--- Destruction ---" << std::endl;
	return (0);
}
