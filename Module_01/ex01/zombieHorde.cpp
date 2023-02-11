/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:16:46 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/05 20:14:46 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* hordeZombie;
	int i;

	i = 0;
	if (N <= 0)
		return (NULL);
	hordeZombie = new Zombie[N];
	while (i < N)
	{
		// hordeZombie[i] = new Zombie(name);
		hordeZombie[i].set_name(name);
		// hordeZombie[i].announce();
		i++;
	}
	return (hordeZombie);
}