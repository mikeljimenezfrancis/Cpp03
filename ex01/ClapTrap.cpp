#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("default"), health(10), energy(10), atk(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &newName)
	: name(newName), health(10), energy(10), atk(0)
{
	std::cout << "ClapTrap " << name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name), health(other.health), energy(other.energy), atk(other.atk)
{
	std::cout << "ClapTrap " << name << " copy constructed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		name = other.name;
		health = other.health;
		energy = other.energy;
		atk = other.atk;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (health == 0 || energy == 0)
	{
		std::cout << "ClapTrap " << name << " can't attack: no "
			<< (health == 0 ? "attack" : "energy") << " points left!" << std::endl;
		return ;
	}
	energy--;
	std::cout << "ClapTrap " << name << " attacks " << target
		<< ", causing " << atk << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (health == 0)
	{
		std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
		return ;
	}
	if (amount >= health)
		health = 0;
	else
		health -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount
		<< " points of damage! Hit points left: " << health << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (health == 0 || energy == 0)
	{
		std::cout << "ClapTrap " << name << " can't repair: no "
			<< (health == 0 ? "attack" : "energy") << " points left!" << std::endl;
		return ;
	}
	energy--;
	health += amount;
	std::cout << "ClapTrap " << name << " repairs itself for " << amount
		<< " attack points! Attack points now: " << health << std::endl;
}
