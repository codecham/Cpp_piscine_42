/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:18:39 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/05 19:13:31 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *my_zombie;

	std::cout << "\033[1;32mCreating Allan from newZombie:\033[0m" << std::endl;
	my_zombie = newZombie("Allan");
	my_zombie->announce();
	std::cout << "\033[1;32mCreating Elodie from randomChump:\033[0m" << std::endl;
	randomChump("Elodie");
	delete my_zombie;
}