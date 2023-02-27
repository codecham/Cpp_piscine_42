/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:24:47 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/25 18:43:46 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define GREY    "\033[38;5;8m"

struct Data
{
	int c;
	std::string n;
};

uintptr_t	serialize(Data*	ptr)
{
	uintptr_t	value;

	value = reinterpret_cast<uintptr_t>(ptr);
	return (value);
}

Data*	deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main()
{
	Data Test;
	Data Result;

	std::cout << GREY << "-----------Init Data Test--------------" << RESET << std::endl;
	Test.c = 10;
	Test.n = "Test of serialize";

	std::cout << "Test: " << std::endl;
	std::cout << "Adress:\t\t" << BLUE << &Test << RESET << std::endl;
	std::cout << "Test.c:\t\t" << CYAN << Test.c << RESET << std::endl;
	std::cout << "Test.n\t\t" << YELLOW <<Test.n << RESET << std::endl;


	std::cout << "\nResult: " << std::endl;
	std::cout << "Adress:\t\t" << BLUE << &Result << RESET << std::endl;
	std::cout << "Result.c:\t" << CYAN << Result.c << RESET << std::endl;
	std::cout << "Result.n:\t" << YELLOW << Result.n << RESET <<std::endl;

	std::cout << GREY << "\n-----------Serialize Data Test--------------" << RESET << std::endl;
	uintptr_t raw = serialize(&Test);
	std::cout << "Raw: \t\t" << BLUE << raw << RESET << std::endl;

	std::cout << GREY << "\n-----------Deserialize Data Test In result --------------" << std::endl;
	Result = *deserialize(raw);
	std::cout << "Test: " << std::endl;
	std::cout << "Adress:\t\t" << BLUE << &Test << RESET << std::endl;
	std::cout << "Test.c:\t\t" << CYAN << Test.c << RESET << std::endl;
	std::cout << "Test.n\t\t" << YELLOW <<Test.n << RESET << std::endl;


	std::cout << "\nResult: " << std::endl;
	std::cout << "Adress:\t\t" << BLUE << &Result << RESET << std::endl;
	std::cout << "Result.c:\t" << CYAN << Result.c << RESET << std::endl;
	std::cout << "Result.n:\t" << YELLOW << Result.n << RESET <<std::endl;

}