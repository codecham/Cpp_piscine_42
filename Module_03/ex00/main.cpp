/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:53:39 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/14 21:55:22 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#define RESET 	"\033[0m"
#define GREEN 	"\033[38;5;46m"
#define WHITE 	"\033[38;5;15m"
#define GREY 	"\033[38;5;8m"
#define BLUE	"\033[1;34m"
#define ORANGE 	"\033[38;5;202m"
#define RED 	"\033[38;5;160m"

int main()
{
	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << GREY << "*Create a ClapTrap named Allan*" << RESET << std::endl;
	ClapTrap allan("Allan");
	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << GREY << "ClapTrap Allan info:" << RESET << std::endl;
	allan.showInfo();
	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << GREY << "ClapTrap Allan attack Benjamin:" << RESET << std::endl;
	allan.attack("Benjamin");
	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << GREY << "ClapTrap Allan suffers an attack of value 5:" << RESET << std::endl;
	allan.takeDamage(5);
	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << GREY << "ClapTrap Allan's life after attack: " << RESET;
	std::cout << BLUE << allan.getHitPoint() << RESET << std::endl;
	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << GREY << "ClapTrap Allan repairs 4:" << RESET << std::endl;
	allan.beRepaired(4);
	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << GREY << "Energy point of Allan after these actions: " << BLUE << allan.getEnergyPoint() << RESET << std::endl;
	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout <<  GREY << "Set the energy point of Allan to 0" << RESET << std::endl;
	allan.setEnergyPoint(0);
	allan.showInfo();
	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << GREY << "Allan try to attack Benjamin again" << RESET << std::endl;
	allan.attack("Benjamin");
	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << GREY << "Allan try to repairs" << RESET << std::endl;
	allan.beRepaired(4);
	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout <<  GREY << "Set the energy point of Allan to 10 and his life to 0" << RESET << std::endl;
	allan.setEnergyPoint(10);
	allan.setHitPoint(0);
	allan.showInfo();
	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << GREY << "Allan try to attack Benjamin again" << RESET << std::endl;
	allan.attack("Benjamin");
	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << GREY << "Allan try to repairs" << RESET << std::endl;
	allan.beRepaired(4);
	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << GREY << "----------------------------------------------------" << RESET << std::endl;
	std::cout << GREY << "Allan is destroyed:" << RESET << std::endl;
}