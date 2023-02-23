/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:35:46 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/23 02:08:46 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define GREY    "\033[38;5;8m"

Dog::Dog()
{
	std::cout << GREEN << "Constructor of Dog called" << RESET << std::endl;
	_type = "Dog";
	_brain = new Brain;
}

Dog::Dog(const Dog& copy)
{
	std::cout << GREEN << "Constructor by copy of Dog called" << RESET << std::endl;
	this->_type = copy._type;
	_brain = new Brain(*copy._brain);
}

Dog::~Dog(void)
{
	std::cout << GREEN << "Destructor of Dog called" << RESET << std::endl;
	delete _brain;
}

Dog&	Dog::operator=(const Dog& copy)
{
	std::cout << GREEN << "Operator = of Dog called" << RESET << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
		this->_brain = new Brain(*copy._brain);
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << GREEN <<"Wouuuuuaf..." << RESET << std::endl;
}

std::string 	Dog::getIdea(int index) const
{
	return(_brain->getIdea(index));
}

void 	Dog::setIdea(std::string idea) 
{
	_brain->setIdea(idea);
}

