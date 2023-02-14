/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 02:05:40 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/12 21:38:56 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#define RESET 	"\033[0m"
#define GREEN 	"\033[38;5;46m"
#define WHITE 	"\033[38;5;15m"
#define GREY 	"\033[38;5;8m"
#define BLUE	"\033[1;34m"
#define ORANGE 	"\033[38;5;202m"
#define RED 	"\033[38;5;160m"


int main()
{
	ScavTrap clement("Clement");

	std::cout << GREY << "\n----------------------------------------------------" << RESET << std::endl;
	std::cout << GREY << "Info of ScavTrap Clement" << RESET << std::endl;
	clement.showInfo();
	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << GREY << "\n----------------------------------------------------" << RESET << std::endl;
	std::cout << GREY << "ScavTrap Clement attack Benjamin" << RESET << std::endl;
	clement.attack("Benjamin");
	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << GREY << "\n----------------------------------------------------" << RESET << std::endl;
	std::cout << GREY << "Clement try to change mode on Gate Keeper" << RESET << std::endl;
	clement.guardGate();
	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


}