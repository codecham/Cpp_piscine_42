/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:52:31 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/13 00:23:03 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <string>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();

	std::cout << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "-------------GOOD ANIMALS------------" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << j->getType() << ": ";
	j->makeSound();
	std::cout << i->getType() << ": ";
	i->makeSound();
	std::cout << meta->getType() << ": ";
	meta->makeSound(); 
	std::cout << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "-------------WRONG ANIMALS-----------" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << wrong_cat->getType() << ": ";
	wrong_cat->makeSound();
	std::cout << wrong_meta->getType() << ": ";
	wrong_meta->makeSound();

	delete meta;
	delete j;
	delete i;
	delete wrong_meta;
	delete wrong_cat;
}