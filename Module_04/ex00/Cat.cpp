/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:35:51 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/13 00:03:33 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define GREY    "\033[38;5;8m"

Cat::Cat()
{
	std::cout << BLUE << "Constructor of Cat called" << RESET << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& copy)
{
	std::cout << BLUE << "Constructor by copy of Cat called" << RESET << std::endl;
	_type = copy._type;
}

Cat::~Cat(void)
{
	std::cout << BLUE << "Destructor of Cat called" << RESET << std::endl;
}

Cat&	Cat::operator=(const Cat& copy)
{
	std::cout << BLUE << "Operator = of Cat called" << RESET << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << BLUE << "Miaaaaaou..." << RESET << std::endl;
}

