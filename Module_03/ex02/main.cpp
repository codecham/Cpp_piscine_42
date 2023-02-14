/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 02:05:40 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/12 22:10:14 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#define RESET 	"\033[0m"
#define GREEN 	"\033[38;5;46m"
#define WHITE 	"\033[38;5;15m"
#define GREY 	"\033[38;5;8m"
#define BLUE	"\033[1;34m"
#define ORANGE 	"\033[38;5;202m"
#define RED 	"\033[38;5;160m"


int main()
{
	FragTrap Alexandre("Alexandre");

	std::cout << GREY << "\n----------------------------------------------------" << RESET << std::endl;
	std::cout << GREY << "Info of ScavTrap Alexandre" << RESET << std::endl;
	Alexandre.showInfo();
	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << GREY << "\n----------------------------------------------------" << RESET << std::endl;
	std::cout << GREY << "ScavTrap Alexandre attack Benjamin" << RESET << std::endl;
	Alexandre.attack("Benjamin");
	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << GREY << "\n----------------------------------------------------" << RESET << std::endl;
	std::cout << GREY << "Alexandre try to ask HighFive" << RESET << std::endl;
	Alexandre.highFivesGuy();
	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


}