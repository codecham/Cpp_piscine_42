/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:11:14 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/14 21:01:39 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include 		"Bureaucrat.hpp"
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
	Bureaucrat allan("Allan", 20);

	std::cout << allan << std::endl;
	std::cout << GREY << "\n--* Try to increment Allan *--" << RESET << std::endl;
	allan.increment();
	std::cout << allan << std::endl;
	std::cout << GREY << "\n--* Try to decrement 2 times Allan *--" << RESET << std::endl;
	allan.decrement();
	allan.decrement();
	std::cout << allan << std::endl;
	std::cout << "------------------------------------------------\n\n" << std::endl;

	Bureaucrat john;
	std::cout << john << std::endl;
	std::cout << GREY << "\n--* Try to decrement John *--" << RESET << std::endl;
	john.decrement();
	std::cout << john << std::endl;
	std::cout << "------------------------------------------------\n\n" << std::endl;

	Bureaucrat boss("Boss", 1);
	std::cout << boss << std::endl;
	std::cout << GREY << "\n--* Try to increment John *--" << RESET << std::endl;
	boss.increment();
	std::cout << boss << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
}