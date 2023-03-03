/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:13:59 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/28 15:12:02 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define RESET 	"\033[0m"
#define GREEN 	"\033[38;5;46m"
#define WHITE 	"\033[38;5;15m"
#define GREY 	"\033[38;5;8m"
#define BLUE	"\033[1;34m"
#define ORANGE 	"\033[38;5;202m"
#define RED 	"\033[38;5;160m"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	this->_name = "Unknow";
	this->_hit_point = 10;
	this->_energy_point = 10;
	this->_attack_damage = 0;
	this->_max_hit_point = 20;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor with name called" << std::endl;
	this->_name = name;
	this->_hit_point = 10;
	this->_energy_point = 10;
	this->_attack_damage = 0;
	this->_max_hit_point = 20;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_name = copy._name;
	this->_hit_point = copy._hit_point;
	this->_energy_point = copy._energy_point;
	this->_attack_damage = copy._attack_damage;
	this->_max_hit_point = copy._max_hit_point;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& copy)
{
	std::cout << "Operator '=' called" << std::endl;
	this->_name = copy._name;
	this->_hit_point = copy._hit_point;
	this->_energy_point = copy._energy_point;
	this->_attack_damage = copy._attack_damage;
	return(*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energy_point > 0 && this->_hit_point > 0)
	{
		std::cout << "ClapTrap ";
		std::cout << this->_name;
		std::cout << " attacks ";
		std::cout << target;
		std::cout << " and causing ";
		std::cout << BLUE << this->_attack_damage << RESET;
		std::cout << " points of damage!" << std::endl;
		this->_energy_point -= 1;
	}
	else if (this->_hit_point <= 0)
	{
		std::cout << "ClapTrap " ;
		std::cout << this->_name;
		std::cout << " can't be attack because he's dead" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " ;
		std::cout << this->_name;
		std::cout << " can't be attack because he doesn't have enough energy points" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_point > 0)
	{
		std::cout << "ClapTrap ";
		std::cout << this->_name;
		std::cout << " suffers an attack and loses ";
		std::cout << BLUE << amount << RESET;
		std::cout << " life points" << std::endl;
		this->_hit_point -= amount;
		if (this->_hit_point < 0)
			this->_hit_point = 0;
	}
	else
	{
		std::cout << "ClapTrap ";
		std::cout << this->_name;
		std::cout << " is attacked but takes no damage because he is already dead" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_point > 0 && this->_energy_point > 0 && this->_hit_point < this->_max_hit_point)
	{
		std::cout << "ClapTrap ";
		std::cout << this->_name;
		if (this->_hit_point + amount > this->_max_hit_point)
		{
			std::cout << " try to repair " ;
			std::cout << BLUE << amount << RESET;
			std::cout << " hp by using one of his energy points... But only regain ";
			std::cout << this->_max_hit_point - this->_hit_point;
			std::cout << " because he can't has more than ";
			std::cout << this->_max_hit_point;
			std::cout << " hp.";
			this->_hit_point += amount;
			if (this->_hit_point > this->_max_hit_point)
				this->_hit_point = this->_max_hit_point;
		}
		else
		{
			std::cout << " repair ";
			std::cout << BLUE << amount << RESET;
			this->_hit_point += amount;
		}
		std::cout << "\nClapTrap ";
		std::cout << this->_name;
		std::cout << " successfully repaired and has now ";
		std::cout << BLUE << this->_hit_point << RESET;
		std::cout << " hp." << std::endl;
		this->_energy_point -= 1;
	}
	else if (this->_hit_point <= 0)
		std::cout << "Clap trap " << this->_name << " would like to repair but he is dead." << std::endl;
	else if (this->_energy_point <= 0)
		std::cout << "Clap trap " << this->_name << " would like to repair but he doesn't have enough energy points." << std::endl;
	else if (this->_hit_point == this->_max_hit_point)
		std::cout << "Clap trap " << this->_name << " would like to repair but his life is already at its maximum." << std::endl;
}

void	ClapTrap::setEnergyPoint(int amount)
{
	if (amount < 0)
	{
		std::cout << "Can't set energy point on [" << amount << "] because it need to be not negative number" << std::endl;
	}
	else
		this->_energy_point = amount;
}

void	ClapTrap::setAttackDmg(int amount)
{
	if (amount < 0)
	{
		std::cout << "Can't set Attack damage on [" << amount << "] because it need to be not negative number" << std::endl;
	}
	else
		this->_attack_damage = amount;
}

void	ClapTrap::setHitPoint(int amount)
{
	if (amount < 0)
	{
		std::cout << "Can't set hp on [" << amount << "] because it need to be not negative number" << std::endl;
	}
	else
		this->_hit_point = amount;

}

void	ClapTrap::setName(std::string name)
{
	if (name.empty())
	{
		std::cout << "Can't give an empty name to a ClapTrap" << std::endl;
	}
	else
		this->_name = name;
}

int		ClapTrap::getEnergyPoint() const
{
	return(this->_energy_point);
}

int		ClapTrap::getAttackDmg() const
{
	return(this->_attack_damage);
}

int		ClapTrap::getHitPoint() const
{
	return(this->_hit_point);
}

std::string ClapTrap::getName() const
{
	return(this->_name);
}

void	ClapTrap::showInfo() const
{
	std::cout << "ClapTrap ";
	std::cout << BLUE <<  this->_name << RESET;
	std::cout << ":" << std::endl;
	std::cout << "Hp: ";
	std::cout << BLUE << this->_hit_point << RESET << std::endl;
	std::cout << "Attack damage: ";
	std::cout << BLUE <<  this->_attack_damage << RESET << std::endl;
	std::cout << "Energy point: ";
	std::cout << BLUE <<  this->_energy_point << RESET << std::endl;
}