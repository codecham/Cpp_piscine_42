/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:22:45 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/05 19:29:21 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << "\033[1;31m" << this->_name << "Destructor Called\033[0m" << std::endl;
}

void 	Zombie::set_name(std::string name)
{
	this->_name = name;
}

void	Zombie::announce()
{
	std::cout << _name << ": " << " BraiiiiiiinnnzzzZ..." << std::endl;
}