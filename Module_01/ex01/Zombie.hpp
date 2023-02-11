/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:18:52 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/05 19:28:54 by dcorenti         ###   ########.fr       */
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
		void 	set_name(std::string name);
	private:
		std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif