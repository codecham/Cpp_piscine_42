/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:50:55 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/14 21:50:55 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#define RESET 	"\033[0m"
#define GREEN 	"\033[38;5;46m"
#define WHITE 	"\033[38;5;15m"
#define GREY 	"\033[38;5;8m"
#define BLUE	"\033[1;34m"
#define ORANGE 	"\033[38;5;202m"
#define RED 	"\033[38;5;160m"

FragTrap::FragTrap()
{
	std::cout << "Default constructor of " << ORANGE << "FragTrap" << RESET << " called" << std::endl;
	this->_name = "Unknow";
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
	this->_max_hit_point = 20;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "Constructor of " << ORANGE << "FragTrap" << RESET << " with name called" << std::endl;
	this->_name = name;
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
	this->_max_hit_point = 120;
}

FragTrap::FragTrap(const FragTrap& copy)
{
	std::cout << "Copy constructor of " << ORANGE << "FragTrap" << RESET << " called" << std::endl;
	this->_name = copy._name;
	this->_hit_point = copy._hit_point;
	this->_energy_point = copy._energy_point;
	this->_attack_damage = copy._attack_damage;
	this->_max_hit_point = copy._max_hit_point;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor of " << ORANGE << "FragTrap" << RESET << " called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& copy)
{
	std::cout << "Operator of " << ORANGE << "FragTrap" << RESET << " '=' called" << std::endl;
	this->_name = copy._name;
	this->_hit_point = copy._hit_point;
	this->_energy_point = copy._energy_point;
	this->_attack_damage = copy._attack_damage;
	this->_max_hit_point = copy._max_hit_point;
	return(*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_energy_point > 0 && this->_hit_point > 0)
	{
		std::cout << "FragTrap ";
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
		std::cout << "FragTrap " ;
		std::cout << this->_name;
		std::cout << " can't be attack because he's dead" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " ;
		std::cout << this->_name;
		std::cout << " can't be attack because he doesn't have enough energy points" << std::endl;
	}
}

void	FragTrap::highFivesGuy() const
{
	std::cout << "Hi guys, i'm ";
	std::cout << BLUE << this->_name << RESET;
	std::cout << " the FragTrap! Give me a high fives!" << std::endl;
}

void	FragTrap::showInfo() const
{
	std::cout << "FragTrap ";
	std::cout << BLUE <<  this->_name << RESET;
	std::cout << ":" << std::endl;
	std::cout << "Hp: ";
	std::cout << BLUE << this->_hit_point << RESET << std::endl;
	std::cout << "Attack damage: ";
	std::cout << BLUE <<  this->_attack_damage << RESET << std::endl;
	std::cout << "Energy point: ";
	std::cout << BLUE <<  this->_energy_point << RESET << std::endl;
}