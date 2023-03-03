/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:56:23 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/28 10:22:51 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "Fixed.hpp"
#include <iostream>
#include <string.h>
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define GREY    "\033[38;5;8m"

int main()
{
	int number[10];
	char character[10];
	char str[5] = "test";
	Fixed  fixed[5];
	int i;

	i = 0;
	while (i < 10)
	{
		number[i] = i;
		i++;
	}
	i = 0;
	while(i < 10)
	{
		character[i] = i + 'a';
		i++;
	}
	i = 0;
	while (i < 5)
	{
		fixed[i] = Fixed(i + 150);
		i++;
	}

	std::cout << GREY << "-----------------INT TEST---------------" << BLUE << std::endl;
	std::cout << "Before addOne: " << std::endl;
	iter(number, 10, print);
	iter(number, 10, addOne);
	std::cout << "After addOne: " << std::endl;
	iter(number, 10, print);
	iter(number, 10, doubleValue);
	std::cout << "After doubleValue: " << std::endl;
	iter(number, 10, print);

	std::cout << GREY << "\n-----------------CHAR TEST---------------" << GREEN << std::endl;
	std::cout << "Before addOne: " << std::endl;
	iter(character, 10, print);
	iter(character, 10, addOne);
	std::cout << "After addOne: " << std::endl;
	iter(character, 10, print);

	std::cout << GREY << "\n-----------------STR TEST---------------" << YELLOW << std::endl;
	std::cout << "Before addOne: " << std::endl;
	iter(str, 5, print);
	iter(str, 5, addOne);
	std::cout << "After addOne: " << std::endl;
	iter(str, 5, print);

	std::cout << GREY << "\n-----------------Class TEST---------------" << CYAN << std::endl;
	std::cout << "Print Class: " << std::endl;
	iter(fixed, 5, print);
	std::cout << "Multiply Class: " << std::endl;
	iter(fixed, 5, mutliplyClass);
	iter(fixed, 5, print);
}