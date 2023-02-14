/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:51:12 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/14 21:51:12 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#define RESET 	"\033[0m"
#define GREEN 	"\033[38;5;46m"
#define WHITE 	"\033[38;5;15m"
#define GREY 	"\033[38;5;8m"
#define BLUE	"\033[1;34m"
#define ORANGE 	"\033[38;5;202m"
#define RED 	"\033[38;5;160m"

ScavTrap::ScavTrap()
{
	std::cout << "Default constructor of " << RED << "ScavTrap" << RESET << " called" << std::endl;
	this->_name = "Unknow";
	this->_hit_point = 10;
	this->_energy_point = 10;
	this->_attack_damage = 10;
	this->_max_hit_point = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "Constructor of " << RED << "ScavTrap" << RESET << " with name called" << std::endl;
	this->_name = name;
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
	this->_max_hit_point = 120;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
{
	std::cout << "Copy constructor of " << RED << "ScavTrap" << RESET << " called" << std::endl;
	this->_name = copy._name;
	this->_hit_point = copy._hit_point;
	this->_energy_point = copy._energy_point;
	this->_attack_damage = copy._attack_damage;
	this->_max_hit_point = copy._max_hit_point;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor of " << RED << "ScavTrap" << RESET << " called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& copy)
{
	std::cout << "Operator of " << GREEN << "ScavTrap" << RESET << " '=' called" << std::endl;
	this->_name = copy._name;
	this->_hit_point = copy._hit_point;
	this->_energy_point = copy._energy_point;
	this->_attack_damage = copy._attack_damage;
	this->_max_hit_point = copy._max_hit_point;
	return(*this);
}

void	ScavTrap::guardGate()
{
	std::cout << "ScaveTrap ";
	std::cout << BLUE << _name << RESET;
	std::cout << " enter in mode Gate keeper" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energy_point > 0 && this->_hit_point > 0)
	{
		std::cout << "ScavTrap ";
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
		std::cout << "ScavTrap " ;
		std::cout << this->_name;
		std::cout << " can't be attack because he's dead" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " ;
		std::cout << this->_name;
		std::cout << " can't be attack because he doesn't have enough energy points" << std::endl;
	}
}

void	ScavTrap::showInfo() const
{
	std::cout << "ScravTrap ";
	std::cout << BLUE <<  this->_name << RESET;
	std::cout << ":" << std::endl;
	std::cout << "Hp: ";
	std::cout << BLUE << this->_hit_point << RESET << std::endl;
	std::cout << "Attack damage: ";
	std::cout << BLUE <<  this->_attack_damage << RESET << std::endl;
	std::cout << "Energy point: ";
	std::cout << BLUE <<  this->_energy_point << RESET << std::endl;
}