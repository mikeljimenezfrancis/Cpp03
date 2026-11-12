#pragma once

# include <string>

class ClapTrap
{
	private:
		std::string		name;
		unsigned int	health;
		unsigned int	energy;
		unsigned int	atk;

	public:
		ClapTrap();
		ClapTrap(const std::string &newName);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
