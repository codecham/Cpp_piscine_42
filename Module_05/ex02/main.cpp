/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:42:39 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/19 08:33:29 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
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
	Bureaucrat boss("Boss", 1);
	Bureaucrat stagiaire("Stagiaire", 150);
	ShrubberyCreationForm jardin("jardin");
	RobotomyRequestForm frankenstien("Frankenstien");
	PresidentialPardonForm Manu("Manu");

	std::cout << GREY << "\n1) Form Error not signed" << RESET << std::endl;
	std::cout << GREY << "------------------------------------------------" << RESET << std::endl;
	boss.executeForm(jardin);
	boss.executeForm(frankenstien);
	boss.executeForm(Manu);

	std::cout << GREY << "\n2) Form Error grade" << RESET << std::endl;
	std::cout << GREY << "------------------------------------------------" << RESET << std::endl;
	boss.sign_form(jardin);
	boss.sign_form(frankenstien);
	boss.sign_form(Manu);
	stagiaire.executeForm(jardin);
	stagiaire.executeForm(frankenstien);
	stagiaire.executeForm(Manu);

	std::cout << GREY << "\n3) Execute forms" << RESET << std::endl;
	std::cout << GREY << "------------------------------------------------" << RESET << std::endl;
	boss.executeForm(jardin);
	boss.executeForm(Manu);
	boss.executeForm(frankenstien);
}