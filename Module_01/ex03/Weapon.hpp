/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:48:14 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/06 06:27:13 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>
#include <string>

class Weapon
{
	public:
		Weapon(std::string weapon);
		void setType(std::string new_type);
		const std::string& getType();

	private:
		std::string _type;
};

#endif