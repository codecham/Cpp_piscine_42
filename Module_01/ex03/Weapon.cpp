/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:49:16 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/06 06:27:05 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
	_type = weapon;	
}

const std::string& Weapon::getType()
{
	const std::string& ref_type = _type; 
	return (ref_type);
}

void	Weapon::setType(std::string new_type)
{
	_type = new_type;
}