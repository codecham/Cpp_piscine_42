/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:52:31 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/28 16:48:00 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

int main()
{
	int i = 0;
	int nb_animals = 10;
	Animal* tab[nb_animals];

	std::cout << "Fill the first half of array with dogs:" << std::endl;
	while(i < nb_animals / 2)
	{
		tab[i] = new Dog;
		i++;
	}
	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Fill the second half of array with cats:" << std::endl;
	while (i < nb_animals)
	{
		tab[i] = new Cat;
		i++;
	}
	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Delete the arraw:" << std::endl;
	i = 0;
	while (i < nb_animals)
	{
		delete tab[i];
		i++;
	}
	/*------------------------Testing deep copy and leaks----------------------------*/
	// std::cout << "----------------------------------------------" << std::endl;

	// Dog dog_1;
	// Dog dog_2;

	// dog_2 = dog_1;
	// system("leaks Zoo");
}