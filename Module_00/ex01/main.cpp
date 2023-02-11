/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:08:18 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/04 19:42:05 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	std::string choice;
	bool		check;
	PhoneBook	my_phonebook;

	check = true;
	std::cout << "Welcome in your Awesome PhoneBook!" << std::endl;
	my_phonebook.fill_phone_book();
	while (check)
	{
		std::cout << "---------------------------------" << std::endl;
		std::cout << "Make your choice:" << std::endl;
		std::cout << "\nADD" << std::endl;
		std::cout << "SEARCH" << std::endl;
		std::cout << "EXIT\n" << std::endl;
		std::cin >> choice;
		if (choice == "ADD")
			my_phonebook.add();
		else if (choice == "SEARCH")
			my_phonebook.search();
		else if (choice == "EXIT")
			check = false;
		else
			std::cout << "Incorrect choice! Try again" << std::endl;
	}
	return (0);
}