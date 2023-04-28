/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:56:47 by dcorenti          #+#    #+#             */
/*   Updated: 2023/04/29 01:03:10 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#define TOTAL_FORMS 3

Intern::Intern()
{

}

Intern::Intern(const Intern& copy)
{
	*this = copy;
}

Intern::~Intern(void)
{

}

Intern&	Intern::operator=(const Intern& copy)
{
	(void)copy;
	return(*this);
}

AForm	*Intern::makeForm(std::string form_name, std::string target)
{
	std::string namesArray[TOTAL_FORMS] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm	*(Intern::*createForm[TOTAL_FORMS])(std::string target) = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPardon};
	int i = 0;

	while (i < TOTAL_FORMS)
	{
		if (form_name == namesArray[i])
		{
			std::cout << "Intern creates " << form_name << std::endl;
			return ((this->*createForm[i])(target));
		}
		i++;
	}
	std::cout << form_name << " is not a valid form" << std::endl;
	return(NULL);
}

AForm 	*Intern::createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm 	*Intern::createPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm 	*Intern::createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}
