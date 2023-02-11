/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:18:52 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/05 19:01:51 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>


class Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	announce();
		
	private:
		std::string _name;
};

Zombie*	newZombie(std::string name);
void    randomChump(std::string name);

#endif