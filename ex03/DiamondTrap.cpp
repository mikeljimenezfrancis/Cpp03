#include "DiamondTrap.hpp"
#include <iostream>

/*
 * ClapTrap is a virtual base: the most derived class (DiamondTrap) constructs
 * it directly, exactly once. The ClapTrap(...) calls inside the ScavTrap and
 * FragTrap constructors are ignored when they build a DiamondTrap.
 *
 * Base order (ScavTrap, then FragTrap) means FragTrap's constructor body runs
 * last and leaves 100 HP / 100 EP / 30 AD. We only need to restore ScavTrap's
 * energy points (50).
 */

DiamondTrap::DiamondTrap()
	: ClapTrap("default_clap_name"), ScavTrap(), FragTrap(), name("default")
{
	energy = 50;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &newName)
	: ClapTrap(newName + "_clap_name"), ScavTrap(newName), FragTrap(newName),
	name(newName)
{
	energy = 50;
	std::cout << "DiamondTrap " << name << " constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
	std::cout << "DiamondTrap " << name << " copy constructed" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		name = other.name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " destroyed" << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap " << name
		<< ", my ClapTrap name is " << ClapTrap::name << std::endl;
}
