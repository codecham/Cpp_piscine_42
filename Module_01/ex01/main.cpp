/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:16:18 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/05 20:16:11 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *horde;
	int n;
	int i;
	std::string name;

	n = 10;
	i = 0;
	name = "Allan";
	horde = NULL;
	std::cout << "\033[1;32m" << "Creating a horde of " << n << " Zobmies named " << name << "...\033[0m\n" << std::endl;
	horde = zombieHorde(n, "Allan");
	if (horde == NULL)
	{
		std::cout << "Horde can't be create because the number of Zombie needs to be a positive number" << std::endl;
		return (0);
	}
	std::cout << "\033[1;32m" << "Zombies annouced from main:" << "\033[0m\n" << std::endl;
	while (i < n)
	{
		std::cout << "\033[1;33m" << "Zombie " << i + 1 << ": \033[0m" ;
		horde[i].announce();
		i++;
	}
	std::cout << "\n\033[1;31m" << "Delete horde... " << "\033[0m" << std::endl;
	delete [] horde;
	horde = NULL;
	std::cout << "\033[1;31m" << "Delete successful " << "\033[0m" << std::endl;
}