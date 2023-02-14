/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:35:51 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/13 00:23:19 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define GREY    "\033[38;5;8m"

WrongCat::WrongCat()
{
	std::cout << YELLOW << "Constructor of WrongCat called" << RESET << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy)
{
	std::cout << YELLOW << "Constructor by copy of WrongCat called" << RESET << std::endl;
	_type = copy._type;
}

WrongCat::~WrongCat()
{
	std::cout << YELLOW << "Destructor of WrongCat called" << RESET << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& copy)
{
	std::cout << YELLOW << "Operator = of WrongCat called" << RESET << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << YELLOW << "Meeeeeeuh..." << RESET << std::endl;
}

