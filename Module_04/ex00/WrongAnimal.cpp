/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:46:50 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/13 00:03:52 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define GREY    "\033[38;5;8m"

WrongAnimal::WrongAnimal()
{
	std::cout << RED << "Constructor of WrongAnimal called" << RESET << std::endl;
	_type = "Unknow";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	std::cout << RED << "Constructor by copy of WrongAnimal called" << RESET << std::endl;
	_type = copy._type;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED << "Destructor of WrongAnimal called" << RESET << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& copy)
{
	std::cout << RED << "Operator = of WrongAnimal called" << RESET << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

void		WrongAnimal::setType(std::string type)
{
	_type = type;
}

std::string	WrongAnimal::getType() const
{
	return(_type);
}

void		WrongAnimal::makeSound() const
{
	std::cout << RED << "*Weird noise from an unknown wrong animal*" << RESET << std::endl;
}

