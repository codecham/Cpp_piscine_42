/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:59:01 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/13 04:52:07 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define GREY    "\033[38;5;8m"

Animal::Animal()
{
	std::cout << GREY << "Constructor of Animal called" << RESET << std::endl;
	_type = "Unknow";
}

Animal::Animal(const Animal& copy)
{
	std::cout << GREY << "Constructor by copy of Animal called" << RESET << std::endl;
	_type = copy._type;
}

Animal::~Animal(void)
{
	std::cout << GREY << "Destructor of Animal called" << RESET << std::endl;
}

Animal&	Animal::operator=(const Animal& copy)
{
	std::cout << GREY << "Operator = of Animal called" << RESET << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

void		Animal::setType(std::string type)
{
	_type = type;
}

std::string	Animal::getType() const
{
	return(_type);
}

void		Animal::makeSound() const
{
	std::cout << GREY << "*Weird noise from an unknown animal*" << RESET << std::endl;
}

