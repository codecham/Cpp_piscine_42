/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:54:04 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/06 18:10:45 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
}

void	HumanB::attack()
{
	std::cout << _name << "attacks with their" << _weapon->getType() << std::endl; 
}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}