#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	health = 100;
	energy = 50;
	atk = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &newName) : ClapTrap(newName)
{
	health = 100;
	energy = 50;
	atk = 20;
	std::cout << "ScavTrap " << name << " constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << name << " copy constructed" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destroyed" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (health == 0 || energy == 0)
	{
		std::cout << "ScavTrap " << name << " can't attack: no "
			<< (health == 0 ? "hit" : "energy") << " points left!" << std::endl;
		return ;
	}
	energy--;
	std::cout << "ScavTrap " << name << " fiercely attacks " << target
		<< ", causing " << atk << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}
